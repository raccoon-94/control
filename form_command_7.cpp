#include "form_command_7.h"
#include "ui_form_command_7.h"

form_command_7::form_command_7(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_command_7)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_form()));
    timer->start(200);
    clipboard = QApplication::clipboard();
}

void form_command_7::update_form(){
    password = ui->lineEdit->text();
    number_sorm = ui->lineEdit_2->text().toInt();

    if(ui->radioButton->isChecked() == true){
        type_control = 0x01;
    }

    if(ui->radioButton_2->isChecked() == true){
        type_control = 0x02;
    }

    if(ui->radioButton_3->isChecked() == true){
        type_control = 0x12;
    }

    if(ui->radioButton_4->isChecked() == true){
        type_control = 0x03;
    }

    if(ui->radioButton_5->isChecked() == true){
        QByteArray t_c = QByteArray::fromHex(ui->lineEdit_6->text().toLatin1());
        memcpy(&type_control,t_c,sizeof(int));
    }


    number_control = ui->lineEdit_3->text().toInt();

    number_ksl = ui->lineEdit_4->text().toInt();
    number_call = ui->lineEdit_5->text().toInt();


    QByteArray ret = com.command_7(password,number_sorm,number_call,type_control,number_control,number_ksl);

    QString hex_view = ret.toHex();
    QString app;

    for(int i=0;i<hex_view.size();i+=2){
        app.append(hex_view[i]);
        app.append(hex_view[i+1]);
        app.append(" ");
    }

    ui->lineEdit_7->setText(app.toUpper());


}

form_command_7::~form_command_7()
{
    delete ui;
}

void form_command_7::on_pushButton_2_clicked()
{
    this->close();
}

void form_command_7::on_pushButton_clicked()
{
    emit sendData_7(password,number_sorm,number_call,type_control,number_control,number_ksl);
}



void form_command_7::on_toolButton_clicked()
{
    clipboard->setText(ui->lineEdit_7->text());
}

void form_command_7::keyPressEvent(QKeyEvent* event)
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

