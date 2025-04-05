#include "AdminPanel.h"
#include "ui_AdminPanel.h"
#include "addbookdialog.h"
#include "editbookdialog.h"
#include "deletebookdialog.h"
#include "LoginWindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QDate>

AdminPanel::AdminPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &AdminPanel::onTabChanged);
    ui->booksTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->borrowedBooksTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->actionLog_out, &QAction::triggered, this, &AdminPanel::onActionLogOutClicked);
    connect(ui->actionExit, &QAction::triggered, this, &AdminPanel::onActionExitClicked);
    connect(ui->actionRefresh, &QAction::triggered, this, &AdminPanel::onActionRefreshClicked);

    connect(ui->addBookButton, &QPushButton::clicked, this, &AdminPanel::onActionAddBookClicked);
    connect(ui->editBookButton, &QPushButton::clicked, this, &AdminPanel::onActionEditBookClicked);
    connect(ui->deleteBookButton, &QPushButton::clicked, this, &AdminPanel::onActionDeleteBookClicked);

    connect(ui->booksTableWidget, &QTableWidget::itemSelectionChanged, this, &AdminPanel::onBookSelectionChanged);
    connect(ui->comboBoxSearchType, &QComboBox::currentTextChanged, this, &AdminPanel::searchBooks);
    connect(ui->lineEditSearch, &QLineEdit::textChanged, this, &AdminPanel::searchBooks);
    loadBooks(); // Load books on startup
    loadBorrowedBooks();
    onTabChanged(2);
}

AdminPanel::~AdminPanel()
{
    delete ui;
}

void AdminPanel::onTabChanged(int)
{
    // Check if the current tab is the Borrowed Books tab (index 1)
    if (ui->tabWidget->currentIndex() == 1) {
        // Set the combo box to show only "All Fields" option for Borrowed Books tab
        ui->comboBoxSearchType->clear();  // Clear existing options
        ui->comboBoxSearchType->addItem("All Fields");  // Add only "All Fields" option

        // Make the combo box uneditable (disable editing)
        ui->comboBoxSearchType->setEditable(false);

        // Optionally, set the combo box to be unselectable (if you don't want any interaction)
        ui->comboBoxSearchType->setEnabled(false);

        loadBorrowedBooks();  // Load the borrowed books table
    }
    // Check if the current tab is the Books tab (index 0)
    else if (ui->tabWidget->currentIndex() == 0) {
        // Reset the combo box to its normal state (with the original options)
        ui->comboBoxSearchType->clear();
        ui->comboBoxSearchType->addItem("Title");
        ui->comboBoxSearchType->addItem("Author");
        ui->comboBoxSearchType->addItem("Genre");
        ui->comboBoxSearchType->addItem("All Fields");

        // Make the combo box editable again
        ui->comboBoxSearchType->setEditable(true);

        // Enable the combo box for interaction
        ui->comboBoxSearchType->setEnabled(true);

        loadBooks();  // Reload the books table
    }
    else if (ui->tabWidget->currentIndex() == 2) {
        int availableCount = 0;
        int borrowedCount = 0;
        int totalCount = 0;
        int overdueCount = 0;

        // Get available count (from books table)
        QSqlQuery availableQuery("SELECT SUM(stock) FROM books");
        if (availableQuery.next())
            availableCount = availableQuery.value(0).toInt();

        // Get borrowed count (from transaction table)
        QSqlQuery borrowedQuery("SELECT COUNT(*) FROM transactionrecord");
        if (borrowedQuery.next())
            borrowedCount = borrowedQuery.value(0).toInt();

        // Get total count (from books and transactionrecord amounts)
        QSqlQuery totalQuery("SELECT (SELECT SUM(stock) FROM books) + (SELECT SUM(amount) FROM transactionrecord)");
        if (totalQuery.next())
            totalCount = totalQuery.value(0).toInt();

        // Get overdue count
        QSqlQuery overdueQuery("SELECT COUNT(*) FROM transactionrecord WHERE due_date < DATETIME('now')");
        if (overdueQuery.next())
            overdueCount = overdueQuery.value(0).toInt();

        setupAnalysisChart(availableCount, borrowedCount, totalCount, overdueCount);
    }
}

