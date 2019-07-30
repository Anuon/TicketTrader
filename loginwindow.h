#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <mainwindow.h>
#include <registerwindow.h>
#include <databasehandler.h>
#include <QMessageBox>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

public: void openMainWindow(QString name);
  private: MainWindow *mainWindow;

public slots: void openRegisterWindow();
private: RegisterWindow *registerWindow;

public slots: void onLoginClicked();
    private:DatabaseHandler *database;

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
