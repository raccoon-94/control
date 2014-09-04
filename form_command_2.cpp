#include "form_command_2.h"
#include "ui_form_command_2.h"

form_command_2::form_command_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_command_2)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_form()));
    timer->start(200);
    clipboard = QApplication::clipboard();
}

form_command_2::~form_command_2()
{
    delete ui;
}

void form_command_2::on_pushButton_clicked()
{

    emit sendData_2(password,number_sorm);
}

void form_command_2::on_pushButton_2_clicked()
{
    this->close();
}

void form_command_2::update_form(){
    password = ui->lineEdit_2->text();
    number_sorm = ui->lineEdit->text().toInt();
    QByteArray ret=com.command_2(password,number_sorm);
    QString hex_view = ret.toHex();
    QString app;

    for(int i=0;i<hex_view.size();i+=2){
        app.append(hex_view[i]);
        app.append(hex_view[i+1]);
        app.append(" ");
    }

    ui->lineEdit_3->setText(app.toUpper());

}


void form_command_2::keyPressEvent(QKeyEvent* event)
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

void form_command_2::on_toolButton_clicked()
{
    clipboard->setText(ui->lineEdit_3->text());
}
