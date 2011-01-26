#include <QtGui/QApplication>
#include <QTextCodec>
#include <QSqlDatabase>
#include "SelectableComboBox.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("GB18030"));
	SelectableComboBox cb;

	//QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
	//database.setDatabaseName("test.db");
	//database.open();

//	w.loadFromTable("Test", 1);
	//cb.addItem(QObject::tr("’‘"));
	//cb.addItem(QObject::tr("«Æ"));
	//cb.addItem(QObject::tr("ÀÔ"));
	//cb.addItem(QObject::tr("¿Ó"));
	//cb.sort();
	cb.setFileFilter(QObject::tr("Sound files (*.wav);;All files(*.*)"));
	cb.setFiles(QStringList() << "a" << "b");
	cb.show();
	return a.exec();
}
