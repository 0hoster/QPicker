#ifndef WELCOMEWIDGET_H
#define WELCOMEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QTreeWidget>
#include <QDockWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QList>
#include <QPushButton>
#include "config.h"

typedef const Config& constConfig;

class WelcomeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WelcomeWidget(QWidget *parent = nullptr);
    void setImage(QString image_path = "");
    void setImage(const QPixmap& image);
    void setImage(constConfig config);
    int setOperation(constConfig config);
private:
    void initalizeUI();
    static const QString default_image_path;
    QVBoxLayout *welcome_layout = nullptr;
    QLabel *welcome_image = nullptr;
signals:

};

#endif // WELCOMEWIDGET_H