void AdminPanel::loadBorrowedBooks()
{
    QSqlQuery query;
    query.prepare(R"(
        SELECT b.title, t.email, t.amount, t.due_date
        FROM transactionrecord t
        JOIN books b ON t.book_id = b.book_id
    )");

    if (!query.exec()) {
        qDebug() << "Failed to load borrowed books:" << query.lastError().text();
        return;
    }

    ui->borrowedBooksTableWidget->setRowCount(0);
    ui->borrowedBooksTableWidget->setColumnCount(4);
    ui->borrowedBooksTableWidget->setHorizontalHeaderLabels(
        {"Book Name", "Borrower", "Amount", "Remaining Time"}
        );
    ui->borrowedBooksTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int row = 0;
    while (query.next()) {
        QString title = query.value(0).toString();
        QString borrower = query.value(1).toString();
        int amount = query.value(2).toInt();
        QString dueDateStr = query.value(3).toString();
        QDateTime dueDateTime = QDateTime::fromString(dueDateStr, "yyyy-MM-dd HH:mm:ss");

        if (!dueDateTime.isValid())
            dueDateTime = QDateTime::fromString(dueDateStr, "yyyy-MM-dd");

        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString remainingText;
        bool isOverdue = false;

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

        ui->borrowedBooksTableWidget->insertRow(row);
        ui->borrowedBooksTableWidget->setItem(row, 0, new QTableWidgetItem(title));
        ui->borrowedBooksTableWidget->setItem(row, 1, new QTableWidgetItem(borrower));
        ui->borrowedBooksTableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(amount)));

        QTableWidgetItem *remainingItem = new QTableWidgetItem(remainingText);
        if (isOverdue) {
            remainingItem->setForeground(QBrush(Qt::red));  // Set text color to red
        }
        ui->borrowedBooksTableWidget->setItem(row, 3, remainingItem);

        row++;
    }
}

// Slot function for adding a book
void AdminPanel::onActionAddBookClicked() {
    AddBookDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        loadBooks();  // Refresh book table after adding
    }
}

// Slot function for editing a book
void AdminPanel::onActionEditBookClicked() {
    if (selectedBookId.isEmpty()) {
        QMessageBox::warning(this, "Warning", "No book selected!");
        return;
    }

    EditBookDialog dialog(selectedBookId, this);  // Pass the book ID
    if (dialog.exec() == QDialog::Accepted) {
        loadBooks();  // Refresh book table
    }
}

// Slot function for deleting a book
void AdminPanel::onActionDeleteBookClicked() {
    DeleteBookDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        loadBooks();  // Refresh book table after deleting
    }
}

// Function to refresh the book list
void AdminPanel::loadBooks() {
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

void AdminPanel::searchBooks() {
    QString searchText = ui->lineEditSearch->text();

    if (searchText.isEmpty()) {
        // Clear search and reload both tables
        loadBooks();
        loadBorrowedBooks();
        return;
    }

    // Search in the books table (with the selected column)
    if (ui->tabWidget->currentIndex() == 0) {  // If the current tab is the Books tab
        QString searchColumn = ui->comboBoxSearchType->currentText();
        QSqlQuery query;
        query.prepare("SELECT book_id, title, author, genre, publication_year, stock, status FROM books WHERE " + searchColumn + " LIKE ?");
        query.addBindValue("%" + searchText + "%");
        query.exec();

        ui->booksTableWidget->setRowCount(0);
        int row = 0;
        while (query.next()) {
            ui->booksTableWidget->insertRow(row);
            for (int col = 0; col < 7; col++) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                ui->booksTableWidget->setItem(row, col, item);
            }
            row++;
        }
    }

    // Search in the borrowed books table (searches only by book name and borrower)
    // Search in the borrowed books table
    else if (ui->tabWidget->currentIndex() == 1) {  // If the current tab is the Borrowed tab
        QSqlQuery query;
        query.prepare(R"(
        SELECT b.title, t.email, t.amount, t.due_date
        FROM transactionrecord t
        JOIN books b ON t.book_id = b.book_id
        WHERE b.title LIKE ? OR t.email LIKE ?
    )");
        query.addBindValue("%" + searchText + "%");
        query.addBindValue("%" + searchText + "%");

        if (!query.exec()) {
            qDebug() << "Failed to search borrowed books:" << query.lastError().text();
            return;
        }

        ui->borrowedBooksTableWidget->setRowCount(0);
        int row = 0;

        while (query.next()) {
            QString title = query.value(0).toString();
            QString borrower = query.value(1).toString();
            int amount = query.value(2).toInt();
            QString dueDateStr = query.value(3).toString();

            // Handle date format exactly as in loadBorrowedBooks
            QDateTime dueDateTime = QDateTime::fromString(dueDateStr, "yyyy-MM-dd HH:mm:ss");
            if (!dueDateTime.isValid())
                dueDateTime = QDateTime::fromString(dueDateStr, "yyyy-MM-dd");

            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString remainingText;
            bool isOverdue = false;

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

            ui->borrowedBooksTableWidget->insertRow(row);
            ui->borrowedBooksTableWidget->setItem(row, 0, new QTableWidgetItem(title));
            ui->borrowedBooksTableWidget->setItem(row, 1, new QTableWidgetItem(borrower));
            ui->borrowedBooksTableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(amount)));

            QTableWidgetItem *remainingItem = new QTableWidgetItem(remainingText);
            if (isOverdue) {
                remainingItem->setForeground(QBrush(Qt::red));  // Set text color to red
            }
            ui->borrowedBooksTableWidget->setItem(row, 3, remainingItem);

            row++;
        }
    }
}

