#include "commands.h"

commands::commands(QObject *parent) :
    QObject(parent)
{
}
QByteArray commands::command_1(QString password,int number_sorm){
    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x01); // код команды 1 0x01
    ret[3]=0x00;  //4ый байт , длинна тела комнды, для 1ой равен 00
    for(int i=0;i<6;i++)
        ret.append(password[i].toLatin1());
    return ret;
}

QByteArray commands::command_2(QString password,int number_sorm){
    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x02); // код команды 2 0x02
    ret[3]=0x00;  //4ый байт , длинна тела комнды, для 2ой равен 00
    for(int i=0;i<6;i++)
        ret.append(password[i].toLatin1());
    return ret;

}

QByteArray commands::command_3(QString password,int number_sorm,QString new_password){
    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x03); // код команды 3 0x03
    ret[3]=0x06;  //4ый байт , длинна тела комнды, для 3ой равен 06
    for(int i=0;i<6;i++)
        ret.append(password[i].toLatin1());
    for(int i=0;i<6;i++)
        ret.append(new_password[i].toLatin1());

    return ret;
}

QByteArray commands::command_4(QString password,int number_sorm,
                                      int number_ksl,
                                      int type_ksl,
                                      int number_ksl_a,
                                      int number_ksl_b,
                                      int number_digital_a,
                                      int number_digital_b){
    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x04); // код команды 4 0x04
    ret[3]=0x04;  //4ый байт , длинна тела комнды, для 4ой равен 04
    for(int i=0;i<6;i++)
        ret.append(password[i].toLatin1());

    ret.append(number_ksl);
    ret.append(type_ksl);

    unsigned char ret_a = (number_ksl_a & 0x1F) | (( number_digital_a<<5)&0xE0);

    ret.append(ret_a);

    unsigned char ret_b = (number_ksl_b & 0x1F) | (( number_digital_b<<5)&0xE0);

    ret.append(ret_b);

    return ret;
}
QByteArray commands::command_5(QString password,int number_sorm,
                                      int number_control,
                                      int type_control,
                                      int sign_number,
                                      QString number,
                                      int number_tract,
                                      int class_control,
                                      int number_ksl,
                                      int priority_flag){
    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x05); // код команды 5 0x05
    ret[3]=19;  //4ый байт , длинна тела комнды, для 5ой равен 19
    for(int i=0;i<6;i++)                    //запись пароля
        ret.append(password[i].toLatin1());

    ret.append(number_control&0xFF);        //
    ret.append((number_control>>8)&0xFF);  //условный номер объекта контроля
    ret.append(type_control); //тип объекта контроля
    ret.append(sign_number); //признак номера телефона или объекта идентификатора

    ret.append(number.size());

    QByteArray num;
    num.clear();

    for(int i=0;i<18;i++){
        num.append(0xFF);
    }


    for(int i=0;i<number.size();i++){
        QString one_buf;
        one_buf.append(number.at(i));
        num[i]=(one_buf.toInt());

    }



    for(int i=0;i<(0+9);i++)
        ret.append(  (num[i*2]&0x0F ) | ((num[i*2+1]<<4)&0xF0) )    ;




    ret.append(number_tract&0xFF);        //
    ret.append((number_tract>>8)&0xFF);  //условный номер пучка каналов

    ret.append(class_control);
    ret.append(number_ksl);
    ret.append(priority_flag);


    return ret;
}

QByteArray commands::command_6(QString password,int number_sorm,
                                      int number_control,
                                      int type_control,
                                      int sign_number,
                                      QString number,
                                      int number_tract){
    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x06); // код команды 6 0x06
    ret[3]=16;  //4ый байт , длинна тела комнды, для 6ой равен 16
    for(int i=0;i<6;i++)                    //запись пароля
        ret.append(password[i].toLatin1());

    ret.append(number_control&0xFF);        //
    ret.append((number_control>>8)&0xFF);  //условный номер объекта контроля
    ret.append(type_control); //тип объекта контроля
    ret.append(sign_number); //признак номера телефона или объекта идентификатора

    ret.append(number.size());
    QByteArray num;
    num.clear();

    for(int i=0;i<18;i++){
        num.append(0xFF);
    }


    for(int i=0;i<number.size();i++){
        QString one_buf;
        one_buf.append(number.at(i));
        num[i]=(one_buf.toInt());

    }



    for(int i=0;i<(0+9);i++)
        ret.append(  (num[i*2]&0x0F ) | ((num[i*2+1]<<4)&0xF0) )    ;


    ret.append(number_tract&0xFF);        //
    ret.append((number_tract>>8)&0xFF);  //условный номер пучка каналов


    return ret;
}

