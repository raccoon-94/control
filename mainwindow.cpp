#include "mainwindow.h"
#include "ui_mainwindow.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    desktop = QApplication::desktop();

    main_addr = ui->lineEdit_2->text();
    main_port = ui->lineEdit_3->text();

    count_number_1=0;
    count_number_2=0;

    fc1 = new form_command_1;
    fc2 = new form_command_2;
    fc3 = new form_command_3;
    fc4 = new form_command_4;
    fc5 = new form_command_5;
    fc6 = new form_command_6;
    fc7 = new form_command_7;
    fc8 = new form_command_8;
    fc9 = new form_command_9;
    fc10 = new form_command_10;
    fc11 = new form_command_11;
    fc12 = new form_command_12;
    fc13 = new form_command_13;
    fc14 = new form_command_14;
    fc15 = new form_command_15;
    fc16 = new form_command_16;
    fc17 = new form_command_17;
    connect(fc1, SIGNAL(sendData_1(QString,int)), this, SLOT(recieveData_1(QString,int)));
    connect(fc2, SIGNAL(sendData_2(QString,int)), this, SLOT(recieveData_2(QString,int)));
    connect(fc3, SIGNAL(sendData_3(QString,int,QString)), this, SLOT(recieveData_3(QString,int,QString)));
    connect(fc4, SIGNAL(sendData_4(QString,int,int,int,int,int,int,int)), this, SLOT(recieveData_4(QString,int,int,int,int,int,int,int)));
    connect(fc5, SIGNAL(sendData_5(QString,int,int,int,int,QString,int,int,int,int)), this, SLOT(recieveData_5(QString,int,int,int,int,QString,int,int,int,int)));
    connect(fc6, SIGNAL(sendData_6(QString,int,int,int,int,QString,int)), this, SLOT(recieveData_6(QString,int,int,int,int,QString,int)));
    connect(fc7, SIGNAL(sendData_7(QString,int,int,int,int,int)), this, SLOT(recieveData_7(QString,int,int,int,int,int)));
    connect(fc8, SIGNAL(sendData_8(QString,int,int,int,int,int,int,int,int)), this, SLOT(recieveData_8(QString,int,int,int,int,int,int,int,int)));
    connect(fc9, SIGNAL(sendData_9(QString,int,int,int,int,int,int)), this, SLOT(recieveData_9(QString,int,int,int,int,int,int)));
    connect(fc10, SIGNAL(sendData_10(QString,int,int,int,int,QString,int)), this, SLOT(recieveData_10(QString,int,int,int,int,QString,int)));
    connect(fc11, SIGNAL(sendData_11(QString,int,int,int,int,int,int,int)), this, SLOT(recieveData_11(QString,int,int,int,int,int,int,int)));
    connect(fc12, SIGNAL(sendData_12(QString,int,int,QString)), this, SLOT(recieveData_12(QString,int,int,QString)));
    connect(fc13, SIGNAL(sendData_13(QString,int)), this, SLOT(recieveData_13(QString,int)));
    connect(fc14, SIGNAL(sendData_14(QString,int,int)), this, SLOT(recieveData_14(QString,int,int)));
    connect(fc15, SIGNAL(sendData_15(QString,int,int,int,int,int)), this, SLOT(recieveData_15(QString,int,int,int,int,int)));
    connect(fc16, SIGNAL(sendData_16(QString,int,int)), this, SLOT(recieveData_16(QString,int,int)));
    connect(fc17, SIGNAL(sendData_17(QString,int)), this, SLOT(recieveData_17(QString,int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::LowToUp(QByteArray ret){
    QString hex_view = ret.toHex();

    QString app;
    for(int i=0;i<hex_view.size();i+=2){
        app.append(hex_view[i]);
        app.append(hex_view[i+1]);
        app.append(" ");
    }
    return app.toUpper();
}

QString MainWindow::type_ksl_ret(int type_ksl){
    switch (type_ksl) {
    case 0x01:
        return "Группа для совмещенного контроля";
        break;
    case 0x11:
        return "Группа для раздельного контроля";
        break;
    default:
        QByteArray ret;
        ret.append(type_ksl);
        return ("Тест: "+ret.toHex().toUpper());
        break;
    }

}

QString MainWindow::type_control_ret(int type_control){
    switch (type_control) {
    case 0x01:
        return "Абонент данной станции";
        break;
    case 0x02:
        return "Сеть, полный номер";
        break;
    case 0x12:
        return "Сеть, неполный номер";
        break;
    case 0x03:
        return "Пучок вх. каналов";
        break;
    default:
        QByteArray ret;
        ret.append(type_control);
        return ("Тест: "+ret.toHex().toUpper());
        break;
    }
}

QString MainWindow::sign_number_ret(int sign_number){
    switch (sign_number) {
    case 0x01:
        return "Абонент данного узла";
        break;
    case 0x04:
        return "Абонент России";
        break;
    case 0x05:
        return "Абонент другой страны";
        break;
    case 0x06:
        return "Номер спец служб";
        break;
    case 0x07:
        return "GSM";
        break;
    case 0xff:
        return "Ничего: 0xFF";
        break;
    default:
        QByteArray ret;
        ret.append(sign_number);
        return ("Тест: "+ret.toHex().toUpper());
        break;
    }
}
QString MainWindow::class_control_ret(int class_control){
    switch (class_control) {
    case 0x01:
        return "Совмещённый контроль";
        break;
    case 0x11:
        return "Раздельный контроль";
        break;
    case 0x02:
        return "Статический контроль";
        break;
    default:
        QByteArray ret;
        ret.append(class_control);
        return ("Тест: "+ret.toHex().toUpper());
        break;
    }

}


QString MainWindow::priority_flag_ret(int priority_flag){
    switch (priority_flag) {
    case 0x01:
        return "Приоритетный";
        break;
    case 0x02:
        return "Обычный";
        break;
    default:
        QByteArray ret;
        ret.append(priority_flag);
        return ("Тест: "+ret.toHex().toUpper());
        break;
    }

}
QTreeWidgetItem* MainWindow::AddParent(QByteArray ret){
    QTime time = QTime::currentTime();
    count_number_1++;
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);

    itm->setText(0, QString::number(count_number_1));
    itm->setText(1, time.toString());
    itm->setText(2, LowToUp(ret));

    return itm;
}

void MainWindow::addChild(QTreeWidgetItem* itm, QString value, QString property){
    QTreeWidgetItem *itm_c = new QTreeWidgetItem;
    QColor child_color_background;
    child_color_background.setRgb(230,230,230,255);
    itm_c->setText(1, value);
    itm_c->setText(2, property);

    itm_c->setBackgroundColor(1,child_color_background);
    itm_c->setBackgroundColor(2,child_color_background);

    itm->addChild(itm_c);
}

void MainWindow::on_pushButton_2_clicked()
{
    main_addr = ui->lineEdit_2->text();
    main_port = ui->lineEdit_3->text();
    client.udp_bind(main_addr,main_port);
}

void MainWindow::on_pushButton_clicked()
{
    client.say(QByteArray::fromHex(ui->lineEdit->text().toLatin1()),main_addr,main_port);


}



void MainWindow::on_action_1_triggered()
{
    fc1->show();
    fc1->setFixedSize(241,143);
    fc1->move(this->x()+this->width()/2-fc1->width()/2,this->y()+this->height()/2-fc1->height()/2);

}

void MainWindow::on_action_2_triggered()
{
    fc2->show();
    fc2->setFixedSize(241,144);
    fc2->move(this->x()+this->width()/2-fc2->width()/2,this->y()+this->height()/2-fc2->height()/2);
}

void MainWindow::recieveData_1(QString password, int number_sorm){
    fc1->close();
    QByteArray ret=com.command_1(password,number_sorm);
    client.say(ret,main_addr,main_port);

    QTreeWidgetItem *itm = AddParent(ret);

    addChild(itm,"Команда №1","Старт СОРМ");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);

}

void MainWindow::recieveData_2(QString password,int number_sorm){
    fc2->close();
    QByteArray ret=com.command_2(password,number_sorm);
    client.say(ret,main_addr,main_port);

    QTreeWidgetItem *itm = AddParent(ret);

    addChild(itm,"Команда №2","Стоп СОРМ");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);
}

