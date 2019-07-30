#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"

#include <string>
#include "databasehandler.h"
#include <QListWidgetItem>
#include "eventitemwidget.h"
#include "createeventwindow.h"
#include "creditsformwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setLoggedUser(QString user);

    void setCredits(int credits);
    QString getCredits();

    void userLoggedIn(QString name);

    void addEvent(Event event);

    void refreshView();

public slots:
    void refreshCredits();

private slots:

    void on_addNewItem_clicked();


    void on_refreshButton_clicked();

    void on_depositButton_clicked();

    void on_withdrawButton_clicked();

private:
    User *user;
    Ui::MainWindow *ui;
    CreateEventWindow *createEventWindow;
    CreditsFormWindow *creditsFormWindow;
    int result;

};

#endif // MAINWINDOW_H
