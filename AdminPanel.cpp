#include "AdminPanel.h"
#include "ui_AdminPanel.h"
#include "addbookdialog.h"
#include "editbookdialog.h"
#include "deletebookdialog.h"

AdminPanel::AdminPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);

    // Connect the renamed buttons to their respective slots
    connect(ui->addBookButton, &QPushButton::clicked, this, &AdminPanel::onActionAddBookClicked);
    connect(ui->editBookButton, &QPushButton::clicked, this, &AdminPanel::onActionEditBookClicked);
    connect(ui->deleteBookButton, &QPushButton::clicked, this, &AdminPanel::onActionDeleteBookClicked);

    connect(ui->booksTableWidget, &QTableWidget::itemSelectionChanged, this, &AdminPanel::onBookSelectionChanged);
    connect(ui->comboBoxSearchType, &QComboBox::currentTextChanged, this, &AdminPanel::searchBooks);
    connect(ui->lineEditSearch, &QLineEdit::textChanged, this, &AdminPanel::searchBooks);
    loadBooks(); // Load books on startup
}

AdminPanel::~AdminPanel()
{
    delete ui;
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
    QString searchColumn = ui->comboBoxSearchType->currentText();

    if (searchText.isEmpty()) {
        loadBooks();
        return;
    }

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
    if (row == 0) {
        ui->ResultLabel->setText("Status: Not found!");
    } else {
        ui->ResultLabel->clear();
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
