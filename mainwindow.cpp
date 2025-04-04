// MainWindow.cpp
#include "mainwindow.h"
#include "AddBookDialog.h"
#include "EditBookDialog.h"
#include "LoginWindow.h"
#include "ui_mainwindow.h"
#include "DeleteBookDialog.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QDate>

MainWindow::MainWindow(int userId, const QString &username, const QString &email, bool isAdmin, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
    currentUserId(userId), currentUsername(username), currentEmail(email), currentIsAdmin(isAdmin) {

    ui->setupUi(this);

    dbManager.openDatabase();
    loadBooks();

    // Hide menuBooks if the user is not an admin
    if (!currentIsAdmin) {
        ui->menuBooks->menuAction()->setVisible(false);
    }

    connect(ui->actionLog_out, &QAction::triggered, this, &MainWindow::onActionLogOutClicked);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::onActionExitClicked);
    connect(ui->actionRefresh, &QAction::triggered, this, &MainWindow::onActionRefreshClicked);
    connect(ui->borrowButton, &QPushButton::clicked, this, &MainWindow::onBorrowButtonClicked);
    connect(ui->booksTableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::onBookSelectionChanged);
    connect(ui->comboBoxSearchType, &QComboBox::currentTextChanged, this, &MainWindow::searchBooks);
    connect(ui->lineEditSearch, &QLineEdit::textChanged, this, &MainWindow::searchBooks);
    connect(ui->returnButton, &QPushButton::clicked, this, &MainWindow::onReturnButtonClicked);
    connect(ui->refreshButton, &QPushButton::clicked, this, &MainWindow::onActionRefreshClicked);
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);
    connect(ui->returnBorrowedButton, &QPushButton::clicked, this, &MainWindow::onReturnButtonClicked);
    connect(ui->refreshBorrowedButton, &QPushButton::clicked, this, &MainWindow::onActionRefreshClicked);
    connect(ui->comboBoxBorrowedSearchType, &QComboBox::currentTextChanged, this, &MainWindow::searchBorrowedBooks);
    connect(ui->lineEditBorrowedSearch, &QLineEdit::textChanged, this, &MainWindow::searchBorrowedBooks);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onTabChanged(int index) {
    if (index == 0) {
        // Books tab
        loadBooks();
    } else if (index == 1) {
        // Borrowed books tab
        loadBorrowedBooks();
    }
}

void MainWindow::loadBorrowedBooks() {
    // Get the borrowed books for the current user
    QSqlQuery query;
    query.prepare("SELECT b.book_id, b.title, b.author, b.genre, t.due_date "
                  "FROM books b "
                  "JOIN transactionrecord t ON b.book_id = t.book_id "
                  "WHERE t.email = (SELECT email FROM users WHERE user_id = :user_id) "
                  "AND t.amount = 1");
    query.bindValue(":user_id", currentUserId);
    query.exec();

    // Clear and setup the borrowed books table
    ui->borrowedBooksTableWidget->setRowCount(0);
    ui->borrowedBooksTableWidget->setColumnCount(5);
    ui->borrowedBooksTableWidget->setHorizontalHeaderLabels({"ID", "Title", "Author", "Genre", "Remaining Time"});
    ui->borrowedBooksTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int row = 0;
    while (query.next()) {
        ui->borrowedBooksTableWidget->insertRow(row);

        // Add book details
        for (int col = 0; col < 4; col++) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            ui->borrowedBooksTableWidget->setItem(row, col, item);
        }

        // Get due date string and parse it
        QString dueDateStr = query.value(4).toString();
        QDateTime dueDateTime = QDateTime::fromString(dueDateStr, "yyyy-MM-dd HH:mm:ss");
        if (!dueDateTime.isValid())
            dueDateTime = QDateTime::fromString(dueDateStr, "yyyy-MM-dd");

        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString remainingText;
        bool isOverdue = false;

        // Calculate remaining time in the same format as AdminPanel
        if (currentDateTime > dueDateTime) {
            isOverdue = true;
            int overdueSecs = dueDateTime.secsTo(currentDateTime);
            int overdueHours = overdueSecs / 3600;
            if (overdueHours < 24) {
                remainingText = QString::number(overdueHours) + " hours overdue";
            } else {
                int overdueDays = dueDateTime.daysTo(currentDateTime);
                remainingText = QString::number(overdueDays) + " days overdue";
            }
        } else {
            int secondsRemaining = currentDateTime.secsTo(dueDateTime);
            int hoursRemaining = secondsRemaining / 3600;
            if (hoursRemaining < 24) {
                remainingText = QString::number(hoursRemaining) + " hours";
            } else {
                int daysRemaining = currentDateTime.daysTo(dueDateTime);
                remainingText = QString::number(daysRemaining) + " days";
            }
        }

        QTableWidgetItem *timeItem = new QTableWidgetItem(remainingText);
        timeItem->setFlags(timeItem->flags() & ~Qt::ItemIsEditable);

        // Make overdue items red
        if (isOverdue) {
            timeItem->setForeground(Qt::red);
        }

        ui->borrowedBooksTableWidget->setItem(row, 4, timeItem);
        row++;
    }
}

