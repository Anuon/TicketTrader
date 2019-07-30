#include "eventitemwidget.h"
#include "ui_eventitemwidget.h"

EventItemWidget::EventItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EventItemWidget)
{
    ui->setupUi(this);
}

EventItemWidget::~EventItemWidget()
{
    delete ui;
}

void EventItemWidget::setUser(QString user){
    this->user = user;
}

void EventItemWidget::setData(Event event){
    database = new DatabaseHandler();
    int attendees = database->getNumberOfUsersInEvent(event.getName());
    this->eventId = event.getId();
    this->event = event;
    this->ticket_price = event.getTicket_price();
    this->eventOrganizer = event.getOrganizer();
    ui->eventNameLabel->setText(event.getName());
    ui->organizerLabel->setText("Organizer: " + event.getOrganizer());
    ui->eventCapacity->setText("Capacity: " + QString::number(attendees)
                               + "/" +QString::number(event.getCapacity()));
    ui->eventStartLabel->setText("Event starts: " + event.getDate_start());
    ui->eventEndLabel->setText("Event ends: " + event.getDate_end());
    ui->eventTicketPrice->setText("Price per ticket: " +  QString::number(event.getTicket_price()) + " credits");
    ui->placeLabel->setText("Where: " + event.getPlace());
    ui->addressLabel->setText("Address: " + event.getAddress());
    User userPlaceholder = database->getUserInformation(this->user);
    if(database->getUserIdBasedOnName(userPlaceholder.getLoggedUser()) != database->getUserIdBasedOnName(event.getOrganizer())){
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_2->setVisible(false);
    }
    if(event.getCapacity() <= attendees){
        ui->pushButton->setEnabled(false);
        ui->pushButton->setText("Event is full");
    }
    else if(database->getUserIdBasedOnName(userPlaceholder.getLoggedUser()) == database->getUserIdBasedOnName(event.getOrganizer())){
        ui->pushButton->setEnabled(false);
        ui->pushButton->setText("You cannot buy ticket to your own event");
    }
    else if(userPlaceholder.getBoughtTickets().contains(event.getId())){
        ui->pushButton->setEnabled(false);
        ui->pushButton->setText("Ticket already bought");
    }else if(event.getTicket_price() > userPlaceholder.getCredits()){
        ui->pushButton->setEnabled(false);
        ui->pushButton->setText("Not enough credits for ticket");
    }

}

void EventItemWidget::on_pushButton_clicked()
{
    database = new DatabaseHandler();
    database->ticketBought(this->user, this->eventId);
    database->transferCredits(this->user, this->eventOrganizer, this->ticket_price);
    ui->pushButton->setEnabled(false);
    ui->pushButton->setText("Ticket already bought");
    emit refresh();
}

void EventItemWidget::on_pushButton_2_clicked()
{
    createEventWindow = new CreateEventWindow(this);
    createEventWindow->setUser(user);
    createEventWindow->setToEditMode(event);
    createEventWindow->show();
    QEventLoop loop;
    connect(createEventWindow, SIGNAL(closed()), &loop, SLOT(quit()));
    loop.exec();
    emit refresh();
}
