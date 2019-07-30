#include "loginwindow.h"
#include "ui_loginwindow.h"

#include "databasehandler.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    //Fields


    //Buttons
    connect(ui->loginButton, SIGNAL(clicked()), this, SLOT(onLoginClicked()));
    connect(ui->registerButton, SIGNAL(clicked()), this, SLOT(openRegisterWindow()));
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::onLoginClicked(){
    database = new DatabaseHandler();
    QString name = ui->nameField->text();
    QString password = ui->passwordField->text();
    if(database->verifyLoginInfo(name, password)){
        openMainWindow(name);
        close();
    }else {
        QMessageBox msgBox;
        msgBox.setText("Failed to login");
        msgBox.exec();
    }
}

void LoginWindow::openMainWindow(QString name){
    mainWindow = new MainWindow();
    mainWindow->userLoggedIn(name);
    mainWindow->show();
    close();
}

void LoginWindow::openRegisterWindow(){
    registerWindow = new RegisterWindow();
    registerWindow->show();
}
