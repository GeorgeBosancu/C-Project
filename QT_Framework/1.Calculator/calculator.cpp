#include "calculator.h"
#include "ui_calculator.h"

double calcVal{0.0};
bool divTrigger{false};
bool multTrigger{false};
bool addTrigger{false};
bool subTrigger{false};
bool clearTrigger{false};

Calculator::Calculator(QWidget *parent): QMainWindow(parent), ui(new Ui::Calculator) //creates the UI class and assign it to our UI member
{
    ui->setupUi(this); //it sets up our UI
    ui->Display->setText(QString::number(calcVal)); //we convert string into numbers
    QPushButton *numButtons[10];//an array for all pushbuttons
    for (int i{0}; i<10; i++){
        QString butName = "Button" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(butName);//search a specific widget, by providing the name
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumberPressed())); //functionality
    }
    connect(ui->Add, SIGNAL(released()), this, SLOT(MathButtonPressed()));//functionality
    connect(ui->Multiply, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Subtract, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Divide, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Equal, SIGNAL(released()), this, SLOT(EqualButton()));
    connect(ui->ChangeSign, SIGNAL(released()), this, SLOT(ChangeNumberSign()));
    connect(ui->clear, SIGNAL(released()), this, SLOT(ClearDisplay()));
    connect(ui->MemAdd, SIGNAL(released()), this, SLOT(Memory()));
    connect(ui->MemClear, SIGNAL (released()), this, SLOT(Memory()));
    connect(ui->MemGet, SIGNAL(released()), SLOT(Memory()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::NumberPressed(){
    QPushButton *button = (QPushButton *) sender();//find out which button was pressed - sender returns a pointer
    QString butval = button->text();//now get the button that was clicked on
    QString displayVal = ui->Display->text();//show the value on display
    if((displayVal.toDouble()==0) || (displayVal.toDouble()==0.0)){
        ui->Display->setText(butval);
    }else{
        QString newVal = displayVal + butval; //le afisam una dupa cealalata
        double dblNewVal = newVal.toDouble();//convert into double
        ui->Display->setText(QString::number(dblNewVal, 'g', 16));
    }
}

void Calculator::MathButtonPressed(){
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
    QString displayVal = ui->Display->text(); //the current display value
    calcVal = displayVal.toDouble(); //store that value and convert it
    QPushButton *button = (QPushButton *) sender();//find out which button was pressed
    QString butVal = button->text();//get the math sign from the button
    if (QString::compare(butVal, "/", Qt::CaseInsensitive)==0){ //if the button pressed is division, divTrigger = true
        divTrigger = true;
     } else if (QString::compare(butVal, "*", Qt::CaseInsensitive)==0){
        multTrigger = true;
     } else if (QString::compare(butVal, "+", Qt::CaseInsensitive)==0){
        addTrigger = true;
     } else {subTrigger = true;}
    ui->Display->setText(""); //clean the display
}

void Calculator::EqualButton(){
    double solution =0.0; //it stores the result
    QString displayVal= ui->Display->text(); //get the value from Display, to perform more calculations
    double dblDisplayVal = displayVal.toDouble(); //convert into double
    if (addTrigger || subTrigger || multTrigger || divTrigger){ //if one o them is pressed
        if (addTrigger){
            solution = calcVal + dblDisplayVal;
        } else if (subTrigger){
            solution = calcVal - dblDisplayVal;
        } else if (multTrigger){
            solution = calcVal * dblDisplayVal;
        } else{
            solution = calcVal / dblDisplayVal;
        }
    }
    ui->Display->setText(QString::number(solution)); //show solution
};

void Calculator::ChangeNumberSign(){
    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();
    QRegExp reg ("[-]?[0-9]*"); //cautam expresia
    if (reg.exactMatch(displayVal)){
        double dblDisplayValSign = -1 * dblDisplayVal;
        ui->Display->setText(QString::number(dblDisplayValSign));
    }
}

void Calculator::ClearDisplay(){
    clearTrigger = false;
    QPushButton *button = (QPushButton *) sender();
    QString butVal = button->text();
    if(QString::compare(butVal, "AC", Qt::CaseInsensitive)==0){
        clearTrigger = true;}
    if (clearTrigger){
        ui->Display->setText("0");
    }
}

void Calculator::Memory(){
    static double memorizedValue{0.0};
    QPushButton *button = (QPushButton *) sender(); //gasit butonul
    QString butVal = button->text(); //stochez ce afiseaza butonul
    QString displayVal = ui->Display->text(); //stochez ce am pe display
    double dblDisplayVal = displayVal.toDouble();
    if(QString::compare(butVal, "M+", Qt::CaseInsensitive)==0){
        memorizedValue = memorizedValue + dblDisplayVal;
    }
    else if(QString::compare(butVal, "M-", Qt::CaseInsensitive)==0){
        memorizedValue = memorizedValue - dblDisplayVal;
    }
    else if(QString::compare(butVal, "M", Qt::CaseInsensitive)==0){
        ui->Display->setText(QString::number(memorizedValue));
    }
}
