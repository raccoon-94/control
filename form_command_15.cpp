#include "form_command_15.h"
#include "ui_form_command_15.h"

form_command_15::form_command_15(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_command_15)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_form()));
    timer->start(200);
    clipboard = QApplication::clipboard();

    priority_flag = 0x02;
}

form_command_15::~form_command_15()
{
    delete ui;
}

void form_command_15::update_form(){
    password = ui->lineEdit->text();
    number_sorm = ui->lineEdit_2->text().toInt();


    if(ui->radioButton_11->isChecked() == true){
        class_control = 0x01;
    }

    if(ui->radioButton_12->isChecked() == true){
        class_control = 0x11;
    }

    if(ui->radioButton_13->isChecked() == true){
        class_control = 0x02;
    }

    if(ui->radioButton->isChecked() == true){
        QByteArray c_c = QByteArray::fromHex(ui->lineEdit_4->text().toLatin1());
        memcpy(&class_control,c_c,sizeof(int));
    }

    number_control = ui->lineEdit_3->text().toInt();

    number_ksl = ui->lineEdit_6->text().toInt();


    QByteArray ret = com.command_15(password,number_sorm,number_control,class_control,number_ksl,priority_flag);

    QString hex_view = ret.toHex();
    QString app;

    for(int i=0;i<hex_view.size();i+=2){
        app.append(hex_view[i]);
        app.append(hex_view[i+1]);
        app.append(" ");
    }

    ui->lineEdit_7->setText(app.toUpper());



    if(ui->checkBox->isChecked()){
        priority_flag = 0x01;
    }



}

void form_command_15::on_pushButton_2_clicked()
{
    this->close();
}

void form_command_15::on_pushButton_clicked()
{
    emit sendData_15(password,number_sorm,number_control,class_control,number_ksl,priority_flag);
}

void form_command_15::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked()){
        priority_flag = 0x01;
    }else{
        priority_flag = 0x02;
    }

}



void form_command_15::on_toolButton_clicked()
{
    clipboard->setText(ui->lineEdit_7->text());
}

void form_command_15::keyPressEvent(QKeyEvent* event)
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
