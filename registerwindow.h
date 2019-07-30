#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QMainWindow>
#include <databasehandler.h>
#include <mainwindow.h>
#include <QMessageBox>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();


public: void openMainWindow(QString user);
  private: MainWindow *mainWindow;

public slots: void closeRegisterWindow();
public slots: void registerUser();

private slots:
    void on_backButton_clicked();
    private:DatabaseHandler *database;

private:
    Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
