#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include  <QDir>
#include <QFileDialog>
#include <QTextCodec>
#include <QMimeDatabase>
#include <ActiveQt/QAxObject>
#include "ExcelEngine.h"
#include <QFile>
#include <QStringList>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QStringList serialNamePort;
    ui->setupUi(this);
    this->setWindowTitle("serial_led");




    /* 创建一个串口对象 */
     serialPort = new QSerialPort(this);
     /* 搜索所有可用串口 */
       foreach (const QSerialPortInfo &inf0, QSerialPortInfo::availablePorts()) {
           serialNamePort<<inf0.portName();
       }
       ui->serial_box->addItems(serialNamePort);

      connect(serialPort,&QSerialPort::readyRead,this,&Widget::display);

}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_open_button_clicked()
{


    serialPort->setPortName(ui->serial_box->currentText());
    serialPort->setBaudRate(ui->baud_box->currentText().toInt());
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);

    if(serialPort->open(QIODevice::ReadWrite)==true)
    {
       QMessageBox::information(this, "提示", "串口打开成功");
    }
    else
    {
      QMessageBox::information(this,"提示", "串口打开失败");
    }
}

void Widget::on_close_button_clicked()
{
    serialPort->close();
    QMessageBox::information(this, "提示", "串口关闭成功");
}


const uint8_t sendOpenLed[7] = {0xee,0x01,0x01,0xff,0xfc,0xff,0xff};
const uint8_t sendCloseLed[7] = {0xee,0x01,0x00,0xff,0xfc,0xff,0xff};
void Widget::on_close_button_Led_clicked()
{

    serialPort->write((const char*)sendOpenLed,7);
    QMessageBox::information(this, "提示", "串口发送点灯成功");
}

void Widget::on_open_button_Led_clicked()
{
  serialPort->write((const char*)sendCloseLed,7);
  QMessageBox::information(this, "提示", "串口发送关灯成功");
}



void Widget::on_textEdit_Recv_textChanged()
{



}

void Widget::anAlysisComData(QByteArray _buf,unsigned char* _pcBuff,int* _len)
{
    const char* ucpBuf = (const char*) _buf.data();

    if(ucpBuf[1] == 0x01 && ucpBuf[2] == 0x11)
    {
        _pcBuff[0] = 0x66;
        _pcBuff[1] = 0x00;
        *_len = 2;
    }
    else
    {
        *_len = 0;
    }

}

void Widget::ResponseComData(QByteArray _buf)
{
   const char* ucpBuf = (const char*)_buf.data();
   int slBuflen = _buf.size();
   serialPort->write(ucpBuf,slBuflen);

}



