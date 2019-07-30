#ifndef EVENT_H
#define EVENT_H

#include "QString"
#include "QDebug"

class Event
{
public:
    Event();
    Event(int id, QString name, QString organizer, QString description, QString date_start, QString date_end, int capacity, int ticket_price, QString place, QString address);

    int getId();
    QString getName();
    QString getOrganizer();
    QString getDescription();
    QString getDate_start();
    QString getDate_end();
    int getCapacity();
    int getTicket_price();
    QString getPlace();
    QString getAddress();

private:
    int id;
    QString name;
    QString organizer;
    QString description;
    QString date_start;
    QString date_end;
    int capacity;
    int ticket_price;
    QString place;
    QString address;
};

#endif // EVENT_H
