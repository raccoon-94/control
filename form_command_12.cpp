#include "form_command_12.h"
#include "ui_form_command_12.h"

form_command_12::form_command_12(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_command_12)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_form()));
    timer->start(200);
    clipboard = QApplication::clipboard();
}

form_command_12::~form_command_12()
{
    delete ui;
}

void form_command_12::update_form(){
    password = ui->lineEdit->text();
    number_sorm = ui->lineEdit_2->text().toInt();

    if(ui->radioButton_5->isChecked() == true){
        sign_number = 0x01;
    }

    if(ui->radioButton_6->isChecked() == true){
        sign_number = 0x04;
    }

    if(ui->radioButton_7->isChecked() == true){
        sign_number = 0x05;
    }

    if(ui->radioButton_8->isChecked() == true){
        sign_number = 0x06;
    }

    if(ui->radioButton_9->isChecked() == true){
        sign_number = 0x07;
    }

    if(ui->radioButton_10->isChecked() == true){
        sign_number = 0xFF;
    }

    if(ui->radioButton->isChecked() == true){
        QByteArray s_n = QByteArray::fromHex(ui->lineEdit_3->text().toLatin1());
        memcpy(&sign_number,s_n,sizeof(int));
    }





    number = ui->lineEdit_4->text();


    QByteArray ret = com.command_12(password,number_sorm,sign_number,number);

    QString hex_view = ret.toHex();
    QString app;

    for(int i=0;i<hex_view.size();i+=2){
        app.append(hex_view[i]);
        app.append(hex_view[i+1]);
        app.append(" ");
    }

    ui->lineEdit_7->setText(app.toUpper());



}

void form_command_12::on_pushButton_2_clicked()
{
    this->close();
}

void form_command_12::on_pushButton_clicked()
{
    emit sendData_12(password,number_sorm,sign_number,number);
}





void form_command_12::on_toolButton_clicked()
{
    clipboard->setText(ui->lineEdit_7->text());
}

void form_command_12::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Escape){
        this->close();
        return;
    }
    if(event->key() == Qt::Key_Return){
        on_pushButton_clicked();
        return;
    }
}
