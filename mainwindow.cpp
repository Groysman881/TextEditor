#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QTextStream>
#include <QTextEdit>
#include <QTextCursor>
#include <QLineEdit>
#include "filemanager.h"
#include <QColor>
#include <QColorDialog>
#include <QFontDialog>
#include <QTextCursor>
#include "text.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    filem = new FileManager;
    mytext = new TextHilight;
    ui->setupUi(this);

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Open_clicked()
{
  QString fpath = QFileDialog::getOpenFileName(this,tr("Open File"),"/","All files (*.*)");
  filem->setPath(fpath);
  QMessageBox::information(this,"File",filem->filepath);
  QString text = filem->open();
  if(text == "Error"){

      QMessageBox::warning(this,"Error","Path is not correct");
  }

  ui->TextEdit->setPlainText(text);



}


void MainWindow::on_Save_clicked()
{
    filem->save(ui->TextEdit->toPlainText());
}






void MainWindow::on_Font_clicked()
{
    bool ok;
    QString str = ui->lineEdit->text();
    int size = str.toInt(&ok,10);

    QTextCursor cursor(ui->TextEdit->textCursor());
    QString select_text = cursor.selectedText();
    if(select_text.isEmpty()){
        ui->TextEdit->selectAll();
        ui->TextEdit->setFontPointSize(size);
    }
    else{
        ui->TextEdit->selectionChanged();
        ui->TextEdit->setFontPointSize(size);
    }

}

void MainWindow::on_Color_clicked()
{
    QColor color = QColorDialog::getColor();
    QTextCursor cursor(ui->TextEdit->textCursor());
    QString select_text = cursor.selectedText();
    if(select_text.isEmpty()){
        ui->TextEdit->selectAll();
        ui->TextEdit->setTextColor(color);
    }
    else{
        ui->TextEdit->selectionChanged();
        ui->TextEdit->setTextColor(color);
    }


}

void MainWindow::on_fontComboBox_currentFontChanged(const QFont &f)
{
    QTextCursor cursor(ui->TextEdit->textCursor());
    QString select_text = cursor.selectedText();
    if(select_text.isEmpty()){
        ui->TextEdit->selectAll();
        ui->TextEdit->setFont(f);
    }
    else{
        ui->TextEdit->selectionChanged();
        ui->TextEdit->setFont(f);
    }

}

void MainWindow::on_actionC_triggered()
{   
    ui->TextEdit->moveCursor(QTextCursor::Start);


    QTextCursor cursor(ui->TextEdit->textCursor());

   //     ui->TextEdit->moveCursor(QTextCursor::Start);
    do{

            //ui->TextEdit->moveCursor(QTextCursor::EndOfWord,QTextCursor::KeepAnchor);
            //QTextCursor cursor(ui->TextEdit->textCursor());
            cursor.movePosition(QTextCursor::EndOfWord,QTextCursor::KeepAnchor);
            ui->TextEdit->setTextCursor(cursor);

            QColor color;
            //color.setBlue(255);

            if(cursor.selectedText() == "if"){
                color.setBlue(255);
                ui->TextEdit->setTextColor(color);   
            }
            else if(cursor.selectedText() == "else"){
                color.setGreen(255);
                ui->TextEdit->setTextColor(color);
            }
            else if(cursor.selectedText() == "#"){
                //ui->TextEdit->moveCursor(QTextCursor::NextWord,QTextCursor::KeepAnchor);
                //ui->TextEdit->moveCursor(QTextCursor::EndOfWord,QTextCursor::KeepAnchor);
                //cursor.movePosition(QTextCursor::NextWord,QTextCursor::KeepAnchor);
                cursor.movePosition(QTextCursor::EndOfWord,QTextCursor::KeepAnchor);
                ui->TextEdit->setTextCursor(cursor);
                //QMessageBox::information(this,"info",cursor.selectedText());
                if(cursor.selectedText() == "#include" || cursor.selectedText() == "#define"){
                    color.setBlue(255);
                    ui->TextEdit->setTextColor(color);
                }
            }
            else if(cursor.selectedText() == "for"){
                color.setRed(255);
                ui->TextEdit->setTextColor(color);
            }
        }while(cursor.movePosition(QTextCursor::NextWord,QTextCursor::MoveAnchor));
            //ui->TextEdit->moveCursor(QTextCursor::NextWord);




}

void MainWindow::on_backGround_clicked()
{
    QColor bgcolor = QColorDialog::getColor();
    QTextCursor cursor(ui->TextEdit->textCursor());
    if(cursor.selectedText().isEmpty()){
        ui->TextEdit->selectAll();
        ui->TextEdit->setTextBackgroundColor(bgcolor);
    }
    else{
        ui->TextEdit->selectionChanged();
        ui->TextEdit->setTextBackgroundColor(bgcolor);
    }
}
