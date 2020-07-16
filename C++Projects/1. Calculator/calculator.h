#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; } //tied to our ui file (calculator.ui)
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT //the main class in QT Creator

public:
    Calculator(QWidget *parent = nullptr); //QWidget has no parent
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots://is called when he receive a signal
    void NumberPressed();
    void MathButtonPressed();
    void EqualButton();
    void ChangeNumberSign();
    void ClearDisplay();
    void Memory();
};
#endif // CALCULATOR_H
