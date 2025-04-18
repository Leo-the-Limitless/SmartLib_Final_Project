// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DatabaseManager.h"
#include <QPushButton>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    // Updated constructor to accept user data
    MainWindow(int userId, const QString &username, const QString &email, bool isAdmin, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadBooks();

    void searchBooks();
    void searchBorrowedBooks();
    void onActionLogOutClicked();
    void onActionExitClicked();
    void onActionRefreshClicked();
    void onBorrowButtonClicked();
    void onBookSelectionChanged();
    void onReturnButtonClicked();
    void loadBorrowedBooks();
    void onTabChanged(int index); // Method to handle tab changes

private:
    Ui::MainWindow *ui;
    DatabaseManager dbManager;

    int currentUserId;
    QString currentUsername;
    QString currentEmail;
    bool currentIsAdmin;  // Store admin status

};

#endif // MAINWINDOW_H
