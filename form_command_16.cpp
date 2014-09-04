#include "form_command_16.h"
#include "ui_form_command_16.h"

form_command_16::form_command_16(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_command_16)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_form()));
    timer->start(200);
    clipboard = QApplication::clipboard();
}

form_command_16::~form_command_16()
{
    delete ui;
}

void form_command_16::on_pushButton_2_clicked()
{
    this->close();
}

void form_command_16::on_pushButton_clicked()
{
    emit sendData_16(password,number_sorm,number_tract);
}

void form_command_16::update_form(){
    password = ui->lineEdit_2->text();
    number_sorm = ui->lineEdit->text().toInt();
    number_tract = ui->lineEdit_4->text().toInt();
    QByteArray ret=com.command_16(password,number_sorm,number_tract);
    QString hex_view = ret.toHex();
    QString app;

    for(int i=0;i<hex_view.size();i+=2){
        app.append(hex_view[i]);
        app.append(hex_view[i+1]);
        app.append(" ");
    }

    ui->lineEdit_3->setText(app.toUpper());

}



void form_command_16::on_toolButton_clicked()
{
    clipboard->setText(ui->lineEdit_3->text());
}

void form_command_16::keyPressEvent(QKeyEvent* event)
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
