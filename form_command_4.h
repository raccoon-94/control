#ifndef FORM_COMMAND_4_H
#define FORM_COMMAND_4_H

#include <QWidget>
#include "commands.h"
#include <QTimer>
#include <QClipboard>
#include <QtGui/QKeyEvent>

namespace Ui {
class form_command_4;
}

class form_command_4 : public QWidget
{
    Q_OBJECT
    
public:
    explicit form_command_4(QWidget *parent = 0);
    ~form_command_4();
    
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void update_form();


    void on_toolButton_clicked();

    void on_lineEdit_7_textEdited(const QString &arg1);

    void on_lineEdit_4_textEdited(const QString &arg1);

signals:
    void sendData_4(QString password,int number_sorm,
                                     int number_ksl,
                                     int type_ksl,
                                     int number_ksl_a,
                                     int number_ksl_b,
                                     int number_digital_a,
                                     int number_digital_b);
protected:
    void keyPressEvent(QKeyEvent *);

private:
    Ui::form_command_4 *ui;
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

#endif // FORM_COMMAND_4_H
