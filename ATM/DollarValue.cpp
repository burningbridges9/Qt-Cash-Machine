//#include "stdafx.h"
#include "DollarValue.h"


DollarValue::DollarValue()
{
	NameVal = "USD";
	ValNum = { {1,0},{ 10,0 },{100 ,0 },{1000 ,0 },
	{ 5,0 },{ 50,0 },{ 500,0 },{ 5000,0 } };
}

QVector<QString> DollarValue::Show()
{
	bool f = false;
    QVector<QString> vectorString;
	for (auto it = ValNum.begin(); it != ValNum.end(); ++it)
	{
		if (it->second != 0)
		{
			f = true;
			//cout << NameVal << " " << it->first << " " << it->second << endl;
            string str = NameVal;
            str += " ";
            str+= to_string(it->first);
            str+=" ";
            str+=to_string(it->second);
            //str+='\n';
            QString S=QString::fromStdString(str);
            vectorString.append(S);
		}
	}
	if (f == false)
	{
		//cout << NameVal << " is empty"<<endl;
        string str = NameVal;
        str += " is empty";
        QString S=QString::fromStdString(str);
        vectorString.append(S);
	}
    return vectorString;
}

QString DollarValue::Add(int Value, int Number)
{
    QString S;
	if (ValNum.find(Value) == ValNum.end())
	{
		//cout << "ERROR"<<endl;
        S = "ERROR\n";
	}
	else
	{
		auto it = ValNum.find(Value);
		it->second += Number;
		//cout << "OK" << endl;
        S = "OK\n";
	}
    return S;
}

QVector<QString> DollarValue::Get(int amount)
{
    QVector<QString> vectorString;
	int CurrentSum = 0;
	int tempAmount = amount;
	map<int,int> used = { { 1,0 },{ 10,0 },{ 100 ,0 },{ 1000 ,0 },{ 5,0 },{ 50,0 },{ 500,0 },{ 5000,0 } };

	for (auto it = ValNum.begin(); it != ValNum.end(); ++it)
	{
		CurrentSum += it->first*it->second;
	}
	if (CurrentSum < amount)
	{
		//cout << "ERROR" << endl;
        vectorString.append("ERROR\n");
	}
	else
	{
		if (CurrentSum == amount)
		{
			auto usedIter = used.begin();
			for (auto it = ValNum.begin(); it != ValNum.end(); ++it)
			{
				usedIter->second = it->second;
				tempAmount -= it->first*it->second;
				it->second = 0;
				++usedIter;
			}
		}
		else
		{
			auto usedIter = used.rbegin();
			for (auto it = ValNum.rbegin(); it != ValNum.rend(); ++it)
			{
				if (it->second == 0)
				{
					++usedIter;
					continue;
				}
				else
				{
					while (it->second!=0)
					{
						if (it->first > tempAmount)
						{
							break;
						}
						else
						{
							//cout << "before amount = " << tempAmount<<endl;
							tempAmount -= it->first;
							--it->second;
							//cout << it->first << " " << it->second<<endl;
							//cout << "after amount = " << tempAmount << endl;

							usedIter->second++;
						}
					}
					++usedIter;
				}
				
			}
		}
	
		if (tempAmount != 0)
		{
			//cout << "ERROR" << endl;
            vectorString.append("ERROR\n");
		}
		else 
		{
			for (auto usedIter = used.rbegin(); usedIter != used.rend(); ++usedIter)
			{
				if(usedIter->second!=0)
				{
                    //cout << usedIter->first << " " << usedIter->second << endl;
                    string str;
                    str = to_string(usedIter->first);
                    str+=" ";
                    str+=to_string(usedIter->second);
                    vectorString.append(QString::fromStdString(str));
                }
			}
			//cout << "OK" << endl;
            vectorString.append("OK\n");
		}
	}
    return vectorString;
}

DollarValue::~DollarValue()
{
}
