#ifndef EVENTITEMWIDGET_H
#define EVENTITEMWIDGET_H

#include <QWidget>
#include <event.h>

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

private slots:
    void on_buyTicketButton_clicked();

private:
    Ui::EventItemWidget *ui;
};

#endif // EVENTITEMWIDGET_H
