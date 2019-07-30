#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(closeRegisterWindow()));
    connect(ui->registerButton, SIGNAL(clicked()), this, SLOT(registerUser()));
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::closeRegisterWindow(){
    close();
}

void RegisterWindow::openMainWindow(QString user){
    mainWindow = new MainWindow();
    mainWindow->userLoggedIn(user);
    mainWindow->show();
}

void RegisterWindow::registerUser(){
    database = new DatabaseHandler();
    QString name = ui->nameField->text();
    QString password = ui->passwordField->text();
    if(!database->verifyLoginInfo(name, password) &&
        database->addUserToDatabase(name, password)){
        openMainWindow(name);
        close();
    }else {
        QMessageBox msgBox;
        msgBox.setText("Failed to register");
        msgBox.exec();
    }
}

void RegisterWindow::on_backButton_clicked()
{

}
