#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLoggedUser(QString user){
    ui->loggedUserLabel->setText("Logged as: " + user);
}
void MainWindow::setCredits(int credits){
    ui->creditsLabel->setText("Credits: " + QString::number(credits));
}

void MainWindow::userLoggedIn(QString name){
    DatabaseHandler db = *new DatabaseHandler();
    User user = db.getUserInformation(name);
    this->user = &user;
    setLoggedUser(name);
    setCredits(this->user->getCredits());
    foreach(Event event, this->user->getEvents()){
        addEvent(event);
    }
}

void MainWindow::addEvent(Event event){
    QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
    EventItemWidget *eventItemWidget = new EventItemWidget;
    eventItemWidget->setData(event);
    listWidgetItem->setSizeHint(QSize(955, 100));
    ui->listWidget->addItem(listWidgetItem);
    ui->listWidget->setItemWidget(listWidgetItem, eventItemWidget);
}

void MainWindow::on_addNewItem_clicked()
{
    createEventWindow = new CreateEventWindow();
    createEventWindow->show();
}