void AdminPanel::onBookSelectionChanged() {
    int row = ui->booksTableWidget->currentRow();
    if (row != -1) {
        selectedBookId = ui->booksTableWidget->item(row, 0)->text();  // Store book ID
        QString selectedBookTitle = ui->booksTableWidget->item(row, 1)->text();
        ui->SelectedLabel->setText(selectedBookTitle);
    } else {
        selectedBookId.clear();  // Clear selection
        ui->SelectedLabel->setText("None");
    }
}

void AdminPanel::onActionExitClicked(){
    QApplication::quit();
}

void AdminPanel::onActionRefreshClicked(){
    loadBooks();
    qDebug()<<"Book load!";
}

void AdminPanel::onActionLogOutClicked() {
    // Show the login window
    LoginWindow *loginWindow = new LoginWindow();
    loginWindow->show();

    // Hide the main window so the user can log in again
    this->hide();

    // Optionally, you can connect the `destroyed` signal to close the main window when the login window is closed
    connect(loginWindow, &LoginWindow::destroyed, this, &AdminPanel::close);
}

void AdminPanel::setupAnalysisChart(int availableCount, int borrowedCount, int totalCount, int overdueCount)
{
    // Create pie chart series
    QPieSeries *series = new QPieSeries();
    series->append("Available", availableCount);
    series->append("Borrowed", borrowedCount);

    // Create chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Library Usage Analysis");
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Create chart view and make it bigger
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumHeight(230);  // Make chart taller

    // Clear existing layout if any
    QLayout *oldLayout = ui->tabAnalysis->layout();
    if (oldLayout) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                item->widget()->deleteLater();
            }
            delete item;
        }
        delete oldLayout;
    }

    // Create new layout for the chart
    QVBoxLayout *layout = new QVBoxLayout(ui->tabAnalysis);
    layout->addWidget(chartView);

    // Create labels
    QLabel *labelAvailable = new QLabel("Available Books: " + QString::number(availableCount));
    QLabel *labelBorrowed = new QLabel("Borrowed Books: " + QString::number(borrowedCount));
    QLabel *labelTotal = new QLabel("Total Books: " + QString::number(totalCount));
    QLabel *labelOverdue = new QLabel("Overdue Books: " + QString::number(overdueCount));

    // Smaller font for labels
    QFont font;
    font.setPointSize(3); // Set the font size for labels
    font.setBold(false);

    // Set font to all labels
    labelAvailable->setFont(font);
    labelBorrowed->setFont(font);
    labelTotal->setFont(font);
    labelOverdue->setFont(font);

    // Create a horizontal layout for Total and Available on one side
    QHBoxLayout *labelLayout1 = new QHBoxLayout();
    labelLayout1->addWidget(labelTotal);
    labelLayout1->addWidget(labelAvailable);

    // Create a horizontal layout for Borrowed and Overdue on the other side
    QHBoxLayout *labelLayout2 = new QHBoxLayout();
    labelLayout2->addWidget(labelBorrowed);
    labelLayout2->addWidget(labelOverdue);

    // Add label layouts to the main layout
    layout->addLayout(labelLayout1);
    layout->addLayout(labelLayout2);

    ui->tabAnalysis->setLayout(layout);
}
