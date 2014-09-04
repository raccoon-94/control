#include "form_command_3.h"
#include "ui_form_command_3.h"

form_command_3::form_command_3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_command_3)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_form()));
    timer->start(200);
    clipboard = QApplication::clipboard();
}

form_command_3::~form_command_3()
{
    delete ui;
}

void form_command_3::on_pushButton_2_clicked()
{
    this->close();
}

void form_command_3::on_pushButton_clicked()
{
     emit sendData_3(password,number_sorm,new_password);
}

void form_command_3::update_form(){
    password = ui->lineEdit_2->text();
    number_sorm = ui->lineEdit->text().toInt();
    new_password = ui->lineEdit_3->text();
    QByteArray ret=com.command_3(password,number_sorm,new_password);
    QString hex_view = ret.toHex();
    QString app;

    for(int i=0;i<hex_view.size();i+=2){
        app.append(hex_view[i]);
        app.append(hex_view[i+1]);
        app.append(" ");
    }

    ui->lineEdit_4->setText(app.toUpper());

}



void form_command_3::keyPressEvent(QKeyEvent* event)
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

void form_command_3::on_toolButton_clicked()
{
    clipboard->setText(ui->lineEdit_4->text());
}
