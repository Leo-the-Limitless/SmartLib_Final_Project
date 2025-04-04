/********************************************************************************
** Form generated from reading UI file 'BorrowedBooksPage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROWEDBOOKSPAGE_H
#define UI_BORROWEDBOOKSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BorrowedBooksPage
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QTableWidget *borrowedBooksTableWidget;

    void setupUi(QWidget *BorrowedBooksPage)
    {
        if (BorrowedBooksPage->objectName().isEmpty())
            BorrowedBooksPage->setObjectName("BorrowedBooksPage");
        BorrowedBooksPage->resize(800, 600);
        centralwidget = new QWidget(BorrowedBooksPage);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget { background-color: white; }"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        borrowedBooksTableWidget = new QTableWidget(centralwidget);
        if (borrowedBooksTableWidget->columnCount() < 5)
            borrowedBooksTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        borrowedBooksTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        borrowedBooksTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        borrowedBooksTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        borrowedBooksTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        borrowedBooksTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        borrowedBooksTableWidget->setObjectName("borrowedBooksTableWidget");
        borrowedBooksTableWidget->setAlternatingRowColors(true);
        borrowedBooksTableWidget->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        borrowedBooksTableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout->addWidget(borrowedBooksTableWidget);


        retranslateUi(BorrowedBooksPage);

        QMetaObject::connectSlotsByName(BorrowedBooksPage);
    } // setupUi

    void retranslateUi(QWidget *BorrowedBooksPage)
    {
        BorrowedBooksPage->setWindowTitle(QCoreApplication::translate("BorrowedBooksPage", "Borrowed Books", nullptr));
        labelTitle->setText(QCoreApplication::translate("BorrowedBooksPage", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Borrowed Books</span></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = borrowedBooksTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("BorrowedBooksPage", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = borrowedBooksTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("BorrowedBooksPage", "Book ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = borrowedBooksTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("BorrowedBooksPage", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = borrowedBooksTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("BorrowedBooksPage", "Borrow Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = borrowedBooksTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("BorrowedBooksPage", "Due Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BorrowedBooksPage: public Ui_BorrowedBooksPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROWEDBOOKSPAGE_H
