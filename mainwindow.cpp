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
    ui->CodecBox->addItem("Windows-1251");
    ui->Save->setEnabled(false);
    keyCtrlO = new QShortcut(this);
    keyCtrlO->setKey(Qt::CTRL + Qt::Key_O);
    connect(keyCtrlO,SIGNAL(activated()),this,SLOT(open_file()));
    keyCtrlS = new QShortcut(this);
    keyCtrlS->setKey(Qt::CTRL + Qt::Key_S);
    connect(keyCtrlS,SIGNAL(activated()),this,SLOT(save_file()));
    keyCtrlM = new QShortcut(this);
    keyCtrlM->setKey(Qt::CTRL + Qt::Key_M);
    connect(keyCtrlM,SIGNAL(activated()),this,SLOT(createFile()));
    connect(ui->Open,SIGNAL(triggered()),this,SLOT(openFile()));
    connect(ui->Save,SIGNAL(triggered()),this,SLOT(saveFile()));
    connect(ui->Create,SIGNAL(triggered()),this,SLOT(createFile()));
    connect(ui->BackGround,SIGNAL(triggered()),this,SLOT(changeBgcolor()));
    connect(ui->fontComboBox,SIGNAL(currentFontChanged(QFont)),this,SLOT(changeTextFont(QFont)));
    connect(ui->FontSize,SIGNAL(released()),this,SLOT(changeSizeFont()));
    connect(ui->Font,SIGNAL(triggered()),this,SLOT(changeColorFont()));
    connect(ui->CodecBox,SIGNAL(currentTextChanged(QString)),this,SLOT(changeCodec(QString)));
    connect(ui->Highlight,SIGNAL(triggered()),this,SLOT(changeHighlight()));
}
MainWindow::~MainWindow()
{
    delete ui;
    delete(filem);
    delete(myfont);
}
void MainWindow::openFile()
{
  QString fpath = QFileDialog::getOpenFileName(this,tr("Open File"),"/","All files (*.*)");
  filem->setPath(fpath);
  ui->Save->setEnabled(true);
  QMessageBox::information(this,"File",filem->filepath);
  QString text = filem->open();
  if(text == "Error"){

      QMessageBox::warning(this,"Error","Path is not correct");
  }

  ui->TextEdit->setPlainText(text);
}


void MainWindow::saveFile()
{
    filem->save(ui->TextEdit->toPlainText());
}

void MainWindow::changeSizeFont()
{
    bool ok;
    QString str = ui->lineEdit->text();
    int size = str.toInt(&ok,10);
    myfont->fontSize = size;
    myfont->changeSizeOfFont(ui->TextEdit,size);
}

void MainWindow::changeColorFont()
{
    QColor color = QColorDialog::getColor();
    myfont->changeColorOfFont(ui->TextEdit,color);
}

void MainWindow::changeTextFont(const QFont &f)
{
    myfont->changeFont(ui->TextEdit,f);
}

void MainWindow::changeBgcolor()
{
    QColor bgcolor = QColorDialog::getColor();
    myfont->changeBackgroundColor(ui->TextEdit,bgcolor);
}

void MainWindow::changeCodec(const QString &codec)
{
    myfont->changeCodec(ui->TextEdit,codec);
}

void MainWindow::createFile()
{
    filem->createNew(ui->TextEdit->toPlainText());
}

void MainWindow::changeHighlight()
{
    QColor color = QColorDialog::getColor();
    myfont->changeHighlightColor(ui->TextEdit,color);
}
