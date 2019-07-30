#include "creditsformwindow.h"
#include "ui_creditsformwindow.h"

CreditsFormWindow::CreditsFormWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreditsFormWindow)
{
    ui->setupUi(this);
}

CreditsFormWindow::~CreditsFormWindow()
{
    delete ui;
}

void CreditsFormWindow::setType(QString type){
    this->type = type;
    ui->label->setText(type);
}

void CreditsFormWindow::setUser(QString credits, QString user){
    this->user = user;
    this->credits = credits;
}

int CreditsFormWindow::getResult(){
    return this->result;
}


void CreditsFormWindow::on_pushButton_clicked()
{
    close();
}

void CreditsFormWindow::on_pushButton_2_clicked()
{
      DatabaseHandler db = *new DatabaseHandler();
      int newCredits = credits.toInt();
      if(type == "Deposit"){
          newCredits += ui->lineEdit->text().toInt();
      }else{
          if(newCredits -= ui->lineEdit->text().toInt()){
              QMessageBox msgBox;
              msgBox.setText("You dont have enough credits");
              msgBox.exec();
              close();
              return;
          };
      }
      db.updateCredits(newCredits, user);
      this->result = newCredits;
      close();
}

void CreditsFormWindow::closeEvent(QCloseEvent *bar){
    emit closed();
}
