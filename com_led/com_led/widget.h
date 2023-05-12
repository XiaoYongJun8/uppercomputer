#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget;
 class ExcelEngine


        ; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    ~Widget();
  void display(void);
  void ResponseComData(QByteArray _buf);
  void anAlysisComData(QByteArray _buf,unsigned char* _pcBuff,int* _len);
  QSerialPort *serialPort;

private slots:

    void on_open_button_clicked();

    void on_close_button_clicked();



    void on_close_button_Led_clicked();

    void on_open_button_Led_clicked();


    void on_textEdit_Recv_textChanged();

    void on_textEdit_Send_textChanged();

    void on_plainTextEdit_textChanged();



    void on_SwitchFilepushButton_clicked();

    void on_showTextpathEdit_textChanged();

 private:
    Ui::Widget *ui;

};
#endif // WIDGET_H
