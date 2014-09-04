#ifndef FORM_COMMAND_7_H
#define FORM_COMMAND_7_H

#include <QWidget>
#include <commands.h>
#include <QTimer>
#include <QClipboard>
#include <QtGui/QKeyEvent>

namespace Ui {
class form_command_7;
}

class form_command_7 : public QWidget
{
    Q_OBJECT

public:
    explicit form_command_7(QWidget *parent = 0);
    ~form_command_7();

signals:
    void sendData_7(QString password,int number_sorm,
                                     int number_call,
                                     int type_control,
                                     int number_control,
                                     int number_ksl);
protected:
    void keyPressEvent(QKeyEvent *);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


    void update_form();

    void on_toolButton_clicked();

private:
    Ui::form_command_7 *ui;

    commands com;
    QTimer *timer;
    QClipboard *clipboard;
    QString password;
    int number_sorm;
    int number_call;
    int type_control;
    int number_control;
    int number_ksl;

};

#endif // FORM_COMMAND_7_H
