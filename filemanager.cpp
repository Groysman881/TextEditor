#include "filemanager.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>

FileManager::FileManager()
{
    filepath = "";
}
QString FileManager::open(){
    QFile file(filepath);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        return("Error");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    file.close();
    return text;

}
void FileManager::setPath(const QString &str){
    filepath.append(str);
}
void FileManager::save(const QString &text){
    QFile file(filepath);
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream stream(&file);
    stream <<text;
    file.close();
}
void FileManager::createNew(const QString &text){
    filepath = QFileDialog::getSaveFileName();
    QFile file(filepath);
    file.open(QIODevice::WriteOnly | QFile::Text);
    QTextStream stream(&file);
    stream<<text;
    file.close();
}