void MainWindow::recieveData_3(QString password,int number_sorm,QString new_password){
    fc3->close();
    QByteArray ret = com.command_3(password,number_sorm,new_password);
    client.say(ret,main_addr,main_port);

    QTreeWidgetItem *itm = AddParent(ret);

    addChild(itm,"Команда №3","Изменение пароля");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);
    addChild(itm,"Новый пароль",new_password);
}


void MainWindow::on_action_3_triggered()
{
    fc3->show();
    fc3->setFixedSize(375,190);
    fc3->move(this->x()+this->width()/2-fc3->width()/2,this->y()+this->height()/2-fc3->height()/2);
}

void MainWindow::on_action_4_triggered()
{
    fc4->show();
    fc4->setFixedSize(345,439);
    fc4->move(this->x()+this->width()/2-fc4->width()/2,this->y()+this->height()/2-fc4->height()/2);
}


void MainWindow::recieveData_4(QString password,int number_sorm,
                                                int number_ksl,
                                                int type_ksl,
                                                int number_ksl_a,
                                                int number_ksl_b,
                                                int number_digital_a,
                                                int number_digital_b){
    QByteArray ret = com.command_4(password,number_sorm,number_ksl,type_ksl,number_ksl_a,number_ksl_b,number_digital_a,number_digital_b);
    fc4->close();
    client.say(ret,main_addr,main_port);

    QTreeWidgetItem *itm = AddParent(ret);

    addChild(itm,"Команда №4","Закрепление КСЛ за группой");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);

    addChild(itm,"Номер группы КСЛ",QString::number(number_ksl));

    addChild(itm,"Тип группы КСЛ",type_ksl_ret(type_ksl));


    addChild(itm,"Номер цифрового потока A",QString::number(number_digital_a));
    addChild(itm,"Номер КСЛ-A",QString::number(number_ksl_a));

    addChild(itm,"Номер цифрового потока B",QString::number(number_digital_b));
    addChild(itm,"Номер КСЛ-B",QString::number(number_ksl_b));
}

