#include "gui/parameter/ParameterText.h"

#include <QFileDialog>
#include <QString>
#include <QWidget>
#include <string>
#include <QDebug>

ParameterText::ParameterText(QWidget *parent, StringParameter *parameter,
                             DescriptionStyle descriptionStyle)
  : ParameterVirtualWidget(parent, parameter), parameter(parameter)
{
  setupUi(this);
  descriptionWidget->setDescription(parameter, descriptionStyle);

  if (parameter->maximumSize) {
    lineEdit->setMaxLength(*parameter->maximumSize);
  }

  connect(lineEdit, &QLineEdit::textEdited, this, &ParameterText::onEdit);
  connect(lineEdit, &QLineEdit::editingFinished, this, &ParameterText::onEditingFinished);
  ParameterText::setValue();
}

void ParameterText::valueApplied()
{
  lastApplied = lastSent;
}

void ParameterText::onEdit(const QString& text)
{
#ifdef DEBUG
  PRINTD("edit");
#endif
  std::string value = text.toStdString();
  if (lastSent != value) {
    lastSent = parameter->value = value;
    emit changed(false);
  }
  if (*parameter->maximumSize == 1025 && value.length() < 2 ){
      QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("3D (*.stl *.off *.obj *.3mf) ;; 2D (*.dxf *.pdf *.svg)") );
      qDebug() << "ParameterTextArea::onEdit fileName: " << fileName;
      lineEdit->setText(fileName);
      lastSent = parameter->value = lineEdit->text().toStdString();
      emit changed(true);
  }
}

void ParameterText::onEditingFinished()
{
#ifdef DEBUG
  PRINTD("editing finished");
#endif
  if (lastApplied != parameter->value) {
    lastSent = parameter->value = lineEdit->text().toStdString();
    emit changed(true);
  }
}

void ParameterText::setValue()
{
  lastApplied = lastSent = parameter->value;
  lineEdit->setText(QString::fromStdString(parameter->value));
}
