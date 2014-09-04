#include "form_command_8.h"
#include "ui_form_command_8.h"

form_command_8::form_command_8(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_command_8)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_form()));
    timer->start(200);
    clipboard = QApplication::clipboard();
}

void form_command_8::update_form(){
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
        type_control = 0xFF;
    }

    if(ui->radioButton_6->isChecked() == true){
        QByteArray t_c = QByteArray::fromHex(ui->lineEdit_4->text().toLatin1());
        memcpy(&type_control,t_c,sizeof(int));
    }


    number_control = ui->lineEdit_3->text().toInt();

    number_ksl_a = ui->lineEdit_10->text().toInt();
    number_ksl_b = ui->lineEdit_11->text().toInt();
    number_digital_a = ui->lineEdit_8->text().toInt();
    number_digital_b = ui->lineEdit_9->text().toInt();
    number_call = ui->lineEdit_5->text().toInt();


    QByteArray ret = com.command_8(password,number_sorm,number_call,type_control,number_control,number_ksl_a,number_ksl_b,number_digital_a,number_digital_b);

    QString hex_view = ret.toHex();
    QString app;

    for(int i=0;i<hex_view.size();i+=2){
        app.append(hex_view[i]);
        app.append(hex_view[i+1]);
        app.append(" ");
    }

    ui->lineEdit_7->setText(app.toUpper());


}

form_command_8::~form_command_8()
{
    delete ui;
}

void form_command_8::on_pushButton_2_clicked()
{
    this->close();
}

void form_command_8::on_pushButton_clicked()
{    
    emit sendData_8(password,number_sorm,number_call,type_control,number_control,number_ksl_a,number_ksl_b,number_digital_a,number_digital_b);
}



void form_command_8::on_toolButton_clicked()
{
    clipboard->setText(ui->lineEdit_7->text());
}

void form_command_8::keyPressEvent(QKeyEvent* event)
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
