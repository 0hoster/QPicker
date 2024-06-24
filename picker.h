#ifndef PICKER_H
#define PICKER_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QTreeWidget>
#include <QDockWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QList>
#include <QStackedWidget>
#include <QPushButton>
#include "config.h"
#include "welcomewidget.h"

class Picker : public QMainWindow
{
    Q_OBJECT
public:
    Picker(QWidget *parent = nullptr);
    ~Picker();
    enum Page{
        Welcome,
        Check,
        Overview,
        Detail,
    };

private:
    inline Page current_page(){return (Page)stacked_widget->currentIndex();}
    Config config;
    QDockWidget *dock_tree;
    QStackedWidget *stacked_widget;
    QString get_window_title();
    void initalize_ui();
    void initalize_slot();
    void change_page(Page page);
    void load_and_check();
};
#endif // PICKER_H