void MainWindow::on_action_5_triggered()
{
    fc5->show();
    fc5->setFixedSize(641,441);
    fc5->move(this->x()+this->width()/2-fc5->width()/2,this->y()+this->height()/2-fc5->height()/2);
}

void MainWindow::recieveData_5(QString password,int number_sorm,
                                                int number_control,
                                                int type_control,
                                                int sign_number,
                                                QString number,
                                                int number_tract,
                                                int class_control,
                                                int number_ksl,
                                                int priority_flag){
    fc5->close();
    QByteArray ret = com.command_5(password,number_sorm,number_control,type_control,sign_number,number,number_tract,class_control,number_ksl,priority_flag);
    client.say(ret,main_addr,main_port);

    QTreeWidgetItem *itm = AddParent(ret);
    addChild(itm,"Команда №5","Постановка объекта на контроль");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);
    addChild(itm,"Условный номер объекта контроля",QString::number(number_control));
    addChild(itm,"Тип объекта контроля",type_control_ret(type_control));
    addChild(itm,"Признак номера телефона",sign_number_ret(sign_number));
    addChild(itm,"Номер",number);
    addChild(itm,"Условный номер пучка каналов",QString::number(number_tract));
    addChild(itm,"Категория контроля",class_control_ret(class_control));
    addChild(itm,"Номер группы КСЛ",QString::number(number_ksl));
    addChild(itm,"Метка приоритета",priority_flag_ret(priority_flag));


}

void MainWindow::on_action_6_triggered()
{
     fc6->show();
     fc6->setFixedSize(579,455);
     fc6->move(this->x()+this->width()/2-fc6->width()/2,this->y()+this->height()/2-fc6->height()/2);
}

