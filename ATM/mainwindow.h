#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DollarValue.h"
#include "RubleValue.h"
#include <regex>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Work(string &S);
    bool isUint(const string& s);
private slots:
    void on_ConfirmPushButton_clicked();
    
private:
    Ui::MainWindow *ui;
    DollarValue DV;
	RubleValue RV;
};

#endif // MAINWINDOW_H
