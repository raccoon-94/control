#ifndef FORM_COMMAND_6_H
#define FORM_COMMAND_6_H

#include <QWidget>
#include "commands.h"
#include <QTimer>
#include <QClipboard>
#include <QtGui/QKeyEvent>

namespace Ui {
class form_command_6;
}

class form_command_6 : public QWidget
{
    Q_OBJECT

public:
    explicit form_command_6(QWidget *parent = 0);
    ~form_command_6();
private slots:
    void update_form();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_toolButton_clicked();

signals:
    void sendData_6(QString password,int number_sorm,
                                     int number_control,
                                     int type_control,
                                     int sign_number,
                                     QString number,
                                     int number_tract);
protected:
    void keyPressEvent(QKeyEvent *);
private:
    Ui::form_command_6 *ui;
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

};

#endif // FORM_COMMAND_6_H
