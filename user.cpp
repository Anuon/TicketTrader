#include "user.h"

User::User(QString name, int credits, QList<Event> events){
    this->name = name;
    this->credits = credits;
    this->events = events;
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
