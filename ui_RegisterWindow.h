/********************************************************************************
** Form generated from reading UI file 'RegisterWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QLabel *label;
    QPushButton *registerButton;
    QLineEdit *nameInput;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *passwordInput;
    QLabel *label_5;
    QLineEdit *passwordConInput;
    QLineEdit *emailInput;
    QLabel *label_6;
    QPushButton *cancleButton;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(320, 490);
        RegisterWindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
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
        label = new QLabel(RegisterWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 10, 221, 51));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        registerButton = new QPushButton(RegisterWindow);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(90, 390, 141, 41));
        nameInput = new QLineEdit(RegisterWindow);
        nameInput->setObjectName("nameInput");
        nameInput->setGeometry(QRect(170, 80, 113, 31));
        label_3 = new QLabel(RegisterWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 80, 131, 31));
        QFont font1;
        label_3->setFont(font1);
        label_4 = new QLabel(RegisterWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 220, 131, 31));
        label_4->setFont(font1);
        passwordInput = new QLineEdit(RegisterWindow);
        passwordInput->setObjectName("passwordInput");
        passwordInput->setGeometry(QRect(170, 220, 113, 31));
        label_5 = new QLabel(RegisterWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 290, 101, 81));
        label_5->setFont(font1);
        passwordConInput = new QLineEdit(RegisterWindow);
        passwordConInput->setObjectName("passwordConInput");
        passwordConInput->setGeometry(QRect(170, 310, 113, 31));
        emailInput = new QLineEdit(RegisterWindow);
        emailInput->setObjectName("emailInput");
        emailInput->setGeometry(QRect(170, 150, 113, 31));
        label_6 = new QLabel(RegisterWindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 150, 131, 31));
        label_6->setFont(font1);
        cancleButton = new QPushButton(RegisterWindow);
        cancleButton->setObjectName("cancleButton");
        cancleButton->setGeometry(QRect(230, 440, 71, 31));

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Registration Window", nullptr));
        label->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">Registeration Section</span></p></body></html>", nullptr));
        registerButton->setText(QCoreApplication::translate("RegisterWindow", "Create Account", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Username:</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Password:</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Confirm </span></p><p><span style=\" font-size:14pt; font-weight:700;\">Password</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("RegisterWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Email:</span></p></body></html>", nullptr));
        cancleButton->setText(QCoreApplication::translate("RegisterWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