void MainWindow::recieveData_6(QString password,int number_sorm,
                                                int number_control,
                                                int type_control,
                                                int sign_number,
                                                QString number,
                                                int number_tract){
    fc6->close();
    QByteArray ret = com.command_6(password,number_sorm,number_control,type_control,sign_number,number,number_tract);
    client.say(ret,main_addr,main_port);
    QTreeWidgetItem *itm = AddParent(ret);
    addChild(itm,"Команда №6","Снятие объекта с контроля");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);
    addChild(itm,"Условный номер объекта контроля",QString::number(number_control));
    addChild(itm,"Тип объекта контроля",type_control_ret(type_control));
    addChild(itm,"Признак номера телефона",sign_number_ret(sign_number));
    addChild(itm,"Номер",number);
    addChild(itm,"Условный номер пучка каналов",QString::number(number_tract));
}


void MainWindow::on_action_7_triggered()
{
    fc7->show();
    fc7->setFixedSize(384,399);
    fc7->move(this->x()+this->width()/2-fc7->width()/2,this->y()+this->height()/2-fc7->height()/2);
}

void MainWindow::recieveData_7(QString password,int number_sorm,
                                                int number_call,
                                                int type_control,
                                                int number_control,
                                                int number_ksl){
    fc7->close();
    QByteArray ret = com.command_7(password,number_sorm,number_call,type_control,number_control,number_ksl);
    client.say(ret,main_addr,main_port);
    QTreeWidgetItem *itm = AddParent(ret);
    addChild(itm,"Команда №7","Подключение к разговорному тракту");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);
    addChild(itm,"Номер вызова",QString::number(number_call));
    addChild(itm,"Тип объекта контроля",type_control_ret(type_control));
    addChild(itm,"Условный номер объекта контроля",QString::number(number_control));
    addChild(itm,"Номер группы КСЛ",QString::number(number_ksl));
}

void MainWindow::on_action_8_triggered()
{
    fc8->show();
    fc8->setFixedSize(403,510);
    fc8->move(this->x()+this->width()/2-fc8->width()/2,this->y()+this->height()/2-fc8->height()/2);
}

void MainWindow::recieveData_8(QString password,int number_sorm,
                                                int number_call,
                                                int type_control,
                                                int number_control,
                                                int number_ksl_a,
                                                int number_ksl_b,
                                                int number_digital_a,
                                                int number_digital_b){
    fc8->close();
    QByteArray ret = com.command_8(password,number_sorm,number_call,type_control,number_control,number_ksl_a,number_ksl_b,number_digital_a,number_digital_b);
    client.say(ret,main_addr,main_port);
    QTreeWidgetItem *itm = AddParent(ret);
    addChild(itm,"Команда №8","Освобождение КСЛ");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);
    addChild(itm,"Номер вызова",QString::number(number_call));
    addChild(itm,"Тип объекта контроля",type_control_ret(type_control));
    addChild(itm,"Условный номер объекта контроля",QString::number(number_control));

    addChild(itm,"Номер цифрового потока A",QString::number(number_digital_a));
    addChild(itm,"Номер КСЛ-A",QString::number(number_ksl_a));

    addChild(itm,"Номер цифрового потока B",QString::number(number_digital_b));
    addChild(itm,"Номер КСЛ-B",QString::number(number_ksl_b));
}

void MainWindow::on_action_9_triggered()
{
    fc9->show();
    fc9->setFixedSize(320,302);
    fc9->move(this->x()+this->width()/2-fc9->width()/2,this->y()+this->height()/2-fc9->height()/2);
}

