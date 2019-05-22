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
    void open_file();

    void save_file();

    void change_size_font();

    void change_color_font();

    void change_font(const QFont &f);

    void on_actionC_triggered();

    void change_bgcolor();

    void change_codec(const QString &codec);

    void create_file();

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
