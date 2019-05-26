#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QAction>
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
#include <QTextCodec>
#include "font.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    filem = new FileManager;
    myfont = new Font;
    ui->setupUi(this);
    ui->CodecBox->addItem("UTF-32");
    ui->CodecBox->addItem("UTF-8");
    keyCtrlO = new QShortcut(this);
    keyCtrlO->setKey(Qt::CTRL + Qt::Key_O);
    connect(keyCtrlO,SIGNAL(activated()),this,SLOT(open_file()));
    keyCtrlS = new QShortcut(this);
    keyCtrlS->setKey(Qt::CTRL + Qt::Key_S);
    connect(keyCtrlS,SIGNAL(activated()),this,SLOT(save_file()));
    keyCtrlM = new QShortcut(this);
    keyCtrlM->setKey(Qt::CTRL + Qt::Key_M);
    connect(keyCtrlM,SIGNAL(activated()),this,SLOT(create_file()));
    connect(ui->Open,SIGNAL(triggered()),this,SLOT(open_file()));
    connect(ui->Save,SIGNAL(triggered()),this,SLOT(save_file()));
    connect(ui->Create,SIGNAL(triggered()),this,SLOT(create_file()));
    connect(ui->BackGround,SIGNAL(triggered()),this,SLOT(change_bgcolor()));
    connect(ui->fontComboBox,SIGNAL(currentFontChanged(QFont)),this,SLOT(change_font(QFont)));
    connect(ui->FontSize,SIGNAL(released()),this,SLOT(change_size_font()));
    connect(ui->Font,SIGNAL(triggered()),this,SLOT(change_color_font()));
    connect(ui->CodecBox,SIGNAL(currentTextChanged(QString)),this,SLOT(change_codec(QString)));
    connect(ui->Highlight,SIGNAL(triggered()),this,SLOT(change_highlight()));
}
MainWindow::~MainWindow()
{
    delete ui;
    delete(filem);
    delete(myfont);
}
void MainWindow::open_file()
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


void MainWindow::save_file()
{
    filem->save(ui->TextEdit->toPlainText());
}

void MainWindow::change_size_font()
{
    bool ok;
    QString str = ui->lineEdit->text();
    int size = str.toInt(&ok,10);
    myfont->change_size_of_font(ui->TextEdit,size);
}

void MainWindow::change_color_font()
{
    QColor color = QColorDialog::getColor();
    myfont->change_color_of_font(ui->TextEdit,color);


}

void MainWindow::change_font(const QFont &f)
{
    myfont->change_font(ui->TextEdit,f);
}

void MainWindow::change_bgcolor()
{
    QColor bgcolor = QColorDialog::getColor();
    myfont->change_background_color(ui->TextEdit,bgcolor);
}

void MainWindow::change_codec(const QString &codec)
{
    myfont->change_codec(ui->TextEdit,codec);

}

void MainWindow::create_file()
{
    filem->create_new(ui->TextEdit->toPlainText());
}

void MainWindow::change_highlight()
{
    QColor color = QColorDialog::getColor();
    myfont->change_highlight_color(ui->TextEdit,color);
}
