#include "createeventwindow.h"
#include "ui_createeventwindow.h"

CreateEventWindow::CreateEventWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateEventWindow)
{
    ui->setupUi(this);
}

CreateEventWindow::~CreateEventWindow()
{
    delete ui;
}

void CreateEventWindow::on_pushButton_clicked()
{

}
