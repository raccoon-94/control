#ifndef FORM_COMMAND_3_H
#define FORM_COMMAND_3_H

#include <QWidget>
#include "commands.h"
#include <QTimer>
#include <QClipboard>
#include <QtGui/QKeyEvent>

namespace Ui {
class form_command_3;
}

class form_command_3 : public QWidget
{
    Q_OBJECT
    
public:
    explicit form_command_3(QWidget *parent = 0);
    ~form_command_3();
    
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void update_form();



    void on_toolButton_clicked();

signals:
    void sendData_3(QString password,int number_sorm,QString new_password);
protected:
    void keyPressEvent(QKeyEvent *);

private:
    Ui::form_command_3 *ui;
    commands com;
    QTimer *timer;
    QClipboard *clipboard;
    QString password;
    int number_sorm;
    QString new_password;
};

#endif // FORM_COMMAND_3_H
