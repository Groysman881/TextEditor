#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include<QString>
#include<QObject>
class FileManager
{
public:
    FileManager();
    QString open();
    void save(const QString &text);
    void createNew(const QString &text);
    void setPath(const QString &str);
    QString filepath;
};

#endif // FILEMANAGER_H
