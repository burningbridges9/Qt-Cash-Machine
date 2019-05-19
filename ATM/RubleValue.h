#pragma once
#include <string>
#include <map>
#include <iostream>
#include <QVector>
using namespace std;
class RubleValue
{
private:
	string NameVal;
	map<int, int> ValNum;
public:
	RubleValue();
    QVector<QString> Show();
	QString Add(int Value, int Number);
	QVector<QString> Get(int amount);
	~RubleValue();
};

