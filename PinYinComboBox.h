#ifndef PinYinComboBox_h__
#define PinYinComboBox_h__

#include "SetTextComboBox.h"

class MyListView;

class PinYinComboBox : public SetTextComboBox
{
public:
	PinYinComboBox(QWidget* parent = 0);
	void loadFromTable(const QString& tableName, int column = 0);
	void sort();

protected:
	virtual void keyPressEvent(QKeyEvent* event);

private:
	MyListView* listView;
};


class MyListView : public QListView
{
public:
	MyListView(QWidget* parent = 0);
	int search(char ch);

protected:
	virtual void keyPressEvent(QKeyEvent* event);

private:
	char lastChar;
	std::vector<int> results;
	int current;
};

#endif // PinYinComboBox_h__