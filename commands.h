#ifndef COMMANDS_H
#define COMMANDS_H

#include <QObject>

class commands : public QObject
{
    Q_OBJECT
public:
    explicit commands(QObject *parent = 0);
    QByteArray command_1(QString password,int number_sorm);
    QByteArray command_2(QString password,int number_sorm);
    QByteArray command_3(QString password,int number_sorm,
                                          QString new_password);
    QByteArray command_4(QString password,int number_sorm,
                                          int number_ksl,
                                          int type_ksl,
                                          int number_ksl_a,
                                          int number_ksl_b,
                                          int number_digital_a,
                                          int number_digital_b);
    QByteArray command_5(QString password,int number_sorm,
                                          int number_control,
                                          int type_control,
                                          int sign_number,
                                          QString number,
                                          int number_tract,
                                          int class_control,
                                          int number_ksl,
                                          int priority_flag);
    QByteArray command_6(QString password,int number_sorm,
                                          int number_control,
                                          int type_control,
                                          int sign_number,
                                          QString number,
                                          int number_tract);
    QByteArray command_7(QString password,int number_sorm,
                                          int number_call,
                                          int type_control,
                                          int number_control,
                                          int number_ksl);
    QByteArray command_8(QString password,int number_sorm,
                                          int number_call,
                                          int type_control,
                                          int number_control,
                                          int number_ksl_a,
                                          int number_ksl_b,
                                          int number_digital_a,
                                          int number_digital_b);
    QByteArray command_9(QString password,int number_sorm,
                                          int number_ksl,
                                          int number_ksl_a,
                                          int number_ksl_b,
                                          int number_digital_a,
                                          int number_digital_b);
    QByteArray command_10(QString password,int number_sorm,
                                          int number_control,
                                          int type_control,
                                          int sign_number,
                                          QString number,
                                          int number_tract);
    QByteArray command_11(QString password,int number_sorm,
                                          int number_ksl,
                                          int type_ksl,
                                          int number_ksl_a,
                                          int number_ksl_b,
                                          int number_digital_a,
                                          int number_digital_b);
    QByteArray command_12(QString password,int number_sorm,
                                          int sign_number,
                                          QString number);
    QByteArray command_13(QString password,int number_sorm);

    QByteArray command_14(QString password,int number_sorm,
                                           int number_test);

    QByteArray command_15(QString password,int number_sorm,
                                           int number_control,
                                           int class_control,
                                           int number_ksl,
                                           int priority_flag);

    QByteArray command_16(QString password,int number_sorm,
                                           int number_tract);

    QByteArray command_17(QString password,int number_sorm);



    
signals:
    
public slots:
    
};

#endif // COMMANDS_H
