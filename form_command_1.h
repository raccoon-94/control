#ifndef FORM_COMMAND_1_H
#define FORM_COMMAND_1_H

#include <QWidget>
#include "commands.h"
#include <QTimer>
#include <QClipboard>
#include <QtGui/QKeyEvent>

namespace Ui {
class form_command_1;
}

class form_command_1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit form_command_1(QWidget *parent = 0);
    ~form_command_1();
    
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();



    void update_form();

    void on_toolButton_clicked();

signals:
    void sendData_1(QString password,int number_sorm);
protected:
    void keyPressEvent(QKeyEvent *);

private:
    Ui::form_command_1 *ui;
    commands com;
    QTimer *timer;
    QClipboard *clipboard;
    QString password;
    int number_sorm;
};

#endif // FORM_COMMAND_1_H
