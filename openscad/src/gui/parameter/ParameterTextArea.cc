#include "gui/parameter/ParameterTextArea.h"

#include <QString>
#include <QWidget>
#include <string>
#include <QFocusEvent>
#include <QDebug>
#include <QFontMetrics>


ParameterTextArea::ParameterTextArea(QWidget *parent, StringParameter *parameter,
                             DescriptionStyle descriptionStyle)
  : ParameterVirtualWidget(parent, parameter), parameter(parameter)
{
  setupUi(this);
  descriptionWidget->setDescription(parameter, descriptionStyle);

  textEdit->setFocusPolicy(Qt::StrongFocus);

  QFontMetrics metrics (textEdit->font()) ;
  int RowHeight = metrics.lineSpacing() ;
  textEdit->setFixedHeight (20 * RowHeight + 3) ;

  connect(textEdit, &TextEdit::textEdited, this, &ParameterTextArea::onEdit);
  connect(textEdit, &TextEdit::editingFinished, this, &ParameterTextArea::onEditingFinished);

  ParameterTextArea::setValue();
}

void ParameterTextArea::valueApplied() { lastApplied = lastSent; }

void ParameterTextArea::onEdit(const QString& text)
{
  //qDebug() << "ParameterTextArea::onEdit " << text;
  std::string value = text.toStdString();
  if (lastSent != value) {
    lastSent = parameter->value = value;
    //emit changed(false);
    emit changed(true);
    //qDebug() << "ParameterTextArea::onEdit CHANGED";
  } 
}

void ParameterTextArea::onEditingFinished()
{
  //qDebug() << "ParameterTextArea::onEditingFinished 1 " << textEdit->toPlainText();

  std::string value = textEdit->toPlainText().toStdString();

  if (lastApplied != parameter->value || lastApplied != value) {
    lastSent = parameter->value = value;
    emit changed(true);
    //qDebug() << "ParameterTextArea::onEditingFinished CHANGED" ;
  } else {
    emit changed(false);
    //qDebug() << "ParameterTextArea::onEditingFinished NO change" ;
  }
}

void ParameterTextArea::setValue()
{
  //qDebug() << "ParameterTextArea::setValue " << QString::fromStdString(parameter->value);
  lastApplied = lastSent = parameter->value;
  textEdit->setText(QString::fromStdString(parameter->value));
}