void Widget::display(void)
{
   static int cmd_pos = 0;
    QByteArray QByteArrayRecvComData;
    int slRecvComDataLen;
    int slDataPos = 0;
    uint32_t slFrameTail = 0;
    QByteArray QByteArrayRecvComVaildData;
      QByteArray QByteArrayResComData;
    uint32_t u32RecvComVaildDataLen = 0;
    QByteArray buftemp;
    QString framedata;
    unsigned char ucBuff[100];

    QByteArrayRecvComData = serialPort->readAll();

    unsigned char* ucPRecvComData = (unsigned char*)QByteArrayRecvComData.data();
    unsigned char ucGetData = 0;
    int slvaildlen = 0;

    slRecvComDataLen = QByteArrayRecvComData.size();
     qDebug("slRecvComDataLen :%d\n",slRecvComDataLen);
    while(slRecvComDataLen--)
    {
         ucGetData = ucPRecvComData[slDataPos++];
         qDebug("ucPRecvComData[%d] :%0x\n",slDataPos-1,ucGetData);
        if((ucGetData != 0xEE) && (cmd_pos == 0))
        {
            continue;
        }
        else
        {

            QByteArrayRecvComVaildData[cmd_pos++] = ucGetData;
            slFrameTail = ((slFrameTail<<8)|ucGetData);
            qDebug("-----QByteArrayRecvComVaildData[%d] :%0x\n",cmd_pos-1,ucGetData);
            if(slFrameTail == 0xFFFCFFFF)
            {
                cmd_pos = 0;
                break;
            }
        }
    }

    ucBuff[0] = 0xee;
    anAlysisComData(QByteArrayRecvComVaildData,&ucBuff[1],&slvaildlen);
    slvaildlen += 1;
    ucBuff[slvaildlen++] = 0xff;
    ucBuff[slvaildlen++] = 0xfc;
    ucBuff[slvaildlen++] = 0xff;
    ucBuff[slvaildlen++] = 0xff;
    for(int i = 0;i<slvaildlen;i++)
    {

          QByteArrayResComData[i] = ucBuff[i];
          qDebug("QByteArrayResComData[%d] :%0x\n",i,ucBuff[i]);
    }

    ResponseComData(QByteArrayResComData);



#if 0

    int size = buf.size();
    uint32_t tail = 0;
    qDebug("bufsize :%d\n",size);
    //buftemp.resize(size+1);
    int pos = 0;
    unsigned char* p = (unsigned char*)buf.data();
    while(size--)
    {

          qDebug("-----p[%d] :%0x\n",pos,p[pos++]);
          if(((uint8_t)p[size] != 0xee) && (cmd_pos == 0))
          {
              continue;
          }
         // else
         // {
qDebug("p[%d] :%0x\n",size,p[size]);
                buftemp[cmd_pos++] = p[size];
                tail = ((tail<<8)|p[size]);
                if(tail == 0xfffcffff)
                {
                  //  break;
                }
        //  }
    }
#endif


# if 0
   if(!buf.isEmpty())
   {
       framedata = QString(buf);
       framedata = QString::fromLocal8Bit(buf);

       // ui->plainTextEdit->appendPlainText(buf.toHex().toUpper());

      // ui->plainTextEdit->setPlainText()


       ui->plainTextEdit->setPlainText(framedata);
   }
#endif


}

void Widget::on_textEdit_Send_textChanged()
{
      serialPort->write(ui->textEdit_Send->toPlainText().toLocal8Bit().data());
      QMessageBox::information(this, "提示", "串口发送数据成功");
}

void Widget::on_plainTextEdit_textChanged()
{


}



void Widget::on_SwitchFilepushButton_clicked()
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "打开文件";
    QString filter = "文本文件(*.txt);;二进制文件(*.bin *.dat);;所有文件(*.*)"; //文件过滤器
    QString filepath = QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
    QFileInfo fileinfo(filepath);
    if (filepath.isEmpty())
    {
        QMessageBox::warning(this,"警告","文件为空");
        return;
    }
  ui->showTextpathEdit->clear();
  ui->showTextpathEdit->appendPlainText(filepath);

  QFile file(filepath);
  if (!file.exists())
  {
      QMessageBox::warning(this,"警告","文件不存在");
      return;
  }
  if (!file.open(QIODevice::ReadOnly))
  {
      QMessageBox::warning(this,"警告","文件打开失败");
      return;
  }



  /* 设置应用程序的编码解码器 */
  QTextCodec *codec = QTextCodec::codecForName("UTF-8");
  QTextCodec::setCodecForLocale(codec);

  /*判断文件类型*/
  int type = 0;
  QMimeDatabase db;
  QMimeType mime = db.mimeTypeForFile(filepath);
  if (mime.name().startsWith("text/"))
  {
      type = 1;	//文本文件
       qDebug() << "文本文件";
  }
  else if (mime.name().startsWith("application/"))
  {
      type = 2;	//二进制文件
  }
  else
  {

  }
QString framedata;
  /*读取文件*/
  switch(type)
  {
      case 1:
      {
          //QIODevice读取普通文本
          QByteArray data = file.readAll();
          file.close();
          if (data.isEmpty())
          {
              QMessageBox::information(this, "提示", "文件内容空");
              return;
          }
          else
          {
              framedata = QString(data);
              framedata = QString::fromLocal8Bit(data);
              ui->plainTextEdit->setPlainText(framedata);
          }
          /* 判断编码 */
      }
      break;
      case 2:
      {

      }
      break;
  }

}

void Widget::on_showTextpathEdit_textChanged()
{

}
