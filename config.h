#ifndef CONFIG_H
#define CONFIG_H

#include <QHash>
#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QDataStream>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QCoreApplication>
#include "projectentry.h"

typedef ProjectEntry History;
typedef QList<History> Histories;

class Config : public QVariantHash
{
private:
    QString config_file_name = "QPicker-config";
public:
    Config();
    int dump_settings(QString path_to_config = "");
    int load_settings(QString path_to_config = "");
    QString get_suitable_config_path(QString path);
};

#endif // CONFIG_H
