/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
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
    QTabWidget *tabWidget;
    QWidget *tabAllBooks;
    QVBoxLayout *verticalLayout_2;
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
    QPushButton *borrowButton;
    QPushButton *returnButton;
    QPushButton *refreshButton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tabMyBorrowed;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *borrowedBooksTableWidget;
    QGroupBox *groupBoxBorrowedSearch;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelBorrowedSearch;
    QLineEdit *lineEditBorrowedSearch;
    QComboBox *comboBoxBorrowedSearchType;
    QLabel *BorrowedResultLabel;
    QGroupBox *groupBoxBorrowedActions;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelSelectedBorrowed;
    QLabel *SelectedBorrowedLabel;
    QPushButton *returnBorrowedButton;
    QPushButton *refreshBorrowedButton;
    QSpacerItem *horizontalSpacer_4;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuBooks;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
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
"}\n"
"\n"
"QTabWidget::pane { \n"
"    border: 1px solid #d0d0d0;\n"
"    border-radius: 5px;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #e0e0e0;\n"
"    color: #2c3e50;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"    min-width: 100px;\n"
"    padding: 8px 12px;\n"
"    margin-right: 2px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"}\n"
"\n"
"QTabBar::tab:ho"
                        "ver:!selected {\n"
"    background-color: #d0d0d0;\n"
"}"));
        actionAddBook = new QAction(MainWindow);
        actionAddBook->setObjectName("actionAddBook");
        actionEditBook = new QAction(MainWindow);
        actionEditBook->setObjectName("actionEditBook");
        actionDeleteBook = new QAction(MainWindow);
        actionDeleteBook->setObjectName("actionDeleteBook");
        actionBorrowBook = new QAction(MainWindow);
        actionBorrowBook->setObjectName("actionBorrowBook");
        actionReturnBook = new QAction(MainWindow);
        actionReturnBook->setObjectName("actionReturnBook");
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName("actionRefresh");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionLog_out = new QAction(MainWindow);
        actionLog_out->setObjectName("actionLog_out");
        centralwidget = new QWidget(MainWindow);
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

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabAllBooks = new QWidget();
        tabAllBooks->setObjectName("tabAllBooks");
        verticalLayout_2 = new QVBoxLayout(tabAllBooks);
        verticalLayout_2->setObjectName("verticalLayout_2");
        booksTableWidget = new QTableWidget(tabAllBooks);
        if (booksTableWidget->columnCount() < 6)
            booksTableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
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

        verticalLayout_2->addWidget(booksTableWidget);

        groupBoxSearch = new QGroupBox(tabAllBooks);
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


        verticalLayout_2->addWidget(groupBoxSearch);

        groupBoxActions = new QGroupBox(tabAllBooks);
        groupBoxActions->setObjectName("groupBoxActions");
        groupBoxActions->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	color: black;\n"
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
"}"));
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

        borrowButton = new QPushButton(groupBoxActions);
        borrowButton->setObjectName("borrowButton");
        borrowButton->setMinimumSize(QSize(140, 0));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("go-down")));
        borrowButton->setIcon(icon);

        horizontalLayout->addWidget(borrowButton);

        returnButton = new QPushButton(groupBoxActions);
        returnButton->setObjectName("returnButton");
        returnButton->setMinimumSize(QSize(140, 0));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("go-up")));
        returnButton->setIcon(icon1);

        horizontalLayout->addWidget(returnButton);

        refreshButton = new QPushButton(groupBoxActions);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setMinimumSize(QSize(140, 0));
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("view-refresh")));
        refreshButton->setIcon(icon2);

        horizontalLayout->addWidget(refreshButton);

        horizontalSpacer_2 = new QSpacerItem(40, 15, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(groupBoxActions);

        tabWidget->addTab(tabAllBooks, QString());
        tabMyBorrowed = new QWidget();
        tabMyBorrowed->setObjectName("tabMyBorrowed");
        verticalLayout_3 = new QVBoxLayout(tabMyBorrowed);
        verticalLayout_3->setObjectName("verticalLayout_3");
        borrowedBooksTableWidget = new QTableWidget(tabMyBorrowed);
        if (borrowedBooksTableWidget->columnCount() < 4)
            borrowedBooksTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        borrowedBooksTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        borrowedBooksTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        borrowedBooksTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        borrowedBooksTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        borrowedBooksTableWidget->setObjectName("borrowedBooksTableWidget");
        borrowedBooksTableWidget->setAlternatingRowColors(true);
        borrowedBooksTableWidget->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        borrowedBooksTableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout_3->addWidget(borrowedBooksTableWidget);

        groupBoxBorrowedSearch = new QGroupBox(tabMyBorrowed);
        groupBoxBorrowedSearch->setObjectName("groupBoxBorrowedSearch");
        groupBoxBorrowedSearch->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	color: black;\n"
"}\n"
"\n"
"QComboBox{\n"
"	background-color: #3498db;\n"
"	color:black;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(groupBoxBorrowedSearch);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        labelBorrowedSearch = new QLabel(groupBoxBorrowedSearch);
        labelBorrowedSearch->setObjectName("labelBorrowedSearch");

        horizontalLayout_3->addWidget(labelBorrowedSearch);

        lineEditBorrowedSearch = new QLineEdit(groupBoxBorrowedSearch);
        lineEditBorrowedSearch->setObjectName("lineEditBorrowedSearch");

        horizontalLayout_3->addWidget(lineEditBorrowedSearch);

        comboBoxBorrowedSearchType = new QComboBox(groupBoxBorrowedSearch);
        comboBoxBorrowedSearchType->addItem(QString());
        comboBoxBorrowedSearchType->addItem(QString());
        comboBoxBorrowedSearchType->addItem(QString());
        comboBoxBorrowedSearchType->addItem(QString());
        comboBoxBorrowedSearchType->setObjectName("comboBoxBorrowedSearchType");
        comboBoxBorrowedSearchType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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

        horizontalLayout_3->addWidget(comboBoxBorrowedSearchType);

        BorrowedResultLabel = new QLabel(groupBoxBorrowedSearch);
        BorrowedResultLabel->setObjectName("BorrowedResultLabel");
        BorrowedResultLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:red;\n"
"}"));

        horizontalLayout_3->addWidget(BorrowedResultLabel);


        verticalLayout_3->addWidget(groupBoxBorrowedSearch);

        groupBoxBorrowedActions = new QGroupBox(tabMyBorrowed);
        groupBoxBorrowedActions->setObjectName("groupBoxBorrowedActions");
        groupBoxBorrowedActions->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	color: black;\n"
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
"}"));
        horizontalLayout_4 = new QHBoxLayout(groupBoxBorrowedActions);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_3 = new QSpacerItem(40, 15, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        labelSelectedBorrowed = new QLabel(groupBoxBorrowedActions);
        labelSelectedBorrowed->setObjectName("labelSelectedBorrowed");

        horizontalLayout_4->addWidget(labelSelectedBorrowed);

        SelectedBorrowedLabel = new QLabel(groupBoxBorrowedActions);
        SelectedBorrowedLabel->setObjectName("SelectedBorrowedLabel");

        horizontalLayout_4->addWidget(SelectedBorrowedLabel);

        returnBorrowedButton = new QPushButton(groupBoxBorrowedActions);
        returnBorrowedButton->setObjectName("returnBorrowedButton");
        returnBorrowedButton->setMinimumSize(QSize(140, 0));
        returnBorrowedButton->setIcon(icon1);

        horizontalLayout_4->addWidget(returnBorrowedButton);

        refreshBorrowedButton = new QPushButton(groupBoxBorrowedActions);
        refreshBorrowedButton->setObjectName("refreshBorrowedButton");
        refreshBorrowedButton->setMinimumSize(QSize(140, 0));
        refreshBorrowedButton->setIcon(icon2);

        horizontalLayout_4->addWidget(refreshBorrowedButton);

        horizontalSpacer_4 = new QSpacerItem(40, 15, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_3->addWidget(groupBoxBorrowedActions);

        tabWidget->addTab(tabMyBorrowed, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuBooks = new QMenu(menubar);
        menuBooks->setObjectName("menuBooks");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuBooks->menuAction());
        menuFile->addAction(actionRefresh);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuFile->addAction(actionLog_out);
        menuBooks->addAction(actionAddBook);
        menuBooks->addAction(actionEditBook);
        menuBooks->addAction(actionDeleteBook);
        menuBooks->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Library Management System", nullptr));
        actionAddBook->setText(QCoreApplication::translate("MainWindow", "Add Book", nullptr));
        actionEditBook->setText(QCoreApplication::translate("MainWindow", "Edit Book", nullptr));
        actionDeleteBook->setText(QCoreApplication::translate("MainWindow", "Delete Book", nullptr));
        actionBorrowBook->setText(QCoreApplication::translate("MainWindow", "Borrow Book", nullptr));
        actionReturnBook->setText(QCoreApplication::translate("MainWindow", "Return Book", nullptr));
        actionRefresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionLog_out->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Library Management System</span></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = booksTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = booksTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = booksTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = booksTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Genre", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = booksTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Publication Year", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = booksTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        groupBoxSearch->setTitle(QCoreApplication::translate("MainWindow", "Search Books", nullptr));
        labelSearch->setText(QCoreApplication::translate("MainWindow", "Search:", nullptr));
        lineEditSearch->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter title, author or keyword...", nullptr));
        comboBoxSearchType->setItemText(0, QCoreApplication::translate("MainWindow", "Title", nullptr));
        comboBoxSearchType->setItemText(1, QCoreApplication::translate("MainWindow", "Author", nullptr));
        comboBoxSearchType->setItemText(2, QCoreApplication::translate("MainWindow", "Genre", nullptr));
        comboBoxSearchType->setItemText(3, QCoreApplication::translate("MainWindow", "All Fields", nullptr));

        ResultLabel->setText(QString());
        groupBoxActions->setTitle(QCoreApplication::translate("MainWindow", "Book Actions", nullptr));
        labelUserId->setText(QCoreApplication::translate("MainWindow", "Selected Book:", nullptr));
        SelectedLabel->setText(QString());
        borrowButton->setText(QCoreApplication::translate("MainWindow", "Borrow Book", nullptr));
        returnButton->setText(QCoreApplication::translate("MainWindow", "Return Book", nullptr));
        refreshButton->setText(QCoreApplication::translate("MainWindow", "Refresh List", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAllBooks), QCoreApplication::translate("MainWindow", "All Books", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = borrowedBooksTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = borrowedBooksTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = borrowedBooksTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = borrowedBooksTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Remaining Days", nullptr));
        groupBoxBorrowedSearch->setTitle(QCoreApplication::translate("MainWindow", "Search Borrowed Books", nullptr));
        labelBorrowedSearch->setText(QCoreApplication::translate("MainWindow", "Search:", nullptr));
        lineEditBorrowedSearch->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter title or author...", nullptr));
        comboBoxBorrowedSearchType->setItemText(0, QCoreApplication::translate("MainWindow", "Title", nullptr));
        comboBoxBorrowedSearchType->setItemText(1, QCoreApplication::translate("MainWindow", "Author", nullptr));
        comboBoxBorrowedSearchType->setItemText(2, QCoreApplication::translate("MainWindow", "Genre", nullptr));
        comboBoxBorrowedSearchType->setItemText(3, QCoreApplication::translate("MainWindow", "All Fields", nullptr));

        BorrowedResultLabel->setText(QString());
        groupBoxBorrowedActions->setTitle(QCoreApplication::translate("MainWindow", "Actions", nullptr));
        labelSelectedBorrowed->setText(QString());
        SelectedBorrowedLabel->setText(QString());
        returnBorrowedButton->setText(QCoreApplication::translate("MainWindow", "Return Book", nullptr));
        refreshBorrowedButton->setText(QCoreApplication::translate("MainWindow", "Refresh List", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabMyBorrowed), QCoreApplication::translate("MainWindow", "My Borrowed Books", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuBooks->setTitle(QCoreApplication::translate("MainWindow", "Books", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
