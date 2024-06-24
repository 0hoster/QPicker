#include "picker.h"

Picker::Picker(QWidget *parent)
    : QMainWindow(parent)
{
    config.load_settings();
    //////////////////////////////////// TEST
//    Histories his = {(History){10,"我","/home/host/Documents/a.sh",""},(History){1,"HIHIIH","asdf",""},(History){1,"Sing Dance Rap","asdf",""}};
//    config["history"] = QVariant::fromValue(his);
    initalize_ui();
    initalize_slot();
}

Picker::~Picker() {
//    config.dump_settings();
}

void Picker::initalize_ui(){
    // Use once
    stacked_widget = new QStackedWidget(this);

    WelcomeWidget *welcome = new WelcomeWidget(this);
    welcome->setOperation(config);
//    welcome->setOperation(config);
    stacked_widget->addWidget(welcome);


    QWidget *check_wight = new QWidget(stacked_widget);

    stacked_widget->addWidget(check_wight);


    QWidget *overview_widget = new QWidget(stacked_widget);
    overview_widget->setMinimumSize(500,500);
    dock_tree = new QDockWidget(overview_widget);
    QTreeWidget *tree_widget = new QTreeWidget(dock_tree);

    dock_tree->setWidget(tree_widget);
    dock_tree->setFeatures(QDockWidget::DockWidgetMovable);
    dock_tree->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    dock_tree->setWindowTitle("Tree");

    this->addDockWidget(Qt::LeftDockWidgetArea,dock_tree);
    stacked_widget->addWidget(overview_widget);

    QWidget *detail_widget = new QWidget(stacked_widget);
    stacked_widget->addWidget(detail_widget);

    this->setCentralWidget(stacked_widget);
    change_page(Welcome);
}

void Picker::initalize_slot(){
}

QString Picker::get_window_title(){
    if(current_page()==Welcome){
        return "QPicker - Open Project";
    }else if(current_page()==Overview){
        return "QPicker - Overview " + config.value("project","").value<QString>();
    }else if(current_page()==Detail){
        return "QPicker - Detail " + config.value("currentImage","").value<QString>();
    }else {
        return "QPicker";
    }
}

void Picker::change_page(Page page){
    stacked_widget->setCurrentIndex(page);
    if(page==Welcome){
        dock_tree->setHidden(true);
    }else{
        dock_tree->setHidden(false);
    }
    setWindowTitle(get_window_title());
}

