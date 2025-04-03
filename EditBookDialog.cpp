#include "EditBookDialog.h"
#include "ui_EditBookDialog.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

EditBookDialog::EditBookDialog(const QString &bookId, QWidget *parent)
    : QDialog(parent), ui(new Ui::EditBookDialog), currentBookId(bookId) {
    ui->setupUi(this);

    connect(ui->SaveButton, &QPushButton::clicked, this, &EditBookDialog::onSaveButtonClicked);

    // Fetch and display book details when opening
    QSqlQuery query;
    query.prepare("SELECT title, author, genre, publication_year, stock FROM books WHERE book_id = :book_id");
    query.bindValue(":book_id", currentBookId);

    if (query.exec() && query.next()) {
        ui->titleInput->setText(query.value(0).toString());
        ui->authorInput->setText(query.value(1).toString());
        ui->genreInput->setText(query.value(2).toString());
        ui->yearInput->setText(query.value(3).toString());
        ui->stockInput->setText(query.value(4).toString());
    } else {
        QMessageBox::warning(this, "Error", "Book ID not found!");
    }
}

EditBookDialog::~EditBookDialog() {
    delete ui;
}

// void EditBookDialog::onIdInputChanged(const QString &text) {
//     // If the ID is empty, don't do anything
//     if (text.isEmpty()) {
//         return;
//     }

//     currentBookId = text;  // Store as QString since book_id is TEXT now

//     QSqlQuery query;
//     query.prepare("SELECT title, author, genre, publication_year, stock FROM books WHERE book_id = :book_id");
//     query.bindValue(":book_id", currentBookId);

//     if (query.exec() && query.next()) {
//         ui->titleInput->setText(query.value(0).toString());
//         ui->authorInput->setText(query.value(1).toString());
//         ui->genreInput->setText(query.value(2).toString());
//         ui->yearInput->setText(query.value(3).toString());
//         ui->stockInput->setText(query.value(4).toString());
//     } else {
//         QMessageBox::warning(this, "Error", "Book ID not found!");
//     }
// }

void EditBookDialog::onSaveButtonClicked() {
    QString title = ui->titleInput->text().trimmed();
    QString author = ui->authorInput->text().trimmed();
    QString genre = ui->genreInput->text().trimmed();
    QString yearStr = ui->yearInput->text().trimmed();
    QString stockStr = ui->stockInput->text().trimmed();

    // Ensure all fields are filled
    if (title.isEmpty() || author.isEmpty() || genre.isEmpty() || yearStr.isEmpty() || stockStr.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all fields.");
        return;
    }

    // Validate year and stock inputs
    bool yearOk, stockOk;
    int year = yearStr.toInt(&yearOk);
    int stock = stockStr.toInt(&stockOk);

    if (!yearOk || year <= 0) {
        QMessageBox::warning(this, "Error", "Publication year must be a valid positive integer.");
        return;
    }
    if (!stockOk || stock <= 0) {
        QMessageBox::warning(this, "Error", "Stock must be a valid positive integer.");
        return;
    }

    // Update book details in the database
    QSqlQuery query;
    query.prepare("UPDATE books SET title = :title, author = :author, genre = :genre, "
                  "publication_year = :year, stock = :stock WHERE book_id = :book_id");
    query.bindValue(":title", title);
    query.bindValue(":author", author);
    query.bindValue(":genre", genre);
    query.bindValue(":year", year);
    query.bindValue(":stock", stock);
    query.bindValue(":book_id", currentBookId);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Book updated successfully!");
        accept();
    } else {
        QMessageBox::warning(this, "Error", "Failed to update book: " + query.lastError().text());
    }
}
