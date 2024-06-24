#include "config.h"
#include <QMetaType>

Config::Config(){
    qRegisterMetaType<ProjectEntry>("ProjectEntry");
    qRegisterMetaType<QList<ProjectEntry>>("QList<ProjectEntry>");
}

int Config::dump_settings(QString path_to_config) {
    path_to_config = get_suitable_config_path(path_to_config);

//    QJsonDocument jsonified_config = QJsonDocument::fromVariant(QVariant(*this));
    QFile config_file(path_to_config);
    if(!config_file.open(QIODevice::WriteOnly)){
        qDebug()<<"Cannot open config file[Write]: "<<path_to_config<<"!";
//        qDebug()<<"Config:\n"<<jsonified_config;
        return 0;
    }
    QDataStream stream(&config_file);
//    stream<<jsonified_config;
    stream<<(QVariantHash)*this;
    config_file.close();
    return 1;
}

int Config::load_settings(QString path_to_config) {
    path_to_config = get_suitable_config_path(path_to_config);
    if(!QFileInfo(path_to_config).isFile())return 0;

    QFile config_file(path_to_config);
    if(!config_file.open(QIODevice::ReadOnly)){
        qDebug()<<"Cannot open config file[Read]: "<<path_to_config<<"!";
        return 0;
    }
    QDataStream stream(&config_file);
//    QJsonDocument jsonified_config;
    QVariantHash config;
    stream >> config;
//    QVariantHash config = jsonified_config.object().toVariantHash();
    if(!config.empty()){
        auto x = config["history"].value<Histories>();
        for(auto i:x){
            qDebug()<<i.count;
        }
        this->insert(config);
    }
    config_file.close();
    return 1;
}

QString Config::get_suitable_config_path(QString path){
    if (path.isEmpty()) {
        path = QCoreApplication::applicationDirPath();
    }

    QFileInfo config_fileinfo(path);
    if(config_fileinfo.isDir()){
        path = config_fileinfo.filePath() + '/' + config_file_name;
        // Fine even though Windows
    }
    return path;
}


