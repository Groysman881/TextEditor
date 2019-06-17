#ifndef FONT_H
#define FONT_H
#include<QTextDocument>
#include<QTextEdit>

class Font
{
public:
    Font();
    int fontSize;
    void changeSizeOfFont(QTextEdit *text,int size);
    void changeColorOfFont(QTextEdit *text,QColor color);
    void changeFont(QTextEdit *text,QFont font);;
    void changeBackgroundColor(QTextEdit *text,QColor color);
    void changeCodec(QTextEdit *text,QString codec);
    void changeHighlightColor(QTextEdit *text,QColor color);
};

#endif // FONT_H
