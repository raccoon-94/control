#include "form_command_4.h"
#include "ui_form_command_4.h"

form_command_4::form_command_4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_command_4)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_form()));
    timer->start(200);
    clipboard = QApplication::clipboard();
}

form_command_4::~form_command_4()
{
    delete ui;
}

void form_command_4::on_pushButton_2_clicked()
{
    this->close();
}

void form_command_4::on_pushButton_clicked()
{
    emit sendData_4(password,number_sorm,number_ksl,type_ksl,number_ksl_a,number_ksl_b,number_digital_a,number_digital_b);
}

void form_command_4::on_radioButton_clicked()
{
     ui->lineEdit_6->setText(ui->lineEdit_7->text());
     ui->lineEdit_5->setText(ui->lineEdit_4->text());
}

void form_command_4::on_radioButton_2_clicked()
{

}

void form_command_4::update_form(){

    password = ui->lineEdit_2->text();
    number_sorm = ui->lineEdit->text().toInt();
    number_ksl = ui->lineEdit_3->text().toInt();
    number_ksl_a = ui->lineEdit_4->text().toInt();
    number_ksl_b = ui->lineEdit_5->text().toInt();
    number_digital_a = ui->lineEdit_7->text().toInt();
    number_digital_b = ui->lineEdit_6->text().toInt();

    if(ui->radioButton->isChecked()){
        type_ksl=0x01;
    }
    if(ui->radioButton_2->isChecked()){
        type_ksl=0x11;
    }
    if(ui->radioButton_3->isChecked()){
        QByteArray t_k = QByteArray::fromHex(ui->lineEdit_9->text().toLatin1());
        memcpy(&type_ksl,t_k,sizeof(int));
    }

    QByteArray ret = com.command_4(password,number_sorm,number_ksl,type_ksl,number_ksl_a,number_ksl_b,number_digital_a,number_digital_b);

    QString hex_view = ret.toHex();
    QString app;

    for(int i=0;i<hex_view.size();i+=2){
        app.append(hex_view[i]);
        app.append(hex_view[i+1]);
        app.append(" ");
    }

    ui->lineEdit_8->setText(app.toUpper());

}



void form_command_4::on_toolButton_clicked()
{
    clipboard->setText(ui->lineEdit_8->text());
}

void form_command_4::keyPressEvent(QKeyEvent* event)
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

void form_command_4::on_lineEdit_7_textEdited(const QString &arg1)
{
    if(ui->radioButton->isChecked()){
        ui->lineEdit_6->setText(ui->lineEdit_7->text());
    }
}

void form_command_4::on_lineEdit_4_textEdited(const QString &arg1)
{
    if(ui->radioButton->isChecked()){
        ui->lineEdit_5->setText(ui->lineEdit_4->text());
    }
}
