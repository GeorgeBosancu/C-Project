#ifndef CHART_H
#define CHART_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Chart; }
QT_END_NAMESPACE

class Chart : public QMainWindow
{
    Q_OBJECT

public:
    Chart(QWidget *parent = nullptr);
    ~Chart();

private:
    Ui::Chart *ui;
};
#endif // CHART_H
