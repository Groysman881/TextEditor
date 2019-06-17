#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filemanager.h"
#include "font.h"
#include "highlighter.h"
#include <QShortcut>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Ui::MainWindow *ui;

private slots:
    void openFile();

    void saveFile();

    void changeSizeFont();

    void changeColorFont();

    void changeTextFont(const QFont &f);

    void changeBgcolor();

    void changeCodec(const QString &codec);

    void createFile();

    void changeHighlight();

private:
    Ui::MainWindow *ui;
    FileManager* filem;
    Font* myfont;
    Highlighter* highlighter;
    QShortcut *keyCtrlO;
    QShortcut *keyCtrlS;
    QShortcut *keyCtrlM;

};

#endif // MAINWINDOW_H
