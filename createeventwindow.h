#ifndef CREATEEVENTWINDOW_H
#define CREATEEVENTWINDOW_H

#include <QMainWindow>

namespace Ui {
class CreateEventWindow;
}

class CreateEventWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateEventWindow(QWidget *parent = nullptr);
    ~CreateEventWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreateEventWindow *ui;
};

#endif // CREATEEVENTWINDOW_H
