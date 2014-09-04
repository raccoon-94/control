#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QTreeWidgetItem>
#include "udp_sock.h"
#include "commands.h"

#include <form_command_1.h>
#include <form_command_2.h>
#include <form_command_3.h>
#include <form_command_4.h>
#include <form_command_5.h>
#include <form_command_6.h>
#include <form_command_7.h>
#include <form_command_8.h>
#include <form_command_9.h>
#include <form_command_10.h>
#include <form_command_11.h>
#include <form_command_12.h>
#include <form_command_13.h>
#include <form_command_14.h>
#include <form_command_15.h>
#include <form_command_16.h>
#include <form_command_17.h>

#include <QTime>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QString LowToUp(QByteArray ret);
    QString type_ksl_ret(int type_ksl);
    QString type_control_ret(int type_control);
    QString sign_number_ret(int sign_number);
    QString class_control_ret(int class_control);
    QString priority_flag_ret(int priority_flag);
    QTreeWidgetItem* AddParent(QByteArray ret);
    void addChild(QTreeWidgetItem* itm, QString value, QString property);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();




    
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_action_1_triggered();

    void on_action_2_triggered();
    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

    void on_action_8_triggered();

    void on_action_9_triggered();

    void on_action_10_triggered();

    void on_action_11_triggered();

    void on_action_12_triggered();

    void on_action_13_triggered();

    void on_action_14_triggered();

    void on_action_15_triggered();

    void on_action_16_triggered();

    void on_action_17_triggered();


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

public slots:
    void recieveData_1(QString password, int number_sorm);

    void recieveData_2(QString password, int number_sorm);

    void recieveData_3(QString password, int number_sorm,
                       QString new_password);

    void recieveData_4(QString password,int number_sorm,
                                        int number_ksl,
                                        int type_ksl,
                                        int number_ksl_a,
                                        int number_ksl_b,
                                        int number_digital_a,
                                        int number_digital_b);

    void recieveData_5(QString password,int number_sorm,
                                        int number_control,
                                        int type_control,
                                        int sign_number,
                                        QString number,
                                        int number_tract,
                                        int class_control,
                                        int number_ksl,
                                        int priority_flag);

    void recieveData_6(QString password,int number_sorm,
                                        int number_control,
                                        int type_control,
                                        int sign_number,
                                        QString number,
                                        int number_tract);

    void recieveData_7(QString password,int number_sorm,
                                        int number_call,
                                        int type_control,
                                        int number_control,
                                        int number_ksl);

    void recieveData_8(QString password,int number_sorm,
                                        int number_call,
                                        int type_control,
                                        int number_control,
                                        int number_ksl_a,
                                        int number_ksl_b,
                                        int number_digital_a,
                                        int number_digital_b);

    void recieveData_9(QString password,int number_sorm,
                                        int number_ksl,
                                        int number_ksl_a,
                                        int number_ksl_b,
                                        int number_digital_a,
                                        int number_digital_b);

    void recieveData_10(QString password,int number_sorm,
                                        int number_control,
                                        int type_control,
                                        int sign_number,
                                        QString number,
                                        int number_tract);

    void recieveData_11(QString password,int number_sorm,
                                        int number_ksl,
                                        int type_ksl,
                                        int number_ksl_a,
                                        int number_ksl_b,
                                        int number_digital_a,
                                        int number_digital_b);

    void recieveData_12(QString password,int number_sorm,
                                        int sign_number,
                                        QString number);

    void recieveData_13(QString password,int number_sorm);

    void recieveData_14(QString password,int number_sorm,
                                        int number_test);

    void recieveData_15(QString password,int number_sorm,
                                        int number_control,
                                        int class_control,
                                        int number_ksl,
                                        int priority_flag);

    void recieveData_16(QString password,int number_sorm,int number_track);

    void recieveData_17(QString password,int number_sorm);

private:
    Ui::MainWindow *ui;
    UDP_sock client;

    QString main_addr;
    QString main_port;

    QDesktopWidget *desktop;

    commands com;



    form_command_1 *fc1;
    form_command_2 *fc2;
    form_command_3 *fc3;
    form_command_4 *fc4;
    form_command_5 *fc5;
    form_command_6 *fc6;
    form_command_7 *fc7;
    form_command_8 *fc8;
    form_command_9 *fc9;
    form_command_10 *fc10;
    form_command_11 *fc11;
    form_command_12 *fc12;
    form_command_13 *fc13;
    form_command_14 *fc14;
    form_command_15 *fc15;
    form_command_16 *fc16;
    form_command_17 *fc17;

    int count_number_1;
    int count_number_2;




};

#endif // MAINWINDOW_H