void MainWindow::loadBooks() {
    QSqlQuery query("SELECT book_id, title, author, genre, publication_year, stock, status FROM books");

    ui->booksTableWidget->setRowCount(0);
    ui->booksTableWidget->setColumnCount(7);
    ui->booksTableWidget->setHorizontalHeaderLabels({"ID", "Title", "Author", "Genre","Publication Year","Stock", "Status"});
    ui->booksTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // Stretch columns

    int row = 0;
    while (query.next()) {
        ui->booksTableWidget->insertRow(row);
        for (int col = 0; col < 7; col++) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);  // Make the item non-editable
            ui->booksTableWidget->setItem(row, col, item);
        }
        row++;
    }
}

void MainWindow::searchBooks() {
    QString searchText = ui->lineEditSearch->text();
    QString searchColumn = ui->comboBoxSearchType->currentText();

    if (searchText.isEmpty()) {
        loadBooks(); // Refresh books list
        loadBorrowedBooks(); // Refresh borrowed books list
        return;
    }

    QSqlQuery query;

    // Check which tab is active
    int currentTab = ui->tabWidget->currentIndex();

    if (currentTab == 0) {
        // First tab (Browsing books)
        query.prepare("SELECT book_id, title, author, genre, publication_year, stock, status "
                      "FROM books WHERE " + searchColumn + " LIKE ?");
        query.addBindValue("%" + searchText + "%");

        ui->booksTableWidget->setRowCount(0);
        int row = 0;
        if (query.exec()) {
            while (query.next()) {
                ui->booksTableWidget->insertRow(row);
                for (int col = 0; col < 7; col++) {
                    QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                    ui->booksTableWidget->setItem(row, col, item);
                }
                row++;
            }
        } else {
            qDebug() << "Error executing search query for books:" << query.lastError().text();
        }

    } else if (currentTab == 1) {
        // Second tab (Borrowed books)
        query.prepare("SELECT t.book_id, b.title, b.author, b.genre, "
                      "julianday(t.due_date) - julianday('now') AS remaining_time "
                      "FROM transactionrecord t "
                      "JOIN books b ON t.book_id = b.book_id "
                      "WHERE t.email = :email AND (b.title LIKE ? OR b.author LIKE ?)");
        query.bindValue(":email", currentEmail);
        query.addBindValue("%" + searchText + "%");
        query.addBindValue("%" + searchText + "%");

        ui->borrowedBooksTableWidget->setRowCount(0);
        int row = 0;
        if (query.exec()) {
            while (query.next()) {
                ui->borrowedBooksTableWidget->insertRow(row);
                for (int col = 0; col < 5; col++) {
                    QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                    ui->borrowedBooksTableWidget->setItem(row, col, item);
                }
                row++;
            }
        } else {
            qDebug() << "Error executing search query for borrowed books:" << query.lastError().text();
        }
    }
}

void MainWindow::searchBorrowedBooks() {
    QString searchText = ui->lineEditBorrowedSearch->text().trimmed();
    QString searchColumn = ui->comboBoxBorrowedSearchType->currentText();

    if (searchText.isEmpty()) {
        loadBorrowedBooks(); // Reload the full list if search is cleared
        return;
    }

    QSqlQuery query;

    // Map searchColumn to valid database fields
    QString columnName;
    if (searchColumn == "Title") {
        columnName = "b.title";
    } else if (searchColumn == "Author") {
        columnName = "b.author";
    } else if (searchColumn == "Genre") {
        columnName = "b.genre";
    } else {
        qDebug() << "Invalid search column selected!";
        return;
    }

    QString queryString = QString(
                              "SELECT b.book_id, b.title, b.author, b.genre, t.due_date "
                              "FROM books b "
                              "JOIN transactionrecord t ON b.book_id = t.book_id "
                              "WHERE t.email = (SELECT email FROM users WHERE user_id = :user_id) "
                              "AND t.amount = 1 "
                              "AND %1 LIKE :searchText"
                              ).arg(columnName);

    query.prepare(queryString);
    query.bindValue(":user_id", currentUserId);
    query.bindValue(":searchText", "%" + searchText + "%");

    ui->borrowedBooksTableWidget->setRowCount(0);
    int row = 0;
    if (query.exec()) {
        while (query.next()) {
            ui->borrowedBooksTableWidget->insertRow(row);

            for (int col = 0; col < 4; col++) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                ui->borrowedBooksTableWidget->setItem(row, col, item);
            }

            // Calculate remaining time
            QString dueDateStr = query.value(4).toString();
            QDateTime dueDateTime = QDateTime::fromString(dueDateStr, "yyyy-MM-dd HH:mm:ss");
            if (!dueDateTime.isValid())
                dueDateTime = QDateTime::fromString(dueDateStr, "yyyy-MM-dd");

            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString remainingText;
            bool isOverdue = false;

            if (currentDateTime > dueDateTime) {
                isOverdue = true;
                int overdueDays = dueDateTime.daysTo(currentDateTime);
                remainingText = QString::number(overdueDays) + " days overdue";
            } else {
                int daysRemaining = currentDateTime.daysTo(dueDateTime);
                remainingText = QString::number(daysRemaining) + " days";
            }

            QTableWidgetItem *timeItem = new QTableWidgetItem(remainingText);
            timeItem->setFlags(timeItem->flags() & ~Qt::ItemIsEditable);
            if (isOverdue) {
                timeItem->setForeground(Qt::red);
            }
            ui->borrowedBooksTableWidget->setItem(row, 4, timeItem);
            row++;
        }
    } else {
        qDebug() << "Error executing search query for borrowed books:" << query.lastError().text();
    }
}


