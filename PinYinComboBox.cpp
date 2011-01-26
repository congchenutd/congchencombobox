#include "PinYinComboBox.h"
#include "GetPinYin.h"
#include <QKeyEvent>
#include <QSqlQuery>

PinYinComboBox::PinYinComboBox(QWidget *parent) : SetTextComboBox(parent)
{
	setView(listView = new MyListView(this));
}

void PinYinComboBox::keyPressEvent(QKeyEvent* event)
{
	showPopup();
	setCurrentIndex(listView->search(event->text().at(0).toAscii()));
	QComboBox::keyPressEvent(event);
}

void PinYinComboBox::loadFromTable(const QString& tableName, int column /*= 0*/)
{
	clear();
	QSqlQuery query;
	query.exec("select * from " + tableName);
	while(query.next())
		addItem(query.value(column).toString());
}

void PinYinComboBox::sort()
{
	QStringList strings;
	for(int i=0; i<count(); ++i)
		strings << itemText(i);
	clear();
	addItems(sortedChineseList(strings));
}

MyListView::MyListView(QWidget* parent) : QListView(parent) 
{
	lastChar = '\0';
	current = -1;
}

void MyListView::keyPressEvent(QKeyEvent* event)
{
	QAbstractItemModel* m = model();
	QChar ch = event->text().at(0);
	int row = search(ch.toAscii());
	scrollTo(m->index(row, 0));
	selectionModel()->select(m->index(0, 0),   QItemSelectionModel::Clear);
	selectionModel()->select(m->index(row, 0), QItemSelectionModel::Select | 
		QItemSelectionModel::Rows);
}

int MyListView::search(char ch)
{
	if(ch != lastChar)  // new search
	{
		results.clear();
		lastChar = ch;
		current = 0;
		QAbstractItemModel* m = model();
		for(int i=0; i<m->rowCount(); ++i)
			if(getFirstPinYin(m->data(m->index(i, 0)).toString()) == ch)
				results.push_back(i);
	}

	return results.empty() ? 0 : results[current++ % results.size()];
}