/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *serial_label;
    QComboBox *serial_box;
    QLabel *baud_label;
    QComboBox *baud_box;
    QPushButton *open_button;
    QPushButton *close_button;
    QPushButton *close_button_Led;
    QPushButton *open_button_Led;
    QLabel *serial_label_2;
    QTextEdit *textEdit_Send;
    QLabel *baud_label_2;
    QPlainTextEdit *plainTextEdit;
    QPushButton *SwitchFilepushButton;
    QPlainTextEdit *showTextpathEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(913, 522);
        serial_label = new QLabel(Widget);
        serial_label->setObjectName(QStringLiteral("serial_label"));
        serial_label->setGeometry(QRect(30, 20, 72, 31));
        serial_box = new QComboBox(Widget);
        serial_box->addItem(QString());
        serial_box->addItem(QString());
        serial_box->setObjectName(QStringLiteral("serial_box"));
        serial_box->setGeometry(QRect(170, 20, 87, 22));
        baud_label = new QLabel(Widget);
        baud_label->setObjectName(QStringLiteral("baud_label"));
        baud_label->setGeometry(QRect(30, 50, 72, 31));
        baud_box = new QComboBox(Widget);
        baud_box->addItem(QString());
        baud_box->addItem(QString());
        baud_box->setObjectName(QStringLiteral("baud_box"));
        baud_box->setGeometry(QRect(170, 50, 87, 22));
        open_button = new QPushButton(Widget);
        open_button->setObjectName(QStringLiteral("open_button"));
        open_button->setGeometry(QRect(20, 90, 93, 28));
        close_button = new QPushButton(Widget);
        close_button->setObjectName(QStringLiteral("close_button"));
        close_button->setGeometry(QRect(170, 90, 93, 28));
        close_button_Led = new QPushButton(Widget);
        close_button_Led->setObjectName(QStringLiteral("close_button_Led"));
        close_button_Led->setGeometry(QRect(170, 140, 93, 28));
        open_button_Led = new QPushButton(Widget);
        open_button_Led->setObjectName(QStringLiteral("open_button_Led"));
        open_button_Led->setGeometry(QRect(20, 140, 93, 28));
        serial_label_2 = new QLabel(Widget);
        serial_label_2->setObjectName(QStringLiteral("serial_label_2"));
        serial_label_2->setGeometry(QRect(340, 0, 72, 31));
        textEdit_Send = new QTextEdit(Widget);
        textEdit_Send->setObjectName(QStringLiteral("textEdit_Send"));
        textEdit_Send->setGeometry(QRect(30, 230, 871, 111));
        baud_label_2 = new QLabel(Widget);
        baud_label_2->setObjectName(QStringLiteral("baud_label_2"));
        baud_label_2->setGeometry(QRect(30, 190, 72, 31));
        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(310, 30, 591, 131));
        SwitchFilepushButton = new QPushButton(Widget);
        SwitchFilepushButton->setObjectName(QStringLiteral("SwitchFilepushButton"));
        SwitchFilepushButton->setGeometry(QRect(30, 370, 93, 28));
        showTextpathEdit = new QPlainTextEdit(Widget);
        showTextpathEdit->setObjectName(QStringLiteral("showTextpathEdit"));
        showTextpathEdit->setGeometry(QRect(180, 370, 471, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        serial_label->setText(QApplication::translate("Widget", "TextLabel", nullptr));
        serial_box->setItemText(0, QApplication::translate("Widget", "COM1", nullptr));
        serial_box->setItemText(1, QApplication::translate("Widget", "COM2", nullptr));

        baud_label->setText(QApplication::translate("Widget", "TextLabel", nullptr));
        baud_box->setItemText(0, QApplication::translate("Widget", "9600", nullptr));
        baud_box->setItemText(1, QApplication::translate("Widget", "115200", nullptr));

        open_button->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        close_button->setText(QApplication::translate("Widget", "\345\205\263\351\227\255\344\270\262\345\217\243", nullptr));
        close_button_Led->setText(QApplication::translate("Widget", "\345\205\263\351\227\255LED", nullptr));
        open_button_Led->setText(QApplication::translate("Widget", "\346\211\223\345\274\200LED", nullptr));
        serial_label_2->setText(QApplication::translate("Widget", "\346\216\245\346\224\266\347\252\227\345\217\243", nullptr));
        baud_label_2->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\347\252\227\345\217\243", nullptr));
        SwitchFilepushButton->setText(QApplication::translate("Widget", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
