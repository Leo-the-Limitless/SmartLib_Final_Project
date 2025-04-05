/********************************************************************************
** Form generated from reading UI file 'EditBookDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITBOOKDIALOG_H
#define UI_EDITBOOKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditBookDialog
{
public:
    QLabel *labelTitle;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLineEdit *titleInput;
    QLineEdit *authorInput;
    QLabel *label_3;
    QLineEdit *genreInput;
    QLabel *label_4;
    QLabel *label_9;
    QLineEdit *yearInput;
    QLineEdit *stockInput;
    QLabel *label_10;
    QPushButton *SaveButton;

    void setupUi(QDialog *EditBookDialog)
    {
        if (EditBookDialog->objectName().isEmpty())
            EditBookDialog->setObjectName("EditBookDialog");
        EditBookDialog->resize(370, 450);
        EditBookDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
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
"    font-weight: bold;\n"
""
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
"QLineEdit{\n"
"	background-color:white;\n"
"	color:black;\n"
"}"));
        labelTitle = new QLabel(EditBookDialog);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setGeometry(QRect(10, 10, 351, 28));
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);
        groupBox = new QGroupBox(EditBookDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(40, 60, 291, 301));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    font-weight: bold;\n"
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
"	color:black;\n"
"}\n"
""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 100, 71, 20));
        QFont font;
        font.setBold(true);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #2c3e50;\n"
"}"));
        titleInput = new QLineEdit(groupBox);
        titleInput->setObjectName("titleInput");
        titleInput->setGeometry(QRect(160, 100, 113, 24));
        authorInput = new QLineEdit(groupBox);
        authorInput->setObjectName("authorInput");
        authorInput->setGeometry(QRect(160, 140, 113, 24));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 140, 71, 20));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #2c3e50;\n"
"}"));
        genreInput = new QLineEdit(groupBox);
        genreInput->setObjectName("genreInput");
        genreInput->setGeometry(QRect(160, 180, 113, 24));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 180, 71, 20));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #2c3e50;\n"
"}"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 220, 121, 20));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #2c3e50;\n"
"}"));
        yearInput = new QLineEdit(groupBox);
        yearInput->setObjectName("yearInput");
        yearInput->setGeometry(QRect(160, 220, 113, 24));
        stockInput = new QLineEdit(groupBox);
        stockInput->setObjectName("stockInput");
        stockInput->setGeometry(QRect(160, 260, 113, 24));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 260, 121, 20));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #2c3e50;\n"
"}"));
        SaveButton = new QPushButton(EditBookDialog);
        SaveButton->setObjectName("SaveButton");
        SaveButton->setGeometry(QRect(140, 390, 91, 31));

        retranslateUi(EditBookDialog);

        QMetaObject::connectSlotsByName(EditBookDialog);
    } // setupUi

    void retranslateUi(QDialog *EditBookDialog)
    {
        EditBookDialog->setWindowTitle(QCoreApplication::translate("EditBookDialog", "Editor Section", nullptr));
        labelTitle->setText(QCoreApplication::translate("EditBookDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700;\">Edit Book Section</span></p><p align=\"center\"><span style=\" font-size:16pt; font-weight:700;\"><br/></span></p></body></html>", nullptr));
        groupBox->setTitle(QCoreApplication::translate("EditBookDialog", "EDITOR", nullptr));
        label_2->setText(QCoreApplication::translate("EditBookDialog", "Title", nullptr));
        label_3->setText(QCoreApplication::translate("EditBookDialog", "Author", nullptr));
        label_4->setText(QCoreApplication::translate("EditBookDialog", "Genre", nullptr));
        label_9->setText(QCoreApplication::translate("EditBookDialog", "Publication Year", nullptr));
        label_10->setText(QCoreApplication::translate("EditBookDialog", "Stock", nullptr));
        SaveButton->setText(QCoreApplication::translate("EditBookDialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditBookDialog: public Ui_EditBookDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITBOOKDIALOG_H
