#ifndef form_command_16_H
#define form_command_16_H

#include <QWidget>
#include "commands.h"
#include <QTimer>
#include <QClipboard>
#include <QtGui/QKeyEvent>

namespace Ui {
class form_command_16;
}

class form_command_16 : public QWidget
{
    Q_OBJECT

public:
    explicit form_command_16(QWidget *parent = 0);
    ~form_command_16();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


    void update_form();

    void on_toolButton_clicked();

signals:
    void sendData_16(QString password,int number_sorm,
                                      int number_tract);
protected:
    void keyPressEvent(QKeyEvent *);
private:
    Ui::form_command_16 *ui;
    commands com;
    QTimer *timer;
    QClipboard *clipboard;
    QString password;
    int number_sorm;
    int number_tract;
};

#endif // form_command_16_H
