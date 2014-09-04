#ifndef FORM_COMMAND_11_H
#define FORM_COMMAND_11_H

#include <QWidget>
#include "commands.h"
#include <QTimer>
#include <QClipboard>
#include <QtGui/QKeyEvent>


namespace Ui {
class form_command_11;
}

class form_command_11 : public QWidget
{
    Q_OBJECT

public:
    explicit form_command_11(QWidget *parent = 0);
    ~form_command_11();
private slots:


    void update_form();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_toolButton_clicked();

    void on_lineEdit_17_textEdited(const QString &arg1);

    void on_lineEdit_16_textEdited(const QString &arg1);

    void on_radioButton_14_clicked();

signals:
    void sendData_11(QString password,int number_sorm,
                                      int number_ksl,
                                      int type_ksl,
                                      int number_ksl_a,
                                      int number_ksl_b,
                                      int number_digital_a,
                                      int number_digital_b);
protected:
    void keyPressEvent(QKeyEvent *);
private:
    Ui::form_command_11 *ui;
    commands com;
    QTimer *timer;
    QClipboard *clipboard;
    QString password;
    int number_sorm;
    int number_ksl;
    int type_ksl;
    int number_ksl_a;
    int number_ksl_b;
    int number_digital_a;
    int number_digital_b;
};

#endif // FORM_COMMAND_11_H
