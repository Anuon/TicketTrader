#include "mainwindow.h"
#include "ui_mainwindow.h"

QString username = "";

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

QString MainWindow::getCredits(){
    return ui->creditsLabel->text().split(" ").value(1);
}

void MainWindow::userLoggedIn(QString name){
    DatabaseHandler db = *new DatabaseHandler();
    User user = db.getUserInformation(name);
    username = user.getLoggedUser();
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
    eventItemWidget->setUser(username);
    eventItemWidget->setData(event);
    listWidgetItem->setSizeHint(QSize(955, 100));
    ui->listWidget->addItem(listWidgetItem);
    ui->listWidget->setItemWidget(listWidgetItem, eventItemWidget);
    connect(eventItemWidget, SIGNAL(refresh()), this, SLOT(refreshCredits()));
}

void MainWindow::refreshView(){
    DatabaseHandler db = *new DatabaseHandler();
    ui->listWidget->clear();
    foreach(Event event, db.getAllEvents()){
        addEvent(event);
    }
}

void MainWindow::on_addNewItem_clicked()
{
    createEventWindow = new CreateEventWindow(this);
    createEventWindow->setUser(username);
    createEventWindow->show();
    QEventLoop loop;
    connect(createEventWindow, SIGNAL(closed()), &loop, SLOT(quit()));
    loop.exec();
    refreshView();
}

void MainWindow::on_refreshButton_clicked()
{
    refreshView();
}

void MainWindow::on_depositButton_clicked()
{
    creditsFormWindow = new CreditsFormWindow(this);
    creditsFormWindow->setType("Deposit");
    creditsFormWindow->setUser(getCredits(), username);
    QEventLoop loop;
    connect(creditsFormWindow, SIGNAL(closed()), &loop, SLOT(quit()));
    creditsFormWindow->show();
    loop.exec();
    refreshCredits();
}

void MainWindow::on_withdrawButton_clicked()
{
    creditsFormWindow = new CreditsFormWindow(this);
    creditsFormWindow->setType("Withdraw");
    creditsFormWindow->setUser(getCredits(), username);
    creditsFormWindow->show();
    QEventLoop loop;
    connect(creditsFormWindow, SIGNAL(closed()), &loop, SLOT(quit()));
    loop.exec();
    refreshCredits();
}

void MainWindow::refreshCredits(){
    DatabaseHandler db = *new DatabaseHandler();
    setCredits(db.getCredits(username));
}
