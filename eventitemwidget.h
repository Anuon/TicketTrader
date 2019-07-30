#ifndef EVENTITEMWIDGET_H
#define EVENTITEMWIDGET_H

#include <QWidget>
#include "event.h"
#include "databasehandler.h"
#include "createeventwindow.h"

namespace Ui {
class EventItemWidget;
}

class EventItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EventItemWidget(QWidget *parent = nullptr);
    ~EventItemWidget();

    void setData(Event event);
    void setUser(QString user);

signals:
     void refresh();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Event event;
    QString user;
    QString eventOrganizer;
    int eventId;
    int ticket_price;
    CreateEventWindow *createEventWindow;
    DatabaseHandler *database;
    Ui::EventItemWidget *ui;
};

#endif // EVENTITEMWIDGET_H