void MainWindow::onActionLogOutClicked() {
    // Show the login window
    LoginWindow *loginWindow = new LoginWindow();
    loginWindow->show();

    // Hide the main window so the user can log in again
    this->hide();

    // Optionally, you can connect the `destroyed` signal to close the main window when the login window is closed
    connect(loginWindow, &LoginWindow::destroyed, this, &MainWindow::close);
}

void MainWindow::onBorrowButtonClicked() {
    int row = ui->booksTableWidget->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Warning", "No book selected!");
        return;
    }

    int bookId = ui->booksTableWidget->item(row, 0)->text().toInt();
    QString bookTitle = ui->booksTableWidget->item(row, 1)->text();
    int currentStock = ui->booksTableWidget->item(row, 5)->text().toInt();

    if (currentUserId == 0) {
        QMessageBox::warning(this, "Warning", "User not logged in!");
        return;
    }

    if (currentStock <= 0) {
        QMessageBox::warning(this, "Warning", "This book is out of stock!");
        return;
    }

    // Confirmation dialog
    QMessageBox::StandardButton confirm;
    confirm = QMessageBox::question(this, "Confirm Borrow",
                                    "Do you want to borrow \"" + bookTitle + "\"?",
                                    QMessageBox::Yes|QMessageBox::No);

    if (confirm == QMessageBox::Yes) {
        QString errorMessage;
        if (dbManager.borrowBook(currentUserId, bookId, errorMessage)) {
            QMessageBox::information(this, "Success", "Book borrowed successfully!");
            loadBooks();
        } else {
            QMessageBox::critical(this, "Error", errorMessage);  // Show specific error
        }
    }
    dbManager.printBookDataADMIN();
    dbManager.printRecordTableDataADMIN();
}

void MainWindow::onBookSelectionChanged() {
    int row = ui->booksTableWidget->currentRow();
    if (row != -1) {
        QString selectedBook = ui->booksTableWidget->item(row, 1)->text();
        ui->SelectedLabel->setText(selectedBook);
    } else {
        ui->SelectedLabel->setText("");
    }
}
void MainWindow::onReturnButtonClicked() {
    // Get list of books borrowed by this user
    QSqlQuery query;
    query.prepare("SELECT b.book_id, b.title FROM books b "
                  "JOIN transactionrecord t ON b.book_id = t.book_id "
                  "JOIN users u ON t.email = u.email "
                  "WHERE u.user_id = :user_id AND t.amount = 1");
    query.bindValue(":user_id", currentUserId);
    query.exec();

    QMap<int, QString> borrowedBooks;
    while (query.next()) {
        int bookId = query.value(0).toInt();
        QString title = query.value(1).toString();
        borrowedBooks[bookId] = title;
    }

    if (borrowedBooks.isEmpty()) {
        QMessageBox::information(this, "Return Book", "You have no books to return.");
        return;
    }

    // Create a list of book titles for the dialog
    QStringList items;
    QList<int> bookIds;

    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        items << QString("ID: %1 - %2").arg(it.key()).arg(it.value());
        bookIds << it.key();
    }

    bool ok;
    QString selected = QInputDialog::getItem(this, "Return Book",
                                             "Select a book to return:",
                                             items, 0, false, &ok);

    if (!ok || selected.isEmpty()) {
        return; // User canceled
    }

    // Extract book ID from selection
    int selectedIndex = items.indexOf(selected);
    if (selectedIndex >= 0) {
        int bookId = bookIds.at(selectedIndex);

        if (dbManager.returnBook(currentUserId, bookId)) {
            QMessageBox::information(this, "Success", "Book returned successfully!");
            loadBooks();  // Refresh book list
        } else {
            QMessageBox::critical(this, "Error", "Failed to return book.");
        }
    }
    dbManager.printBookDataADMIN();
    dbManager.printRecordTableDataADMIN();
    loadBorrowedBooks();
}

void MainWindow::onActionExitClicked(){
    QApplication::quit();
}

void MainWindow::onActionRefreshClicked(){
    loadBooks();
    qDebug()<<"Book load!";
}
