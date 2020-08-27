#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //Aplicatia principala
    QApplication app(argc, argv);

    // Cream si deschidem fereastra
    MainWindow window;
    window.show();

    // Afisam fereastra principala (o preia qtCreator)
    return app.exec();
}
