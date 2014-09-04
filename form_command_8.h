#ifndef FORM_COMMAND_8_H
#define FORM_COMMAND_8_H

#include <QWidget>
#include <commands.h>
#include <QTimer>
#include <QClipboard>
#include <QtGui/QKeyEvent>

namespace Ui {
class form_command_8;
}

class form_command_8 : public QWidget
{
    Q_OBJECT

public:
    explicit form_command_8(QWidget *parent = 0);
    ~form_command_8();

signals:
    void sendData_8(QString password,int number_sorm,
                                     int number_call,
                                     int type_control,
                                     int number_control,
                                     int number_ksl_a,
                                     int number_ksl_b,
                                     int number_digital_a,
                                     int number_digital_b);
protected:
    void keyPressEvent(QKeyEvent *);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


    void update_form();

    void on_toolButton_clicked();

private:
    Ui::form_command_8 *ui;

    commands com;
    QTimer *timer;
    QClipboard *clipboard;
    QString password;
    int number_sorm;
    int number_call;
    int type_control;
    int number_control;
    int number_ksl_a;
    int number_ksl_b;
    int number_digital_a;
    int number_digital_b;

};

#endif // FORM_COMMAND_8_H
