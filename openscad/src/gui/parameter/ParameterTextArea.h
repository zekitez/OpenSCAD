#pragma once

#include "gui/parameter/ParameterVirtualWidget.h"
#include "ui_ParameterTextArea.h"

#include <QString>
#include <QWidget>
#include <string>
#include <QFocusEvent>

class ParameterTextArea : public ParameterVirtualWidget, Ui::ParameterTextArea
{
  Q_OBJECT

public:
  ParameterTextArea(QWidget *parent, StringParameter *parameter, DescriptionStyle descriptionStyle);
  void setValue() override;
  void valueApplied() override;

protected slots:
  void onEdit(const QString& text);
  void onEditingFinished();

private:
  StringParameter *parameter;
  boost::optional<std::string> lastSent;
  boost::optional<std::string> lastApplied;
};
