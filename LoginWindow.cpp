#include "mainwindow.h"
#include "AdminPanel.h"
#include "LoginWindow.h"
#include "RegisterWindow.h"
#include "ui_LoginWindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::LoginWindow), dbManager() {  // Initialize dbManager
    ui->setupUi(this);

    if (!dbManager.openDatabase()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database.");
        return;
    }

    connect(ui->LoginButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);
    connect(ui->RegisterButton, &QPushButton::clicked, this, &LoginWindow::onRegisterButtonClicked);
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::onLoginButtonClicked() {
    QString email = ui->emailInput->text();
    QString password = ui->passwordInput->text();
    int userId;
    QString username;
    bool isAdmin;

    if (dbManager.checkCredentials(email, password, userId, username, isAdmin)) {
        QMessageBox::information(this, "Login Successful", "Welcome, " + username);

        emit userLoggedIn(userId, isAdmin);

        QWidget *nextWindow = nullptr;
        if (isAdmin) {
            nextWindow = new AdminPanel();
        } else {
            nextWindow = new MainWindow(userId, username, email, isAdmin);
        }

        nextWindow->show();
        this->hide();
        connect(nextWindow, &QWidget::destroyed, this, &LoginWindow::close);
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid email or password.");
    }
}

void LoginWindow::onRegisterButtonClicked() {
    this->hide();
    RegisterWindow *registerWindow = new RegisterWindow(this);
    registerWindow->exec();
}