void MainWindow::recieveData_9(QString password,int number_sorm,
                                                int number_ksl,
                                                int number_ksl_a,
                                                int number_ksl_b,
                                                int number_digital_a,
                                                int number_digital_b){
    fc9->close();
    QByteArray ret = com.command_9(password,number_sorm,number_ksl,number_ksl_a,number_ksl_b,number_digital_a,number_digital_b);
    client.say(ret,main_addr,main_port);
    QTreeWidgetItem *itm = AddParent(ret);
    addChild(itm,"Команда №9","Исключение КСЛ из группы");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);
    addChild(itm,"Номер группы КСЛ",QString::number(number_ksl));
    addChild(itm,"Номер цифрового потока A",QString::number(number_digital_a));
    addChild(itm,"Номер КСЛ-A",QString::number(number_ksl_a));

    addChild(itm,"Номер цифрового потока B",QString::number(number_digital_b));
    addChild(itm,"Номер КСЛ-B",QString::number(number_ksl_b));
}

void MainWindow::on_action_10_triggered()
{
    fc10->show();
    fc10->setFixedSize(581,441);
    fc10->move(this->x()+this->width()/2-fc10->width()/2,this->y()+this->height()/2-fc10->height()/2);
}

void MainWindow::recieveData_10(QString password,int number_sorm,
                                                 int number_control,
                                                 int type_control,
                                                 int sign_number,
                                                 QString number,
                                                 int number_tract){
    fc10->close();
    QByteArray ret = com.command_10(password,number_sorm,number_control,type_control,sign_number,number,number_tract);
    client.say(ret,main_addr,main_port);
    QTreeWidgetItem *itm = AddParent(ret);
    addChild(itm,"Команда №10","Запрос на передачу данных об объектах контроля");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);
    addChild(itm,"Условный номер объекта контроля",QString::number(number_control));
    addChild(itm,"Тип объекта контроля",type_control_ret(type_control));
    addChild(itm,"Признак номера телефона",sign_number_ret(sign_number));
    addChild(itm,"Номер",number);
    addChild(itm,"Условный номер пучка каналов",QString::number(number_tract));
}

void MainWindow::on_action_11_triggered()
{
    fc11->show();
    fc11->setFixedSize(341,421);
    fc11->move(this->x()+this->width()/2-fc11->width()/2,this->y()+this->height()/2-fc11->height()/2);
}

void MainWindow::recieveData_11(QString password,int number_sorm,
                                                 int number_ksl,
                                                 int type_ksl,
                                                 int number_ksl_a,
                                                 int number_ksl_b,
                                                 int number_digital_a,
                                                 int number_digital_b){
    fc11->close();
    QByteArray ret = com.command_11(password,number_sorm,number_ksl,type_ksl,number_ksl_a,number_ksl_b,number_digital_a,number_digital_b);
    client.say(ret,main_addr,main_port);

    QTreeWidgetItem *itm = AddParent(ret);
    addChild(itm,"Команда №11","Запрос на передачу информации о соответствии между КСЛ и группами");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);
    addChild(itm,"Номер группы КСЛ",QString::number(number_ksl));
    addChild(itm,"Тип группы КСЛ",type_ksl_ret(type_ksl));
    addChild(itm,"Номер цифрового потока A",QString::number(number_digital_a));
    addChild(itm,"Номер КСЛ-A",QString::number(number_ksl_a));

    addChild(itm,"Номер цифрового потока B",QString::number(number_digital_b));
    addChild(itm,"Номер КСЛ-B",QString::number(number_ksl_b));

}

void MainWindow::on_action_12_triggered()
{
    fc12->show();
    fc12->setFixedSize(520,273);
    fc12->move(this->x()+this->width()/2-fc12->width()/2,this->y()+this->height()/2-fc12->height()/2);
}

void MainWindow::recieveData_12(QString password,int number_sorm,
                                                 int sign_number,
                                                 QString number){
    fc12->close();
    QByteArray ret = com.command_12(password,number_sorm,sign_number,number);
    client.say(ret,main_addr,main_port);
    QTreeWidgetItem *itm = AddParent(ret);
    addChild(itm,"Команда №12","Запрос на передачу списка услуг связи");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);
    addChild(itm,"Признак номера телефона",sign_number_ret(sign_number));
    addChild(itm,"Номер",number);


}

void MainWindow::on_action_13_triggered()
{
    fc13->show();
    fc13->setFixedSize(260,141);
    fc13->move(this->x()+this->width()/2-fc13->width()/2,this->y()+this->height()/2-fc13->height()/2);
}

