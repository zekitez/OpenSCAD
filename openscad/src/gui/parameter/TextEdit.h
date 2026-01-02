#pragma once

#include <QTextEdit>
#include <QFocusEvent>

class TextEdit : public QTextEdit
{
    Q_OBJECT

    public:
        TextEdit(QWidget *parent = nullptr);

    signals:
        void textEdited(const QString &);
        void editingFinished();

    protected:
        void focusInEvent(QFocusEvent* e) override;
        void focusOutEvent(QFocusEvent* e) override;
};
