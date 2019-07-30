#include "user.h"

User::User(QString name, int credits, QList<Event> events, QList<int> boughtTickets){
    this->name = name;
    this->credits = credits;
    this->events = events;
    this->boughtTickets = boughtTickets;
}

QString User::getLoggedUser(){
    return this->name;
}
void User::setLoggedUser(QString user){
    this->name = user;
}

int User::getCredits(){
    return this->credits;
}
void User::setCredits(int credits){
    this->credits = credits;
}

QList<Event> User::getEvents(){
    return this->events;
}

QList<int> User::getBoughtTickets(){
    return this->boughtTickets;
}
