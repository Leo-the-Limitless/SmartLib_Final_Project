/********************************************************************************
** Form generated from reading UI file 'AdminPanel.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPANEL_H
#define UI_ADMINPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminPanel
{
public:
    QAction *actionAddBook;
    QAction *actionEditBook;
    QAction *actionDeleteBook;
    QAction *actionBorrowBook;
    QAction *actionReturnBook;
    QAction *actionRefresh;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionLog_out;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QTableWidget *booksTableWidget;
    QGroupBox *groupBoxSearch;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelSearch;
    QLineEdit *lineEditSearch;
    QComboBox *comboBoxSearchType;
    QLabel *ResultLabel;
    QGroupBox *groupBoxActions;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *labelUserId;
    QLabel *SelectedLabel;
    QPushButton *addBookButton;
    QPushButton *editBookButton;
    QPushButton *deleteBookButton;
    QSpacerItem *horizontalSpacer_2;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;

    void setupUi(QMainWindow *AdminPanel)
    {
        if (AdminPanel->objectName().isEmpty())
            AdminPanel->setObjectName("AdminPanel");
        AdminPanel->resize(800, 600);
        AdminPanel->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #f5f5f5;\n"
"}\n"
"\n"
"QTableWidget {\n"
"    background-color: white;\n"
"    alternate-background-color: #f0f0f0;\n"
"    border: 1px solid #d0d0d0;\n"
"    border-radius: 5px;\n"
"    selection-background-color: #3498db;\n"
"    selection-color: white;\n"
"	color: black;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1c6ea4;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #bdc3c7;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: none;\n"
"}\n"
"\n"
"QLabel {\n"
"    font-size: 14px;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"QGroupBox {\n"
"   "
                        " font-weight: bold;\n"
"    border: 1px solid #d0d0d0;\n"
"    border-radius: 5px;\n"
"    margin-top: 10px;\n"
"    padding-top: 15px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 5px;\n"
"}\n"
"\n"
"QStatusBar{\n"
"	background-color:white;\n"
"}\n"
"QMenuBar{\n"
"	background-color: #3498db;\n"
"}\n"
"\n"
"QLineEdit{\n"
"	color:black;\n"
"}\n"
"\n"
"QMessabeBox{\n"
"	color:black;\n"
"	background-color:white;\n"
"}"));
        actionAddBook = new QAction(AdminPanel);
        actionAddBook->setObjectName("actionAddBook");
        actionEditBook = new QAction(AdminPanel);
        actionEditBook->setObjectName("actionEditBook");
        actionDeleteBook = new QAction(AdminPanel);
        actionDeleteBook->setObjectName("actionDeleteBook");
        actionBorrowBook = new QAction(AdminPanel);
        actionBorrowBook->setObjectName("actionBorrowBook");
        actionReturnBook = new QAction(AdminPanel);
        actionReturnBook->setObjectName("actionReturnBook");
        actionRefresh = new QAction(AdminPanel);
        actionRefresh->setObjectName("actionRefresh");
        actionExit = new QAction(AdminPanel);
        actionExit->setObjectName("actionExit");
        actionAbout = new QAction(AdminPanel);
        actionAbout->setObjectName("actionAbout");
        actionLog_out = new QAction(AdminPanel);
        actionLog_out->setObjectName("actionLog_out");
        centralwidget = new QWidget(AdminPanel);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: white;\n"
"}"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        booksTableWidget = new QTableWidget(centralwidget);
        if (booksTableWidget->columnCount() < 6)
            booksTableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignJustify|Qt::AlignBottom);
        booksTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        booksTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        booksTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        booksTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        booksTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        booksTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        booksTableWidget->setObjectName("booksTableWidget");
        booksTableWidget->setAlternatingRowColors(true);
        booksTableWidget->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        booksTableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout->addWidget(booksTableWidget);

        groupBoxSearch = new QGroupBox(centralwidget);
        groupBoxSearch->setObjectName("groupBoxSearch");
        groupBoxSearch->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	color: black;\n"
"}\n"
"\n"
"QComboBox{\n"
"	background-color: #3498db;\n"
"	color:black;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(groupBoxSearch);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelSearch = new QLabel(groupBoxSearch);
        labelSearch->setObjectName("labelSearch");

        horizontalLayout_2->addWidget(labelSearch);

        lineEditSearch = new QLineEdit(groupBoxSearch);
        lineEditSearch->setObjectName("lineEditSearch");

        horizontalLayout_2->addWidget(lineEditSearch);

        comboBoxSearchType = new QComboBox(groupBoxSearch);
        comboBoxSearchType->addItem(QString());
        comboBoxSearchType->addItem(QString());
        comboBoxSearchType->addItem(QString());
        comboBoxSearchType->addItem(QString());
        comboBoxSearchType->setObjectName("comboBoxSearchType");
        comboBoxSearchType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #3498db;\n"
"    color: black;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #3498db; \n"
"    color: black;              \n"
"    selection-background-color: #2980b9;\n"
"    selection-color: white;      \n"
"}\n"
""));

        horizontalLayout_2->addWidget(comboBoxSearchType);

        ResultLabel = new QLabel(groupBoxSearch);
        ResultLabel->setObjectName("ResultLabel");
        ResultLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:red;\n"
"}"));

        horizontalLayout_2->addWidget(ResultLabel);


        verticalLayout->addWidget(groupBoxSearch);

        groupBoxActions = new QGroupBox(centralwidget);
        groupBoxActions->setObjectName("groupBoxActions");
        groupBoxActions->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"   color: black;\n"
"  }\n"
"\n"
"  QPushButton {\n"
"      background-color: #3498db;\n"
"      color: white;\n"
"      border: none;\n"
"      border-radius: 5px;\n"
"      padding: 8px 16px;\n"
"      font-weight: bold;\n"
"  }\n"
"\n"
"  QPushButton:hover {\n"
"      background-color: #2980b9;\n"
"  }\n"
"\n"
"  QPushButton:pressed {\n"
"      background-color: #1c6ea4;\n"
"  }\n"
"\n"
"  QPushButton:disabled {\n"
"      background-color: #bdc3c7;\n"
"  }"));
        horizontalLayout = new QHBoxLayout(groupBoxActions);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 15, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelUserId = new QLabel(groupBoxActions);
        labelUserId->setObjectName("labelUserId");

        horizontalLayout->addWidget(labelUserId);

        SelectedLabel = new QLabel(groupBoxActions);
        SelectedLabel->setObjectName("SelectedLabel");

        horizontalLayout->addWidget(SelectedLabel);

        addBookButton = new QPushButton(groupBoxActions);
        addBookButton->setObjectName("addBookButton");
        addBookButton->setMinimumSize(QSize(140, 0));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("list-add")));
        addBookButton->setIcon(icon);

        horizontalLayout->addWidget(addBookButton);

        editBookButton = new QPushButton(groupBoxActions);
        editBookButton->setObjectName("editBookButton");
        editBookButton->setMinimumSize(QSize(140, 0));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("document-edit")));
        editBookButton->setIcon(icon1);

        horizontalLayout->addWidget(editBookButton);

        deleteBookButton = new QPushButton(groupBoxActions);
        deleteBookButton->setObjectName("deleteBookButton");
        deleteBookButton->setMinimumSize(QSize(140, 0));
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("edit-delete")));
        deleteBookButton->setIcon(icon2);

        horizontalLayout->addWidget(deleteBookButton);

        horizontalSpacer_2 = new QSpacerItem(40, 15, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(groupBoxActions);

        AdminPanel->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(AdminPanel);
        statusbar->setObjectName("statusbar");
        AdminPanel->setStatusBar(statusbar);
        menubar = new QMenuBar(AdminPanel);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        AdminPanel->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionRefresh);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuFile->addAction(actionLog_out);

        retranslateUi(AdminPanel);

        QMetaObject::connectSlotsByName(AdminPanel);
    } // setupUi

    void retranslateUi(QMainWindow *AdminPanel)
    {
        AdminPanel->setWindowTitle(QCoreApplication::translate("AdminPanel", "Library Management System", nullptr));
        actionAddBook->setText(QCoreApplication::translate("AdminPanel", "Add Book", nullptr));
        actionEditBook->setText(QCoreApplication::translate("AdminPanel", "Edit Book", nullptr));
        actionDeleteBook->setText(QCoreApplication::translate("AdminPanel", "Delete Book", nullptr));
        actionBorrowBook->setText(QCoreApplication::translate("AdminPanel", "Borrow Book", nullptr));
        actionReturnBook->setText(QCoreApplication::translate("AdminPanel", "Return Book", nullptr));
        actionRefresh->setText(QCoreApplication::translate("AdminPanel", "Refresh", nullptr));
        actionExit->setText(QCoreApplication::translate("AdminPanel", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("AdminPanel", "About", nullptr));
        actionLog_out->setText(QCoreApplication::translate("AdminPanel", "Log out", nullptr));
        labelTitle->setText(QCoreApplication::translate("AdminPanel", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Library Management System</span></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = booksTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AdminPanel", "IDss", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = booksTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AdminPanel", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = booksTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AdminPanel", "Author", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = booksTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AdminPanel", "Genre", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = booksTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("AdminPanel", "Publication Year", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = booksTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("AdminPanel", "Status", nullptr));
        groupBoxSearch->setTitle(QCoreApplication::translate("AdminPanel", "Search Books", nullptr));
        labelSearch->setText(QCoreApplication::translate("AdminPanel", "Search:", nullptr));
        lineEditSearch->setPlaceholderText(QCoreApplication::translate("AdminPanel", "Enter title, author or keyword...", nullptr));
        comboBoxSearchType->setItemText(0, QCoreApplication::translate("AdminPanel", "Title", nullptr));
        comboBoxSearchType->setItemText(1, QCoreApplication::translate("AdminPanel", "Author", nullptr));
        comboBoxSearchType->setItemText(2, QCoreApplication::translate("AdminPanel", "Genre", nullptr));
        comboBoxSearchType->setItemText(3, QCoreApplication::translate("AdminPanel", "All Fields", nullptr));

        ResultLabel->setText(QString());
        groupBoxActions->setTitle(QCoreApplication::translate("AdminPanel", "Book Actions", nullptr));
        labelUserId->setText(QCoreApplication::translate("AdminPanel", "Selected Book:", nullptr));
        SelectedLabel->setText(QString());
        addBookButton->setText(QCoreApplication::translate("AdminPanel", "Add Book", nullptr));
        editBookButton->setText(QCoreApplication::translate("AdminPanel", "\360\237\226\212\357\270\217 Edit Book", nullptr));
        deleteBookButton->setText(QCoreApplication::translate("AdminPanel", "Delete Book", nullptr));
        menuFile->setTitle(QCoreApplication::translate("AdminPanel", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminPanel: public Ui_AdminPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPANEL_H
