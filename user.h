#ifndef USER_H
#define USER_H

#include "QString"
#include "QList"
#include "event.h"

class User
{
public:
    User(QString name, int credits, QList<Event> events, QList<int> boughtTickets);
    QString name;
    int credits;
    QList<Event> events;
    QList<int> boughtTickets;

    QString getLoggedUser();
    void setLoggedUser(QString user);

    int getCredits();
    void setCredits(int credits);

    QList<Event> getEvents();
    QList<int> getBoughtTickets();
};

#endif // USER_H
