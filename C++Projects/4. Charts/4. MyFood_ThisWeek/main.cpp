//The influence of TV Media – last 7 years

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

    //placinta
    QPieSeries *series = new QPieSeries();
    series->append("Salads", .40);
    series->append("Soups", .20);
    series->append("Fruits", .15);
    series->append("Meet", .10);
    series->append("Milk/Cheese", .10);
    series->append("Bread", .05);

    //bucatile placintei
    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();
    // -->
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setLabelVisible();//etichetele sunt invizibile by default
    // -->
    QPieSlice *slice2 = series->slices().at(2);
    slice2->setExploded();
    slice2->setLabelVisible();
    slice2->setPen(QPen(Qt::darkGreen, 3));
    slice2->setBrush(Qt::green);
    // -->
    QPieSlice *slice3 = series->slices().at(3);
    slice3->setLabelVisible();
    // -->
    QPieSlice *slice4 = series->slices().at(4);
    slice4->setLabelVisible();
    // -->
    QPieSlice *slice5 = series->slices().at(5);
    slice5->setLabelVisible();

    //chartul in sine
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("My food for this week");
    chart->legend()->hide(); //ascundem legenda

    //font
    QFont font;
    font.setPixelSize(18);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::darkGreen));

    //afisare chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow w;
    w.setCentralWidget(chartView);
    w.resize(500, 350);
    w.show();
    return a.exec();
}






















