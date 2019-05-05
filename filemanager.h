#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include<QString>
class FileManager
{
public:
    FileManager();
    QString open();
    void save(const QString &text);
    void create_new();
    void setPath(const QString &str);


    QString filepath;
};

#endif // FILEMANAGER_H
