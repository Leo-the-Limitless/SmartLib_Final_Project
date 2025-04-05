/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLabel *label;
    QLineEdit *emailInput;
    QLabel *label_2;
    QLineEdit *passwordInput;
    QLabel *label_3;
    QPushButton *LoginButton;
    QPushButton *RegisterButton;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(320, 380);
        LoginWindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
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
        label = new QLabel(LoginWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 20, 141, 51));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        emailInput = new QLineEdit(LoginWindow);
        emailInput->setObjectName("emailInput");
        emailInput->setGeometry(QRect(170, 90, 113, 31));
        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 90, 91, 31));
        QFont font1;
        label_2->setFont(font1);
        passwordInput = new QLineEdit(LoginWindow);
        passwordInput->setObjectName("passwordInput");
        passwordInput->setGeometry(QRect(170, 160, 113, 31));
        label_3 = new QLabel(LoginWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 160, 101, 31));
        label_3->setFont(font1);
        LoginButton = new QPushButton(LoginWindow);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(79, 230, 161, 41));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        LoginButton->setFont(font2);
        RegisterButton = new QPushButton(LoginWindow);
        RegisterButton->setObjectName("RegisterButton");
        RegisterButton->setGeometry(QRect(80, 300, 161, 41));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        RegisterButton->setFont(font3);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Login Window", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">Login Section</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">EMAIL:</span></p><p><br/></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Password:</span></p></body></html>", nullptr));
        LoginButton->setText(QCoreApplication::translate("LoginWindow", "Log In", nullptr));
        RegisterButton->setText(QCoreApplication::translate("LoginWindow", "New User? Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
