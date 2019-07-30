#include "event.h"



Event::Event(){

}

Event::Event(int id, QString name, QString organizer, QString description, QString date_start, QString date_end, int capacity, int ticket_price, QString place, QString address){
    //qDebug() << "Created new event: id: " << id << " name: " << name << " organizer: " << organizer << " description: " << description << " date_start: " << date_start << " date_end: " << date_end << " capacity: " << capacity << " ticket_price: " << ticket_price;
    this->id = id;
    this->name = name;
    this->organizer = organizer;
    this->description = description;
    this->date_start = date_start;
    this->date_end = date_end;
    this->capacity = capacity;
    this->ticket_price = ticket_price;
    this->place = place;
    this->address = address;
}

int Event::getId()
{
    return this->id;
}

QString Event::getName()
{
    return this->name;
}

QString Event::getOrganizer()
{
    return this->organizer;
}

QString Event::getDescription()
{
    return this->description;
}

QString Event::getDate_start()
{
    return this->date_start;
}

QString Event::getDate_end()
{
    return this->date_end;
}

int Event::getCapacity()
{
    return this->capacity;
}

int Event::getTicket_price()
{
    return this->ticket_price;
}

QString Event::getPlace()
{
    return this->place;
}

QString Event::getAddress()
{
    return this->address;
}

