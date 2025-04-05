/********************************************************************************
** Form generated from reading UI file 'DeleteBookDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEBOOKDIALOG_H
#define UI_DELETEBOOKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DeleteBookDialog
{
public:
    QLabel *labelTitle;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *idInput;
    QLabel *ResultLabel;
    QPushButton *ConfirmButton;

    void setupUi(QDialog *DeleteBookDialog)
    {
        if (DeleteBookDialog->objectName().isEmpty())
            DeleteBookDialog->setObjectName("DeleteBookDialog");
        DeleteBookDialog->resize(370, 300);
        DeleteBookDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
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
        labelTitle = new QLabel(DeleteBookDialog);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setGeometry(QRect(10, 10, 350, 28));
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);
        groupBox = new QGroupBox(DeleteBookDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(40, 60, 291, 151));
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
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 60, 71, 20));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #2c3e50;\n"
"}"));
        idInput = new QLineEdit(groupBox);
        idInput->setObjectName("idInput");
        idInput->setGeometry(QRect(160, 60, 113, 24));
        ResultLabel = new QLabel(groupBox);
        ResultLabel->setObjectName("ResultLabel");
        ResultLabel->setGeometry(QRect(80, 100, 131, 41));
        QFont font1;
        ResultLabel->setFont(font1);
        ConfirmButton = new QPushButton(DeleteBookDialog);
        ConfirmButton->setObjectName("ConfirmButton");
        ConfirmButton->setGeometry(QRect(140, 240, 91, 31));

        retranslateUi(DeleteBookDialog);

        QMetaObject::connectSlotsByName(DeleteBookDialog);
    } // setupUi

    void retranslateUi(QDialog *DeleteBookDialog)
    {
        DeleteBookDialog->setWindowTitle(QCoreApplication::translate("DeleteBookDialog", "Delete Books Section", nullptr));
        labelTitle->setText(QCoreApplication::translate("DeleteBookDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Delete Book Selection</span></p><p align=\"center\"><br/></p></body></html>", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DeleteBookDialog", "Properties", nullptr));
        label->setText(QCoreApplication::translate("DeleteBookDialog", "ID", nullptr));
        ResultLabel->setText(QString());
        ConfirmButton->setText(QCoreApplication::translate("DeleteBookDialog", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteBookDialog: public Ui_DeleteBookDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEBOOKDIALOG_H
