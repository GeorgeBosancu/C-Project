#include "chart.h"

#include <QApplication> //pentru widgeturi in general
#include <QtWidgets/QMainWindow> //QMainWindow (parte din QTWidget) - fereastra principala
#include <QtCharts/QChartView> //QChartView (parte din QTCharts) - afisare charturi
#include <QtCharts/QBarSeries> //QBarSeries (...) - bare grupate in diferite categorii
#include <QtCharts/QBarSet> //QBarSet - un set anume de bare
#include <QtCharts/QLegend> //QLegend - culorile pentru fiecare QBarSet
#include <QtCharts/QBarCategoryAxis> //QBarCategoryAxis - adauga categorii pentru fiecare axa de charturi
#include <QtCharts/QHorizontalStackedBarSeries> //QH... - una dintre bare
#include <QtCharts/QLineSeries> //QLineSeries - pentru Line Charts
#include <QtCharts/QCategoryAxis> //QCategoryAxis - schimbare nume pe axele de charturi
#include <QtCharts/QPieSeries> //QPieSeries - pentru Pie Charts
#include <QtCharts/QPieSlice> //QPieSlice - pentru Pie Charts

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLineSeries *series = new QLineSeries();
    series->append(0, 45);
    series->append(1, 33);
    series->append(2, 40);
    series->append(3, 28);
    series->append(4, 35);
    series->append(5, 24);
    series->append(6, 26);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();

    //fonturi
    QFont font;
    font.setPixelSize(18);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::blue));
    chart->setTitle("The influence of TV Media – last 7 years");

    //schimbam culoarea liniei noastre
    QPen pen(QRgb(0xFFAA1D));
    pen.setWidth(5);
    series->setPen(pen);

    //animatii
    chart->setAnimationOptions(QChart::AllAnimations);

    //schimbam axele (categoriile)
    QCategoryAxis *axisX = new QCategoryAxis();
    axisX->append("2013", 0);
    axisX->append("2014", 0);
    axisX->append("2015", 1);
    axisX->append("2016", 2);
    axisX->append("2017", 3);
    axisX->append("2018", 4);
    axisX->append("2019", 5);
    chart->setAxisX(axisX, series);

    //afisam chartul
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);



    QMainWindow w;
    w.setCentralWidget(chartView);
    w.resize(420, 300);
    w.show();
    return a.exec();
}






















