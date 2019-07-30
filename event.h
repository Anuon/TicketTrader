#ifndef EVENT_H
#define EVENT_H

#include "QString"

class Event
{
public:
    Event(int id, QString name, QString organizer, QString description, QString date_start, QString date_end, int capacity, int ticket_price, QString place, QString address);

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