QByteArray commands::command_7(QString password,int number_sorm,
                                      int number_call,
                                      int type_control,
                                      int number_control,
                                      int number_ksl){
    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x07); // код команды 7 0x07
    ret[3]=6;  //4ый байт , длинна тела комнды, для 7ой равен 6
    for(int i=0;i<6;i++)                    //запись пароля
        ret.append(password[i].toLatin1());

    ret.append(number_call&0xFF);        //
    ret.append((number_call>>8)&0xFF);  //номер вызова

    ret.append(type_control);

    ret.append(number_control&0xFF);        //
    ret.append((number_control>>8)&0xFF);  //условный номер объекта контроля

    ret.append(number_ksl); //номер группы  КСЛ

    return ret;

}

QByteArray commands::command_8(QString password, int number_sorm,
                                      int number_call,
                                      int type_control,
                                      int number_control,
                                      int number_ksl_a,
                                      int number_ksl_b, int number_digital_a, int number_digital_b){
    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x08); // код команды 8 0x08
    ret[3]=7;  //4ый байт , длинна тела комнды, для 8ой равен 7
    for(int i=0;i<6;i++)                    //запись пароля
        ret.append(password[i].toLatin1());

    ret.append(number_call&0xFF);        //
    ret.append((number_call>>8)&0xFF);  //номер вызова

    ret.append(type_control);           //тип объекта контроля

    ret.append(number_control&0xFF);        //
    ret.append((number_control>>8)&0xFF);  //условный номер объекта контроля

    unsigned char ret_a = (number_ksl_a & 0x1F) | (( number_digital_a<<5)&0xE0);

    ret.append(ret_a);

    unsigned char ret_b = (number_ksl_b & 0x1F) | (( number_digital_b<<5)&0xE0);

    ret.append(ret_b);

    return ret;

}

QByteArray commands::command_9(QString password,int number_sorm,
                                      int number_ksl,
                                      int number_ksl_a,
                                      int number_ksl_b,
                                      int number_digital_a,
                                      int number_digital_b){
    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x09); // код команды 9 0x09
    ret[3]=3;  //4ый байт , длинна тела комнды, для 9ой равен 3
    for(int i=0;i<6;i++)                    //запись пароля
        ret.append(password[i].toLatin1());

    ret.append(number_ksl);  //номер группы КСЛ

    unsigned char ret_a = (number_ksl_a & 0x1F) | (( number_digital_a<<5)&0xE0);

    ret.append(ret_a);

    unsigned char ret_b = (number_ksl_b & 0x1F) | (( number_digital_b<<5)&0xE0);

    ret.append(ret_b);

    return ret;

}

QByteArray commands::command_10(QString password,int number_sorm,
                                      int number_control,
                                      int type_control,
                                      int sign_number,
                                      QString number,
                                      int number_tract){
    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x0A); // код команды 10 0x0A
    ret[3]=16;  //4ый байт , длинна тела комнды, для 10ой равен 16
    for(int i=0;i<6;i++)                    //запись пароля
        ret.append(password[i].toLatin1());

    ret.append(number_control&0xFF);        //
    ret.append((number_control>>8)&0xFF);  //условный номер объекта контроля
    ret.append(type_control); //тип объекта контроля
    ret.append(sign_number); //признак номера телефона или объекта идентификатора

    ret.append(number.size());
    QByteArray num;
    num.clear();

    for(int i=0;i<18;i++){
        num.append(0xFF);
    }


    for(int i=0;i<number.size();i++){
        QString one_buf;
        one_buf.append(number.at(i));
        num[i]=(one_buf.toInt());

    }



    for(int i=0;i<(0+9);i++)
        ret.append(  (num[i*2]&0x0F ) | ((num[i*2+1]<<4)&0xF0) )    ;


    ret.append(number_tract&0xFF);        //
    ret.append((number_tract>>8)&0xFF);  //условный номер пучка каналов


    return ret;
}