void MainWindow::recieveData_13(QString password,int number_sorm){
    fc13->close();
    QByteArray ret=com.command_13(password,number_sorm);
    client.say(ret,main_addr,main_port);
    QTreeWidgetItem *itm = AddParent(ret);
    addChild(itm,"Команда №13","Прерывание выдачи сообщений на запросы содержимого таблиц");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);
}

void MainWindow::on_action_14_triggered()
{
    fc14->show();
    fc14->setFixedSize(281,171);
    fc14->move(this->x()+this->width()/2-fc14->width()/2,this->y()+this->height()/2-fc14->height()/2);
}

void MainWindow::recieveData_14(QString password,int number_sorm,
                                                 int number_test){
    fc14->close();
    QByteArray ret=com.command_14(password,number_sorm,number_test);
    client.say(ret,main_addr,main_port);
    QTreeWidgetItem *itm = AddParent(ret);
    addChild(itm,"Команда №14","Тестирование каналов передачи данных");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);
    addChild(itm,"Тест",QString::number(number_test));
}

void MainWindow::on_action_15_triggered()
{
    fc15->show();
    fc15->setFixedSize(353,382);
    fc15->move(this->x()+this->width()/2-fc15->width()/2,this->y()+this->height()/2-fc15->height()/2);
}

void MainWindow::recieveData_15(QString password,int number_sorm,
                                                 int number_control,
                                                 int class_control,
                                                 int number_ksl,
                                                 int priority_flag){
    fc15->close();
    QByteArray ret = com.command_15(password,number_sorm,number_control,class_control,number_ksl,priority_flag);
    client.say(ret,main_addr,main_port);
    QTreeWidgetItem *itm = AddParent(ret);
    addChild(itm,"Команда №15","Изменение параметров объекта контроля");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);
    addChild(itm,"Условный номер объекта контроля",QString::number(number_control));
    addChild(itm,"Категория контроля",class_control_ret(class_control));
    addChild(itm,"Номер группы КСЛ",QString::number(number_ksl));
    addChild(itm,"Метка приоритета",priority_flag_ret(priority_flag));

}

void MainWindow::on_action_16_triggered()
{
    fc16->show();
    fc16->setFixedSize(290,169);
    fc16->move(this->x()+this->width()/2-fc16->width()/2,this->y()+this->height()/2-fc16->height()/2);
}

void MainWindow::recieveData_16(QString password,int number_sorm,
                                                 int number_tract){
    fc16->close();
    QByteArray ret=com.command_16(password,number_sorm,number_tract);
    client.say(ret,main_addr,main_port);
    QTreeWidgetItem *itm = AddParent(ret);
    addChild(itm,"Команда №16","Запрос соответствия имени пучка каналов и его условного номера");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);
    addChild(itm,"Условный номер пучка каналов",QString::number(number_tract));
}

void MainWindow::on_action_17_triggered()
{
    fc17->show();
    fc17->setFixedSize(251,141);
    fc17->move(this->x()+this->width()/2-fc17->width()/2,this->y()+this->height()/2-fc17->height()/2);
}

void MainWindow::recieveData_17(QString password,int number_sorm){
    fc17->close();
    QByteArray ret=com.command_17(password,number_sorm);
    client.say(ret,main_addr,main_port);
    QTreeWidgetItem *itm = AddParent(ret);
    addChild(itm,"Команда №17","Запрос версии ПО узла связи");
    addChild(itm,"Номер СОРМ",QString::number(number_sorm));
    addChild(itm,"Пароль",password);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->treeWidget->clear();
    count_number_1=0;
}

void MainWindow::on_pushButton_4_clicked()
{
     ui->treeWidget_2->clear();
     count_number_2=0;
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if(!item->parent()){
        ui->tableWidget->clear();
        QTableWidget *itm = new QTableWidget();
        ui->tableWidget->setRowCount(item->childCount());
        ui->tableWidget->setItem();

    }
        //qDebug()<<item->childCount();
}
