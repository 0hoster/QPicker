#include "projectentry.h"

ProjectEntry::ProjectEntry()=default;

ProjectEntry::ProjectEntry(int Count,QString Name,QString PathToConfig,QString PathToCover){
    count = Count;
    name = Name;
    setPathToConfig(PathToConfig);
    setPathToCover(PathToCover);
}

int ProjectEntry::setPathToConfig(const QString &path){
    if(!QFileInfo(path).isFile())return 0;
    path_to_config = path;
    return 1;
}

int ProjectEntry::setPathToCover(const QString &path){
    if(!QFileInfo(path).isFile())return 0;
    path_to_cover = path;
    return 1;
}

QDataStream &operator<<(QDataStream &out, const ProjectEntry &entry){
    out << entry.count
        << entry.name
        << entry.pathToConfig()
        << entry.pathToCover();
    qDebug()<< entry.count
           << entry.name
           << entry.pathToConfig()
           << entry.pathToCover();
    return out;
}

QDataStream &operator>>(QDataStream &in, ProjectEntry &entry){
    QString path_to_config = "";
    QString path_to_cover = "";
    in >> entry.count >> entry.name>> path_to_config>> path_to_cover;
    qDebug()<<entry.count<< entry.name<<path_to_config<<path_to_cover;
    entry.setPathToConfig(path_to_config);
    entry.setPathToCover(path_to_cover);
    return in;
}
