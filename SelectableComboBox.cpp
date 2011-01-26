#include "SelectableComboBox.h"
#include <QFileDialog>

SelectableComboBox::SelectableComboBox(QWidget* parent) : SetTextComboBox(parent)
{
	addItem(tr("No file"));
	addItem(tr("Select ..."));
	connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(onSetCurrentIndex(int)));
}

void SelectableComboBox::onSetCurrentIndex(int idx)
{
	if(currentText() == tr("Select ..."))  // select
	{
		QString fileName = QFileDialog::getOpenFileName
			(this, tr("Open File"),	".", fileFilter);
		if(!fileName.isEmpty())
		{
			disconnect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(onSetCurrentIndex(int)));
			insertItem(idx, QFileInfo(fileName).filePath());
			setCurrentIndex(idx);
			connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(onSetCurrentIndex(int)));
		}
	}
}

QStringList SelectableComboBox::getFiles() const
{
	QStringList result;
	for(int i=0; i<count(); ++i)
		if(itemText(i) != tr("No file") && itemText(i) != tr("Select ..."))
			result << itemText(i);
	return result;
}

void SelectableComboBox::setFiles(const QStringList& files)
{
	int row = 1;
	foreach(QString file, files)
		insertItem(row++, file);
}
