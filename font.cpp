#include "font.h"
#include <QTextCodec>
#include <QPalette>

Font::Font()
{
    fontSize = 0;
}
void Font::changeColorOfFont(QTextEdit *Text,QColor color){
    QTextCursor cursor(Text->textCursor());
    QString select_text = cursor.selectedText();
    if(select_text.isEmpty()){
        Text->selectAll();
        Text->setTextColor(color);
    }
    else{
        Text->selectionChanged();
        Text->setTextColor(color);
    }
}

void Font::changeBackgroundColor(QTextEdit *text, QColor color){
    QPalette pal = text->palette();
    pal.setColor(QPalette::Base,color);
    text->setPalette(pal);
}

void Font::changeCodec(QTextEdit *text,QString codec){
    QTextCodec *_codec;
    if(codec == "UTF-32"){
        _codec = QTextCodec::codecForName("UTF-32");
    }
    else if(codec == "UTF-8"){
        _codec = QTextCodec::codecForName("UTF-8");
    }
    else if(codec == "Windows-1251"){
        _codec = QTextCodec::codecForName("Windows-1251");
    }
    QString prevText = text->toPlainText();
    text->setText(_codec->toUnicode(prevText.toUtf8()));
}

void Font::changeSizeOfFont(QTextEdit *text,int size){
    QTextCursor cursor(text->textCursor());
    QString selectText = cursor.selectedText();
    if(selectText.isEmpty()){
        text->selectAll();
        text->setFontPointSize(size);
    }
    else{
        text->selectionChanged();
        text->setFontPointSize(size);
    }
}

void Font::changeFont(QTextEdit *text,QFont font){
    QTextCursor cursor(text->textCursor());
    QString selectText = cursor.selectedText();
    QTextCharFormat format = cursor.charFormat();
    if(selectText.isEmpty()){
        text->selectAll();
        format.setFont(font);
        cursor.setCharFormat(format);
    }
    else{
        text->selectionChanged();
        format.setFont(font);
        cursor.setCharFormat(format);
    }
    if(fontSize != 0){
        text->setFontPointSize(fontSize);
    }
}

void Font::changeHighlightColor(QTextEdit *text, QColor color){
    QTextCursor cursor(text->textCursor());
    if(cursor.selectedText().isEmpty()){
        text->selectAll();
        text->setTextBackgroundColor(color);
    }
    else{
        text->selectionChanged();
        text->setTextBackgroundColor(color);
    }
}
