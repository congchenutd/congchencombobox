#ifndef GET_PIN_YIN_H
#define GET_PIN_YIN_H

#include <QString>
#include <QStringList>
#include <string>
#include <functional>

bool In(wchar_t start, wchar_t end, wchar_t code);
char convert(wchar_t n);
char getFirstPinYin(const QString& chineseChar);
bool isChinese(const QString& str);
QStringList sortedChineseList(const QStringList& list);

struct lessChinese : public std::binary_function<QString, QString, bool> 
{
	bool operator() (const QString& x, const QString& y) const {
		return getFirstPinYin(x) < getFirstPinYin(y);
	}
};

#endif