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

bool AddBookDialog::isIdUnique(const QString &bookId) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM books WHERE book_id = :book_id");
    query.bindValue(":book_id", bookId);
    if (query.exec() && query.next()) {
        return query.value(0).toInt() == 0;
    }
    return false;
}

void AddBookDialog::onAddButtonClicked() {
    QString id = ui->idInput->text().trimmed(); // Keep ID as QString
    QString title = ui->titleInput->text().trimmed();
    QString author = ui->authorInput->text().trimmed();
    QString genre = ui->genreInput->text().trimmed();
    QString yearStr = ui->yearInput->text().trimmed();
    QString stockStr = ui->stockInput->text().trimmed();

    // Check for empty fields
    if (id.isEmpty() || title.isEmpty() || author.isEmpty() || genre.isEmpty() ||
        yearStr.isEmpty() || stockStr.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all fields.");
        return;
    }

    // Validate that yearStr is a valid integer greater than 0
    bool yearOk;
    int year = yearStr.toInt(&yearOk);
    if (!yearOk || year <= 0) {
        QMessageBox::warning(this, "Error", "Publication year must be a valid positive integer.");
        return;
    }

    // Validate that stockStr is a valid integer greater than 0
    bool stockOk;
    int stock = stockStr.toInt(&stockOk);
    if (!stockOk || stock <= 0) {
        QMessageBox::warning(this, "Error", "Stock must be greater than 0.");
        return;
    }

    // Ensure book ID is unique
    if (!isIdUnique(id)) {  // Pass the ID as a string
        QMessageBox::warning(this, "Error", "Book ID already exists!");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO books (book_id, title, author, genre, publication_year, status, stock) "
                  "VALUES (:id, :title, :author, :genre, :year, :status, :stock)");

    query.bindValue(":id", id); // Store ID as a string
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


