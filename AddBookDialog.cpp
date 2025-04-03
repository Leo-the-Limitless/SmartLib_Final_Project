#include "AddBookDialog.h"
#include "ui_AddBookDialog.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

AddBookDialog::AddBookDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AddBookDialog) {
    ui->setupUi(this);
    connect(ui->ConfirmButton, &QPushButton::clicked, this, &::AddBookDialog::onAddButtonClicked);
}

AddBookDialog::~AddBookDialog() {
    delete ui;
}

// Ensure book ID is unique
bool AddBookDialog::isIdUnique(int bookId) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM books WHERE book_id = :book_id");
    query.bindValue(":book_id", bookId);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() == 0;
    }
    return false;
}

void AddBookDialog::onAddButtonClicked() {
    QString idStr = ui->idInput->text().trimmed();
    QString title = ui->titleInput->text().trimmed();
    QString author = ui->authorInput->text().trimmed();
    QString genre = ui->genreInput->text().trimmed();
    QString yearStr = ui->yearInput->text().trimmed();
    QString stockStr = ui->stockInput->text().trimmed();

    // Validate book ID as a positive integer
    bool idOk;
    int bookId = idStr.toInt(&idOk);
    if (!idOk || bookId <= 0) {
        QMessageBox::warning(this, "Error", "Book ID must be a positive integer.");
        return;
    }

    // Check for empty fields
    if (title.isEmpty() || author.isEmpty() || genre.isEmpty() ||
        yearStr.isEmpty() || stockStr.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all fields.");
        return;
    }

    // Validate publication year
    bool yearOk;
    int year = yearStr.toInt(&yearOk);
    if (!yearOk || year <= 0) {
        QMessageBox::warning(this, "Error", "Publication year must be a valid positive integer.");
        return;
    }

    // Validate stock quantity
    bool stockOk;
    int stock = stockStr.toInt(&stockOk);
    if (!stockOk || stock <= 0) {
        QMessageBox::warning(this, "Error", "Stock must be greater than 0.");
        return;
    }

    // Ensure book ID is unique
    if (!isIdUnique(bookId)) {
        QMessageBox::warning(this, "Error", "Book ID already exists!");
        return;
    }

    // Insert new book into the database
    QSqlQuery query;
    query.prepare("INSERT INTO books (book_id, title, author, genre, publication_year, status, stock) "
                  "VALUES (:id, :title, :author, :genre, :year, :status, :stock)");

    query.bindValue(":id", bookId);
    query.bindValue(":title", title);
    query.bindValue(":author", author);
    query.bindValue(":genre", genre);
    query.bindValue(":year", year);
    query.bindValue(":status", "Available");
    query.bindValue(":stock", stock);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Book added successfully!");
        accept();
    } else {
        QMessageBox::warning(this, "Error", "Failed to add book: " + query.lastError().text());
    }
}
