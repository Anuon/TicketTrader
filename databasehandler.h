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
    User getUserInformation(QString name);
    bool addNewEvent(Event event);
};

#endif // DATABASEHANDLER_H