QByteArray commands::command_11(QString password,int number_sorm,
                                      int number_ksl,
                                      int type_ksl,
                                      int number_ksl_a,
                                      int number_ksl_b,
                                      int number_digital_a,
                                      int number_digital_b){
    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x0B); // код команды 11 0x0B
    ret[3]=3;  //4ый байт , длинна тела комнды, для 11ой равен 4
    for(int i=0;i<6;i++)                    //запись пароля
        ret.append(password[i].toLatin1());

    ret.append(number_ksl);  //номер группы КСЛ
    ret.append(type_ksl);   //тип группы КСЛ

    unsigned char ret_a = (number_ksl_a & 0x1F) | (( number_digital_a<<5)&0xE0);

    ret.append(ret_a);

    unsigned char ret_b = (number_ksl_b & 0x1F) | (( number_digital_b<<5)&0xE0);

    ret.append(ret_b);

    return ret;

}

QByteArray commands::command_12(QString password,int number_sorm,
                                      int sign_number,
                                      QString number){
    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x0C); // код команды 12 0x0C
    ret[3]=11;  //4ый байт , длинна тела комнды, для 12ой равен 11
    for(int i=0;i<6;i++)                    //запись пароля
        ret.append(password[i].toLatin1());

    ret.append(sign_number);

    ret.append(number.size());
    QByteArray num;
    num.clear();

    for(int i=0;i<18;i++){
        num.append(0xFF);
    }


    for(int i=0;i<number.size();i++){
        QString one_buf;
        one_buf.append(number.at(i));
        num[i]=(one_buf.toInt());

    }

    for(int i=0;i<(0+9);i++)
        ret.append(  (num[i*2]&0x0F ) | ((num[i*2+1]<<4)&0xF0) )    ;


    return ret;
}

QByteArray commands::command_13(QString password,int number_sorm){

    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x0D); // код команды 13 0x0D
    ret[3]=0;  //4ый байт , длинна тела комнды, для 13ой равен 0
    for(int i=0;i<6;i++)                    //запись пароля
        ret.append(password[i].toLatin1());

    return ret;
}

QByteArray commands::command_14(QString password,int number_sorm,
                                                 int number_test){

    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x0E); // код команды 14 0x0E
    ret[3]=1;  //4ый байт , длинна тела комнды, для 14ой равен 1
    for(int i=0;i<6;i++)                    //запись пароля
        ret.append(password[i].toLatin1());
    ret.append(number_test);

    return ret;
}


QByteArray commands::command_15(QString password,int number_sorm,
                                       int number_control,
                                       int class_control,
                                       int number_ksl,
                                       int priority_flag){
    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x0F); // код команды 15 0x0F
    ret[3]=5;  //4ый байт , длинна тела комнды, для 15ой равен 5
    for(int i=0;i<6;i++)                    //запись пароля
        ret.append(password[i].toLatin1());

    ret.append(number_control&0xFF);        //
    ret.append((number_control>>8)&0xFF);  //условный номер объекта контроля

    ret.append(class_control);
    ret.append(number_ksl);
    ret.append(priority_flag);

    return ret;
}

QByteArray commands::command_16(QString password, int number_sorm,
                                                  int number_tract){
    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x10); // код команды 16 0x10
    ret[3]=2;  //4ый байт , длинна тела комнды, для 16ой равен 2
    for(int i=0;i<6;i++)                    //запись пароля
        ret.append(password[i].toLatin1());
    ret.append(number_tract&0xFF);        //
    ret.append((number_tract>>8)&0xFF);  //условный номер пучка каналов

    return ret;

}

QByteArray commands::command_17(QString password, int number_sorm){
    QByteArray ret;
    ret.append(0xCC);//преамбула СС
    ret.append(number_sorm); //номер СОРМ
    ret.append(0x11); // код команды 17 0x11
    ret[3]=0;  //4ый байт , длинна тела комнды, для 17ой равен 0
    for(int i=0;i<6;i++)                    //запись пароля
        ret.append(password[i].toLatin1());

    return ret;

}



