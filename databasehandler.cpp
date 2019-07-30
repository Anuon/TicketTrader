#include "databasehandler.h"

DatabaseHandler::DatabaseHandler()
{

}

QSqlDatabase DatabaseHandler::connectToDatabase(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Anuon/Documents/TicketVendor/ticket_vendor.db");

   if(!db.open()){throw "Couldnt connect to database";}
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

QString DatabaseHandler::getUserIdBasedOnName(QString name){
    QSqlDatabase db = connectToDatabase();
    QSqlQuery userQuery;
    userQuery.prepare("SELECT userid FROM users WHERE name='" + name + "'");
    userQuery.exec();
    closeDatabaseConnection(db);
    while(userQuery.next()){
        return userQuery.value(0).toString();
    }
    return "No user found";
}

QList<Event>DatabaseHandler::getAllEvents(){
    QSqlDatabase db = connectToDatabase();
    QSqlQuery eventQuery;
    eventQuery.prepare("SELECT id, events.name, users.name, description, date_start, date_end, capacity, ticket_price, place, address FROM events "
                       "INNER JOIN users ON events.organizer = users.userid");
    eventQuery.exec();
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
    closeDatabaseConnection(db);
    return events;
}

User DatabaseHandler::getUserInformation(QString name){
    QSqlDatabase db = connectToDatabase();
    QSqlQuery userQuery;
    QSqlQuery ticketsQuery;
    userQuery.prepare("SELECT userid, credits FROM users WHERE name='" + name + "'");
    userQuery.exec();
    int credits = 0;
    int userId = 0;
    while(userQuery.next()){
          userId = userQuery.value(0).toInt();
          credits = userQuery.value(1).toInt();
    }
    ticketsQuery.prepare("SELECT event_id FROM attendance WHERE user_id=" + QString::number(userId) + "");
    ticketsQuery.exec();
    QList<int> ids;
    while(ticketsQuery.next()){
          ids.append(ticketsQuery.value(0).toInt());
    }
    closeDatabaseConnection(db);
    return *new User(name, credits, getAllEvents(), ids);
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

bool DatabaseHandler::editEvent(Event event){
    QSqlDatabase db = connectToDatabase();
    QSqlQuery query;
    query.prepare("UPDATE events SET name = '"+ event.getName() +"', organizer = '" + event.getOrganizer() + "'"
                  ", description = '"+ event.getDescription() +"', date_start = '"+ event.getDate_start() +"'"
                  ", date_end = '"+ event.getDate_end() +"', capacity = '"+QString::number(event.getCapacity())+"', ticket_price = '"+QString::number(event.getCapacity())+"'"
                  ", place = '"+event.getPlace()+"', address = '"+event.getAddress()+"' WHERE id= "+QString::number(event.getId())+"");
    bool insertSuccesful = query.exec();
    closeDatabaseConnection(db);
    return insertSuccesful;
}

int DatabaseHandler::getNumberOfUsersInEvent(QString name){
    QSqlDatabase db = connectToDatabase();
    QSqlQuery query;
    query.prepare("SELECT COUNT(attendance.user_id) FROM attendance LEFT JOIN events ON attendance.event_id = events.id WHERE events.name = '" + name + "' ");
    query.exec();
    while(query.next()){
        return query.value(0).toInt();
    }
    closeDatabaseConnection(db);
    return 0;
}

bool DatabaseHandler::ticketBought(QString username, int eventId){
    QSqlDatabase db = connectToDatabase();
    QSqlQuery insertQuery;
    QSqlQuery selectQuery;
    selectQuery.exec("SELECT userid FROM users WHERE name = '" + username + "'");
    int userId = 0;
    while(selectQuery.next()){
        userId = selectQuery.value(0).toInt();
    }
    insertQuery.prepare("INSERT INTO attendance (user_id, event_id) VALUES (:user_id, :event_id)");
    insertQuery.bindValue(":user_id",userId);
    insertQuery.bindValue(":event_id",eventId);
    bool result = insertQuery.exec();
    closeDatabaseConnection(db);
    return result;
}

int DatabaseHandler::getCredits(QString user){
     QSqlDatabase db = connectToDatabase();
     QSqlQuery query;
     query.exec("SELECT credits FROM users WHERE name = '" + user + "'");
     while(query.next()){
         return query.value(0).toInt();
     }
     return 0;
}

int DatabaseHandler::transferCredits(QString sender, QString receiver, int amount){
    int senderCredits = getCredits(sender);
    int receiverCredits = getCredits(receiver);
    senderCredits -= amount;
    receiverCredits += amount;
    QSqlDatabase db = connectToDatabase();
    QSqlQuery senderQuery;
    QSqlQuery receiverQuery;
    senderQuery.prepare("UPDATE users SET credits = " + QString::number(senderCredits) + " WHERE users.name = '" + sender + "'");
    senderQuery.exec();
    receiverQuery.prepare("UPDATE users SET credits = " + QString::number(receiverCredits) + " WHERE users.name = '" + receiver + "'");
    receiverQuery.exec();
    closeDatabaseConnection(db);
    return senderCredits;
}

bool DatabaseHandler::updateCredits(int newCredits, QString user){
    QSqlDatabase db = connectToDatabase();
    QSqlQuery query;
    query.prepare("UPDATE users SET credits = " + QString::number(newCredits) + " WHERE users.name = '" + user + "'");
    bool result = query.exec();
    closeDatabaseConnection(db);
    return result;
}





