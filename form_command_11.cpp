#include "form_command_11.h"
#include "ui_form_command_11.h"

form_command_11::form_command_11(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_command_11)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_form()));
    timer->start(200);
    clipboard = QApplication::clipboard();
}

form_command_11::~form_command_11()
{
    delete ui;
}


void form_command_11::update_form(){

    password = ui->lineEdit_9->text();
    number_sorm = ui->lineEdit_8->text().toInt();
    number_ksl = ui->lineEdit_10->text().toInt();
    number_ksl_a = ui->lineEdit_16->text().toInt();
    number_ksl_b = ui->lineEdit_11->text().toInt();
    number_digital_a = ui->lineEdit_17->text().toInt();
    number_digital_b = ui->lineEdit_12->text().toInt();

    if(ui->radioButton_14->isChecked()){
        type_ksl=0x01;
    }

    if(ui->radioButton_15->isChecked()){
        type_ksl=0x11;
    }

    if(ui->radioButton->isChecked()){
        QByteArray t_k = QByteArray::fromHex(ui->lineEdit->text().toLatin1());
        memcpy(&type_ksl,t_k,sizeof(int));
    }

    QByteArray ret = com.command_11(password,number_sorm,number_ksl,type_ksl,number_ksl_a,number_ksl_b,number_digital_a,number_digital_b);

    QString hex_view = ret.toHex();
    QString app;

    for(int i=0;i<hex_view.size();i+=2){
        app.append(hex_view[i]);
        app.append(hex_view[i+1]);
        app.append(" ");
    }

    ui->lineEdit_15->setText(app.toUpper());



}


void form_command_11::on_pushButton_clicked()
{
    this->close();
}

void form_command_11::on_pushButton_2_clicked()
{
    emit sendData_11(password,number_sorm,number_ksl,type_ksl,number_ksl_a,number_ksl_b,number_digital_a,number_digital_b);
}



void form_command_11::on_toolButton_clicked()
{
    clipboard->setText(ui->lineEdit_15->text());
}

void form_command_11::on_lineEdit_17_textEdited(const QString &arg1)
{
    if(ui->radioButton_14->isChecked()){
        ui->lineEdit_12->setText(ui->lineEdit_17->text());
    }
}

void form_command_11::on_lineEdit_16_textEdited(const QString &arg1)
{
    if(ui->radioButton_14->isChecked()){
        ui->lineEdit_11->setText(ui->lineEdit_16->text());
    }
}

void form_command_11::on_radioButton_14_clicked()
{
    ui->lineEdit_11->setText(ui->lineEdit_16->text());
    ui->lineEdit_12->setText(ui->lineEdit_17->text());
}

void form_command_11::keyPressEvent(QKeyEvent* event)
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
