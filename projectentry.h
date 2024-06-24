#ifndef PROJECTENTRY_H
#define PROJECTENTRY_H
#include <QMetaType>
#include <QFileInfo>
#include <QString>
#include <QDataStream>

class ProjectEntry
{
public:
    ProjectEntry();
    ProjectEntry(int Count,QString Name,QString PathToConfig,QString PathToCover);
    int count = 0;
    QString name;
    QString pathToCover()const{return path_to_cover;}
    QString pathToConfig()const{return path_to_config;}
    int setPathToCover(const QString &path);
    int setPathToConfig(const QString &path);
private:
    QString path_to_cover;
    QString path_to_config;

};
Q_DECLARE_METATYPE(ProjectEntry)

QDataStream &operator<<(QDataStream &out, const ProjectEntry &entry);
QDataStream &operator>>(QDataStream &in, ProjectEntry &entry);
// 你是小丑吗 TM entry 按值传
#endif // PROJECTENTRY_H
