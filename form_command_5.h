#ifndef FORM_COMMAND_5_H
#define FORM_COMMAND_5_H

#include <QWidget>
#include "commands.h"
#include <QTimer>
#include <QClipboard>
#include <QtGui/QKeyEvent>

namespace Ui {
class form_command_5;
}

class form_command_5 : public QWidget
{
    Q_OBJECT

public:
    explicit form_command_5(QWidget *parent = 0);
    ~form_command_5();

private slots:
    void update_form();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_checkBox_clicked();


    void on_toolButton_clicked();

signals:
    void sendData_5(QString password,int number_sorm,
                                     int number_control,
                                     int type_control,
                                     int sign_number,
                                     QString number,
                                     int number_tract,
                                     int class_control,
                                     int number_ksl,
                                     int priority_flag);
protected:
    void keyPressEvent(QKeyEvent *);

private:
    Ui::form_command_5 *ui;
    commands com;
    QTimer *timer;
    QClipboard *clipboard;
    QString password;
    int number_sorm;
    int number_control;
    int type_control;
    int sign_number;
    QString number;
    int number_tract;
    int class_control;
    int number_ksl;
    int priority_flag;
};

#endif // FORM_COMMAND_5_H
