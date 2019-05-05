#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filemanager.h"
#include "text.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Open_clicked();

    void on_Save_clicked();

    void on_Font_clicked();

    void on_Color_clicked();

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_actionC_triggered();

    void on_backGround_clicked();

private:
    Ui::MainWindow *ui;
    FileManager* filem;
    TextHilight* mytext;
};

#endif // MAINWINDOW_H
