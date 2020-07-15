#include "calculator.h"
#include "ui_calculator.h"

double calcValue{0.0};
bool addTrigger{false};
bool subtrTrigger{false};
bool multTrigger{false};
bool divTrigger{false};
bool clearTrigger{false};

Calculator::Calculator(QWidget *parent): QMainWindow(parent), ui(new Ui::Calculator)
{
    ui->setupUi(this);
    ui->Display->setText(QString::number(calcValue));
    QPushButton *btns [10];
    for (int i{0}; i<10; i++){
        QString butName = "Btn" + QString::number(i);//stocam denumirea in btName
        btns[i] = Calculator::findChild <QPushButton *> (butName); //cautam fiecare buton dupa denumire
        connect (btns[i], SIGNAL(released()), this, SLOT(NumberPressed())); //functionalitate pentru fiecare buton apasat
    }
    connect(ui->BtnPoint, SIGNAL(released()), this, SLOT(Point()));
    connect(ui->Clear, SIGNAL(pressed()), this, SLOT(Clear()));
    connect(ui->Add, SIGNAL(pressed()), SLOT(MathNumberPressed()));
    connect(ui->Subtraction, SIGNAL(pressed()), SLOT(MathNumberPressed()));
    connect(ui->Divide, SIGNAL(pressed()), SLOT(MathNumberPressed()));
    connect(ui->Multiply, SIGNAL(pressed()), SLOT(MathNumberPressed()));
    connect(ui->Equal, SIGNAL(pressed()), this, SLOT(Equal()));
    connect(ui->Sign, SIGNAL(pressed()), this, SLOT(ChangeNumberSign()));
    connect(ui->Percent, SIGNAL(pressed()), this, SLOT(percent()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::NumberPressed(){
    QPushButton *btn = (QPushButton *) sender(); //*btn = sender-ul (butonul)
    QString btnValue = btn->text(); //stocam numarul butonului in btnValue
    QString displayValue = ui->Display->text(); //stocam valoarea de pe display in displayValue
    if ((displayValue.toDouble() ==0) || (displayValue.toDouble()==0.0)){
        ui->Display->setText(btnValue);
}
    else{
        QString longValue = displayValue + btnValue; //una dupa alta
        ui->Display->setText(longValue);
        //mai pun limita?
    }
}

//de rectificat (nu functioneaza optim la 0.)
void Calculator::Point(){
    QPushButton *btn = (QPushButton *) sender(); //identific buton
    QString btnValue = btn->text(); //text de pe buton
    QString displayValue = ui->Display->text(); //text de pe display
    QString longValue = displayValue + btnValue; //valorile combinate
    double dblDisplayValue = displayValue.toDouble(); //convertim
    if (QString::compare(btnValue, ".", Qt::CaseInsensitive) ==0){
        if (dblDisplayValue == 0){
            ui->Display->setText("0");
        }
        else
            ui->Display->setText(longValue);
    }
}

void Calculator::MathNumberPressed(){
    addTrigger = false;
    subtrTrigger = false;
    multTrigger = false;
    divTrigger = false;
    QPushButton *mathBtn = (QPushButton *) sender();
    QString mathBtnValue = mathBtn->text();
    QString displayValue = ui->Display->text();
    calcValue = displayValue.toDouble();
    ui->Help->setText(QString::number(calcValue));//imi afiseaza calcValue in help
    if (QString::compare(mathBtnValue, "+", Qt::CaseInsensitive)==0){
                addTrigger = true;
    }else if (QString::compare(mathBtnValue, "–", Qt::CaseInsensitive)==0){
                subtrTrigger = true;
    }else if (QString::compare(mathBtnValue, "x", Qt::CaseInsensitive)==0){
                multTrigger = true;
    }else{
                divTrigger = true;
            }
    ui->Display->setText("");
}

void Calculator::Equal(){
    double solution {0.0};
    QString displayValue = ui->Display->text();
    double dbldisplayValue = displayValue.toDouble();
    if (addTrigger || subtrTrigger || multTrigger || divTrigger){
        if (addTrigger){
            solution = calcValue + dbldisplayValue;
        } else if (subtrTrigger){
            solution = calcValue - dbldisplayValue;
        } else if (multTrigger){
            solution = calcValue * dbldisplayValue;
        } else{
            solution = calcValue / dbldisplayValue;
        }
    }
    ui->Display->setText(QString::number(solution));
    ui->Help->setText("");
};

void Calculator::Clear(){
    QPushButton *btn = (QPushButton *) sender();
    QString btnValue = btn->text();
    if (QString::compare(btnValue, "C", Qt::CaseInsensitive) == 0){
        ui->Display->setText("0");
    }
};

void Calculator::ChangeNumberSign(){
    QString displayValue = ui->Display->text();
    double dblDisplayValue = displayValue.toDouble();
    QRegExp reg ("[-]?[0-9]*");
    if (reg.exactMatch(displayValue)){
        double signedValue = (-1) * dblDisplayValue;
        ui->Display->setText(QString::number(signedValue));
    }
};

void Calculator::percent(){
    QPushButton *btn = (QPushButton *) sender();
    QString btnValue = btn->text();
    QString displayValue = ui->Display->text();
    double dblDisplayValue = displayValue.toDouble();
    if (QString::compare(btnValue, "%", Qt::CaseInsensitive)==0){
        dblDisplayValue = dblDisplayValue / 100;
    }
    ui->Display->setText(QString::number(dblDisplayValue));
}

















