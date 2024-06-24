#include "welcomewidget.h"

const QString WelcomeWidget::default_image_path = ":/images/welcome.png";

WelcomeWidget::WelcomeWidget(QWidget *parent)
    : QWidget{parent}
{
    initalizeUI();
    this->setLayout(welcome_layout);
}

void WelcomeWidget::initalizeUI(){
    assert(welcome_layout == nullptr);
    // Dont use initalizeUI again, cause memory LEAK!

    welcome_layout = new QVBoxLayout(this);

    welcome_image = new QLabel(this);
    welcome_image->setPixmap(QPixmap(":/images/welcome.png"));
    welcome_image->setAlignment(Qt::AlignCenter);
    welcome_layout->addWidget(welcome_image);

    QPushButton *operation = new QPushButton("Open existing folder");
    connect(operation,&QPushButton::clicked,this,[&](){
        qDebug()<<"Open existing folder";
    });
    welcome_layout->addWidget(operation);
}

void WelcomeWidget::setImage(constConfig config){
    setImage(config.value("welcome_image","").value<QString>());
}

void WelcomeWidget::setImage(QString image_path){
    if(image_path.isEmpty())image_path = default_image_path;
    setImage(QPixmap(image_path));
}

void WelcomeWidget::setImage(const QPixmap& image){
    welcome_image->setPixmap(image);
}

int WelcomeWidget::setOperation(constConfig config){
    for(int i=0;i < welcome_layout->count();){
        QLayoutItem *layout_item = welcome_layout->itemAt(i);
        auto *item = qobject_cast<QPushButton*>(layout_item->widget());
        if(item!=nullptr && item->property("operation")==true){
            qDebug()<<"del";
            auto repeated_buttons = welcome_layout->takeAt(i);
            delete repeated_buttons->widget();
            delete repeated_buttons;
        }else{
            i += 1;
        }
    }

    int options = 0;
    if(config.contains("history")){
        auto histories = config.value("history").value<Histories>();
        for(const auto &history:histories){
            QString tip =  tr("Continue") + ' ' + history.name + ' ' + tr("Session");
            QPushButton *operation = new QPushButton(tip);
            operation->setProperty("operation",true);
            connect(operation,&QPushButton::clicked,this,[tip](){
                qDebug()<<tip;
            });
            welcome_layout->addWidget(operation);
            options += 1;
        }
    }
    return options;
}
