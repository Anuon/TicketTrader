#ifndef USER_H
#define USER_H

#include "QString"
#include "QList"
#include "event.h"

class User
{
public:
    User(QString name, int credits, QList<Event> events);
    QString name;
    int credits;
    QList<Event> events;

    QString getLoggedUser();
    void setLoggedUser(QString user);

    int getCredits();
    void setCredits(int credits);

    QList<Event> getEvents();
};

#endif // USER_H
