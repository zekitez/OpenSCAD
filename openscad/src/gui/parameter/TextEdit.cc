#include "gui/parameter/TextEdit.h"
#include <QDebug>

TextEdit::TextEdit(QWidget *parent)
    : QTextEdit(parent)
{
    setFocusPolicy(Qt::StrongFocus); // Ensure the widget can receive focus
}

void TextEdit::focusInEvent(QFocusEvent *event)
{
    //qDebug() << "TextEdit::focusInEvent: Gained focus!";
    QTextEdit::focusInEvent(event); // Essential: call base class implementation
    emit textEdited( QTextEdit::toPlainText() );
    setStyleSheet("border: 2px solid blue;"); // Change border to blue
}

void TextEdit::focusOutEvent(QFocusEvent *event)
{
    //qDebug() << "TextEdit::focusOutEvent: Lost focus!";
    QTextEdit::focusOutEvent(event); // Essential: call base class implementation
    emit editingFinished();
    setStyleSheet("border: 1px solid darkgray;"); // Change border to darkgray

}