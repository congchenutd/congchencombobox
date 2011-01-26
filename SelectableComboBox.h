#ifndef SelectableComboBox_h__
#define SelectableComboBox_h__

#include "SetTextComboBox.h"

class SelectableComboBox : public SetTextComboBox
{
	Q_OBJECT

public:
	SelectableComboBox(QWidget* parent = 0);
	void setFileFilter(const QString& filter) { fileFilter = filter; }
	QStringList getFiles() const;
	void setFiles(const QStringList& files);

private slots:
	void onSetCurrentIndex(int idx);

private:
	QString fileFilter;
};

#endif // SelectableComboBox_h__