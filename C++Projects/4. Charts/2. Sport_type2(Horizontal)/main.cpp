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

QT_CHARTS_USE_NAMESPACE //namespace pentru charts

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //atribuim nume diferitelor bare din chart
    QBarSet *set0 = new QBarSet("Steaua");
    QBarSet *set1 = new QBarSet("Dinamo");
    QBarSet *set2 = new QBarSet("Rapid");
    QBarSet *set3 = new QBarSet("FC Botosani");
    QBarSet *set4 = new QBarSet("CSM Iasi");

    //stabilim cate goluri au dat pe sezon (sub diferite variatii)
    *set0 << 234 << 245 << 341 << 313 << 231 << 320;
    *set1 << 271 << 200 << 300 << 410 << 351 << 450;
    *set2 << 223 << 299 << 347 << 376 << 411 << 220;
    *set3 << 201 << 234 << 365 << 422 << 171 << 350;
    *set4 << 211 << 212 << 399 << 399 << 211 << 320;

    //adaugam numarul de goluri chartului
    QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
    series->append(set0);//legam toate informatiile de seria noastra
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    //definim bara chart pe care vrem sa o afisam
    QChart *chart = new QChart();
    chart->addSeries(series); //adaugam seriile (nr de goluri)
    chart->setTitle("Goals scored each year");
    chart->setAnimationOptions(QChart::AllAnimations); //toate animatiile; alte optiuni pt animatii: NoAnimation, GridAxisAnimations, SeriesAnimations
    QStringList categories;//definesc titlurile categoriilor
    categories << "2015" << "2016" << "2017" << "2018" << "2019"<< "2020";
    QBarCategoryAxis *axis = new QBarCategoryAxis();//adaugam categoriile -> axelor
    axis->append(categories); //add categorii
    chart->createDefaultAxes();
    chart->setAxisY(axis, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    //Cream un QChartView pentru a afisa chartul, apoi dam culoare
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::Text, QRgb(0x404040));
    qApp->setPalette(pal);




    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(420, 300);
    window.show();

    return a.exec();
}
