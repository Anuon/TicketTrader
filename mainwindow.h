#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"

#include <string>
#include "databasehandler.h"
#include <QListWidgetItem>
#include "eventitemwidget.h"
#include "createeventwindow.h"

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

    void userLoggedIn(QString name);

    void addEvent(Event event);

private slots:
    void on_addNewItem_clicked();


private:
    User *user;
    Ui::MainWindow *ui;
    CreateEventWindow *createEventWindow;

};

#endif // MAINWINDOW_H
