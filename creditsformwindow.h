#ifndef CREDITSFORMWINDOW_H
#define CREDITSFORMWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "databasehandler.h"
#include <QMessageBox>

namespace Ui {
class CreditsFormWindow;
}

class CreditsFormWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreditsFormWindow(QWidget *parent = nullptr);
    ~CreditsFormWindow();

    void setType(QString type);
    void setUser(QString credits, QString user);
    int getResult();
signals:
     void closed();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QString type;
    QString user;
    QString credits;
    int result;
    Ui::CreditsFormWindow *ui;
    void closeEvent(QCloseEvent *bar);
};

#endif // CREDITSFORMWINDOW_H
