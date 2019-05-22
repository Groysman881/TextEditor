#ifndef FONT_H
#define FONT_H
#include<QTextDocument>
#include<QTextEdit>

class Font
{
public:
    Font();
    void change_size_of_font(QTextEdit *text,int size);
    void change_color_of_font(QTextEdit *text,QColor color);
    void change_font(QTextEdit *text,QFont font);;
    void change_background_color(QTextEdit *text,QColor color);
    void change_codec(QTextEdit *text,QString codec);
};

#endif // FONT_H
