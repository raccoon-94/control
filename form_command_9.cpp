#include "form_command_9.h"
#include "ui_form_command_9.h"

form_command_9::form_command_9(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_command_9)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_form()));
    timer->start(200);
    clipboard = QApplication::clipboard();
}

form_command_9::~form_command_9()
{
    delete ui;
}

void form_command_9::update_form(){
    password = ui->lineEdit->text();
    number_sorm = ui->lineEdit_2->text().toInt();





    number_ksl_a = ui->lineEdit_10->text().toInt();
    number_ksl_b = ui->lineEdit_11->text().toInt();
    number_digital_a = ui->lineEdit_8->text().toInt();
    number_digital_b = ui->lineEdit_9->text().toInt();
    number_ksl = ui->lineEdit_5->text().toInt();


    QByteArray ret = com.command_9(password,number_sorm,number_ksl,number_ksl_a,number_ksl_b,number_digital_a,number_digital_b);

    QString hex_view = ret.toHex();
    QString app;

    for(int i=0;i<hex_view.size();i+=2){
        app.append(hex_view[i]);
        app.append(hex_view[i+1]);
        app.append(" ");
    }

    ui->lineEdit_7->setText(app.toUpper());


}

void form_command_9::on_pushButton_2_clicked()
{
    this->close();
}




void form_command_9::on_toolButton_clicked()
{
    clipboard->setText(ui->lineEdit_7->text());
}

void form_command_9::on_pushButton_clicked()
{

    emit sendData_9(password,number_sorm,number_ksl,number_ksl_a,number_ksl_b,number_digital_a,number_digital_b);
}

void form_command_9::keyPressEvent(QKeyEvent* event)
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
