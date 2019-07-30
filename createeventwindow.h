#ifndef CREATEEVENTWINDOW_H
#define CREATEEVENTWINDOW_H

#include <QMainWindow>
#include "databasehandler.h"

namespace Ui {
class CreateEventWindow;
}

class CreateEventWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateEventWindow(QWidget *parent = nullptr);
    ~CreateEventWindow();
    void setUser(QString user);
    Event getEvent();
    void setToEditMode(Event event);

signals:
     void closed();

private slots:
    void on_pushButton_clicked();

private:
    bool editMode = false;
    Event *event;
    QString user;
    DatabaseHandler *database;
    Ui::CreateEventWindow *ui;
    void closeEvent(QCloseEvent *bar);
};

#endif // CREATEEVENTWINDOW_H
