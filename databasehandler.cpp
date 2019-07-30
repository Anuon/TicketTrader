#include "databasehandler.h"

DatabaseHandler::DatabaseHandler()
{

}

QSqlDatabase DatabaseHandler::connectToDatabase(){
    qDebug()<< "Trying to connect to database";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Anuon/Documents/TicketVendor/ticker_vendor.db");

    //qDebug() << QCoreApplication::applicationDirPath() + "/ticket_vendor.db";

   if(!db.open()){throw "Couldnt connect to database";}
    qDebug()<< "Succesfully connected to database";
    return db;
}

void DatabaseHandler::closeDatabaseConnection(QSqlDatabase db){
    db.close();
}

bool DatabaseHandler::verifyLoginInfo(QString name, QString password){
    QSqlDatabase db = connectToDatabase();
    QSqlQuery query;
    query.exec("SELECT name, password FROM users WHERE name='" + name + "' AND password='" + password + "'");
    closeDatabaseConnection(db);
    if(query.next()){
         return true;
    }
    return false;
}

bool DatabaseHandler::addUserToDatabase(QString name, QString password){
    QSqlDatabase db = connectToDatabase();
    QSqlQuery query;
    query.prepare("INSERT INTO users (name, password) VALUES (:name, :password)");
    query.bindValue(":name",name);
    query.bindValue(":password",password);
    bool insertSuccesful = query.exec();
    closeDatabaseConnection(db);
    return insertSuccesful;
}

QString DatabaseHandler::getUsernameBasedOnID(int id){
    QSqlDatabase db = connectToDatabase();
    QSqlQuery userQuery;
    userQuery.prepare("SELECT name FROM users WHERE id='" + QString::number(id) + "'");
    closeDatabaseConnection(db);
    while(userQuery.next()){
        return userQuery.value(0).toString();
    }
    return "";
}

User DatabaseHandler::getUserInformation(QString name){
    QSqlDatabase db = connectToDatabase();
    QSqlQuery userQuery;
    QSqlQuery eventQuery;
    userQuery.prepare("SELECT credits FROM users WHERE name='" + name + "'");
    eventQuery.prepare("SELECT id, events.name, users.name, description, date_start, date_end, capacity, ticket_price, place, address FROM events "
                       "INNER JOIN users ON events.organizer = users.userid");
    userQuery.exec();
    eventQuery.exec();
    int credits = 0;
    while(userQuery.next()){
          credits = userQuery.value(0).toInt();
    }
    QList<Event> events;
    while(eventQuery.next()){
        int id = eventQuery.value(0).toInt();
        QString name = eventQuery.value(1).toString();
        QString organizer = eventQuery.value(2).toString();
        QString description = eventQuery.value(3).toString();
        QString date_start = eventQuery.value(4).toString();
        QString date_end = eventQuery.value(5).toString();
        int capacity = eventQuery.value(6).toInt();
        int ticket_price = eventQuery.value(7).toInt();
        QString place = eventQuery.value(8).toString();
        QString address = eventQuery.value(9).toString();
        Event event = *new Event(id, name, organizer, description, date_start, date_end, capacity, ticket_price, place, address);
        events.append(event);
    }
    qDebug() << events.last().getName();
    closeDatabaseConnection(db);
    return *new User(name, credits, events);
}

bool DatabaseHandler::addNewEvent(Event event){
    QSqlDatabase db = connectToDatabase();
    QSqlQuery query;
    query.prepare("INSERT INTO events (name, organizer, description, date_start, date_end, capacity, ticket_price, place, address) "
                  "VALUES (:name, :organizer, :description, :date_start, :date_end, :capacity, :ticket_price, :place, :address)");
    query.bindValue(":name",event.getName());
    query.bindValue(":organizer",event.getOrganizer());
    query.bindValue(":description",event.getDescription());
    query.bindValue(":date_start",event.getDate_start());
    query.bindValue(":date_end",event.getDate_end());
    query.bindValue(":capacity",event.getCapacity());
    query.bindValue(":ticket_price",event.getTicket_price());
    query.bindValue(":place",event.getPlace());
    query.bindValue(":address",event.getAddress());
    bool insertSuccesful = query.exec();
    closeDatabaseConnection(db);
    return insertSuccesful;
}







