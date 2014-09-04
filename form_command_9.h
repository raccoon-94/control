#ifndef FORM_COMMAND_9_H
#define FORM_COMMAND_9_H

#include <QWidget>
#include <commands.h>
#include <QTimer>
#include <QClipboard>
#include <QtGui/QKeyEvent>


namespace Ui {
class form_command_9;
}

class form_command_9 : public QWidget
{
    Q_OBJECT

public:
    explicit form_command_9(QWidget *parent = 0);
    ~form_command_9();

signals:
    void sendData_9(QString password,int number_sorm,
                                     int number_ksl,
                                     int number_ksl_a,
                                     int number_ksl_b,
                                     int number_digital_a,
                                     int number_digital_b);
protected:
    void keyPressEvent(QKeyEvent *);

private slots:
    void on_pushButton_2_clicked();



    void update_form();


    void on_toolButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::form_command_9 *ui;

    commands com;
    QTimer *timer;
    QClipboard *clipboard;
    QString password;
    int number_sorm;
    int number_ksl;
    int number_ksl_a;
    int number_ksl_b;
    int number_digital_a;
    int number_digital_b;

};

#endif // FORM_COMMAND_9_H
