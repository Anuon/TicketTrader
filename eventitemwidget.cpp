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

void EventItemWidget::setData(Event event){
    ui->eventNameLabel->setText(event.getName());
    ui->organizerLabel->setText("Organizer: " + event.getOrganizer());
    ui->eventCapacity->setText("Capacity: " + QString::number(event.getCapacity()) + "/TODO");
    ui->eventStartLabel->setText("Event starts: " + event.getDate_start());
    ui->eventEndLabel->setText("Event ends: " + event.getDate_end());
    ui->eventTicketPrice->setText("Price per ticket: " +  QString::number(event.getTicket_price()) + " credits");
    ui->placeLabel->setText("Where: " + event.getPlace());
    ui->addressLabel->setText("Address: " + event.getAddress());
}

void EventItemWidget::on_buyTicketButton_clicked()
{

}
