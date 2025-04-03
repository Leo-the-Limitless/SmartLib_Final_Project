#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QMainWindow>  // Change QWidget to QMainWindow
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QMessageBox>

#include "ui_AdminPanel.h"  // ✅ Must be included BEFORE using Ui::AdminPanel

namespace Ui {
class AdminPanel;  // ✅ Forward declaration
}

class AdminPanel : public QMainWindow {  // Change QWidget to QMainWindow
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();

private slots:
    void onActionAddBookClicked();
    void onActionEditBookClicked();
    void onActionDeleteBookClicked();
    void onBookSelectionChanged();
    void searchBooks();
    void loadBooks();

private:
    Ui::AdminPanel *ui;  // ✅ This requires `ui_AdminPanel.h`
    QString selectedBookId;
};

#endif // ADMINPANEL_H
