#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include<QtSql>
#include<QSqlDatabase>
#include<QString>

#include "user.h"

class DatabaseHandler
{
public:
    DatabaseHandler();

    QSqlDatabase connectToDatabase();
    void closeDatabaseConnection(QSqlDatabase db);
    bool verifyLoginInfo(QString name, QString password);
    bool addUserToDatabase(QString name, QString password);
    QString getUsernameBasedOnID(int id);
    QString getUserIdBasedOnName(QString name);
    User getUserInformation(QString name);
    int getNumberOfUsersInEvent(QString name);
    bool addNewEvent(Event event);
    bool editEvent(Event event);
    bool ticketBought(QString username, int eventId);
    QList<Event> getAllEvents();
    bool updateCredits(int credits, QString user);
    int transferCredits(QString sender, QString receiver, int amount);
    int getCredits(QString user);
};

#endif // DATABASEHANDLER_H
