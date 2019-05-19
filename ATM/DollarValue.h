#pragma once
#include <string>
#include <map>
#include <iostream>
#include <array>
#include <QVector>
using namespace std;
class DollarValue
{
	string NameVal;
	map<int, int> ValNum;
public:
	DollarValue();
	QVector<QString> Show();
	QString Add(int Value, int Number);
	QVector<QString> Get(int amount);
	~DollarValue();
};

