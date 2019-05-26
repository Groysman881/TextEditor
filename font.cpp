#include "font.h"
#include <QTextCodec>
#include <QPalette>

Font::Font()
{

}

void Font::change_color_of_font(QTextEdit *Text,QColor color){
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

void Font::change_background_color(QTextEdit *text, QColor color){
    QPalette pal = text->palette();
    pal.setColor(QPalette::Base,color);
    text->setPalette(pal);
}

void Font::change_codec(QTextEdit *text,QString codec){
    QTextCodec *_codec;
    if(codec == "UTF-32"){
        _codec = QTextCodec::codecForName("UTF-32");
    }
    else if(codec == "UTF-8"){
        _codec = QTextCodec::codecForName("UTF-8");
    }
    QString prev_text = text->toPlainText();
    text->setText(_codec->toUnicode(prev_text.toUtf8()));
}

void Font::change_size_of_font(QTextEdit *text,int size){
    QTextCursor cursor(text->textCursor());
    QString select_text = cursor.selectedText();
    if(select_text.isEmpty()){
        text->selectAll();
        text->setFontPointSize(size);
    }
    else{
        text->selectionChanged();
        text->setFontPointSize(size);
    }
}

void Font::change_font(QTextEdit *text,QFont font){
    QTextCursor cursor(text->textCursor());
    QString select_text = cursor.selectedText();
    if(select_text.isEmpty()){
        text->selectAll();
        text->setFont(font);
    }
    else{
        text->selectionChanged();
        text->setFont(font);
    }
}

void Font::change_highlight_color(QTextEdit *text, QColor color){
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
