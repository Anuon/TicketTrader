#include "createeventwindow.h"
#include "ui_createeventwindow.h"

int eventId = 0;

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
    database = new DatabaseHandler();
    QString name = ui->nameInput->text();
    QString organizer = database->getUserIdBasedOnName(this->user);
    QString description = ui->descriptionInput->toPlainText();
    QString date_start = ui->startDatePicker->text();
    QString date_end = ui->endDatePicker->text();
    int capacity = ui->capacityInput->text().toInt();
    int ticket_price = ui->priceInput->text().toInt();
    QString place = ui->placeInput->text();
    QString address = ui->adressInput->text();

    Event event = *new Event(eventId, name, organizer, description, date_start, date_end, capacity, ticket_price, place, address);
    this->event = &event;
    if(editMode){
         database->editEvent(event);
    }else{
         database->addNewEvent(event);
    }
    close();
}

void CreateEventWindow::setUser(QString user){
    this->user = user;
}

Event CreateEventWindow::getEvent(){
    return *this->event;
}

void CreateEventWindow::setToEditMode(Event event)
{
    editMode = true;
    ui->nameInput->setText(event.getName());
    ui->descriptionInput->setText(event.getDescription());
    ui->capacityInput->setText(QString::number(event.getCapacity()));
    ui->priceInput->setText(QString::number(event.getTicket_price()));
    ui->placeInput->setText(event.getPlace());
    ui->adressInput->setText(event.getAddress());
    eventId = event.getId();
}

void CreateEventWindow::closeEvent(QCloseEvent *bar){
    emit closed();
}
