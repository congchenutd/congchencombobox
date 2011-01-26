#ifndef SetTextComboBox_h__
#define SetTextComboBox_h__

#include <QComboBox>
#include <QListView>
#include <vector>

class SetTextComboBox : public QComboBox
{
public:
	SetTextComboBox(QWidget* parent = 0);
	void setCurrentText(const QString& text);
};

#endif // SetTextComboBox_h__


