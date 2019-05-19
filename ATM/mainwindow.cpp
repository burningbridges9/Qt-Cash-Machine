#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(500,500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow:: isUint(const string& s){
    bool f1 = s.find_first_not_of("0123456789") == std::string::npos;
    bool f2 = true;
    if (s=="")
    {
        f2 = false;
    }
    if ((f1 == true)&&(f2==true))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MainWindow::Work(string &S)
{
    cmatch result;
	
	if (S[0] == '+')
	{
        S.erase(0, 2);
        regex regular("([A-Z]{3}) (\\d{1,6}) (\\d{1,10})");
        if (regex_match(S.c_str(), result, regular))
        {
            string currency = result[1];
            int value = stoi(result[2]);
            int num = stoi(result[3]);
            //set(result[1], stoi(result[2]), stoi(result[3]));
            if (currency == "USD")
            {
                QString str = DV.Add(value, num);
                ui->textEdit->append(str);
            }
            if(currency == "RUR")
            {
                QString str = RV.Add(value, num);
                ui->textEdit->append(str);
            }
            
        }
        else
        {
            ui->textEdit->append("ERROR\n");
        }
	}
	if (S[0] == '-')
	{
		string currency = S.substr(2, 3);
        S.erase(0, 2);
        regex regular("([A-Z]{3}) (\\d{1,10})");
        if (regex_match(S.c_str(), result, regular))
        {
            string currency = result[1];
            int amount = stoi(result[2]);
            if (currency == "USD")
            {
                
                QVector<QString> vs;
                vs = DV.Get(amount);
                for (auto it = vs.begin();it!=vs.end(); it++)
                    ui->textEdit->append(*it);
                
            }
    
            if (currency == "RUR")
            {
                QVector<QString> vs;
                vs = RV.Get(amount);
                for (auto it = vs.begin();it!=vs.end(); it++)
                    ui->textEdit->append(*it);
            }
        }
        else
        {
            ui->textEdit->append("ERROR\n");
        }
	}
	if (S[0] == '?')
	{
        QVector<QString> vs;
		vs = DV.Show();
        for (auto it = vs.begin();it!=vs.end(); it++)
            ui->textEdit->append(*it);
        vs = RV.Show();
        for (auto it = vs.begin();it!=vs.end(); it++)
            ui->textEdit->append(*it);
	}
}


void MainWindow::on_ConfirmPushButton_clicked()
{
    QString S = ui->CommandLineEdit->text();
    ui->textEdit->append(S);
    ui->CommandLineEdit->clear();
    string str = S.toStdString();
    Work(str);
}
