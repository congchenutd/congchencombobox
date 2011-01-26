#include "SetTextComboBox.h"

SetTextComboBox::SetTextComboBox(QWidget *parent) : QComboBox(parent)
{}

void SetTextComboBox::setCurrentText(const QString& text)
{
	int index = findText(text);
	if(index > -1)
		setCurrentIndex(index);
}