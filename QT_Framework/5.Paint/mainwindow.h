#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>

class ScribbleArea; //clasa care ne ajuta sa desenam (scribble - mazgaleala)

class MainWindow : public QMainWindow
{

    Q_OBJECT //clasa de baza pentru toate widgeturile

public:
    MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override; //inchidere eveniment

// evenimente pt SLOT
private slots:
    void open();
    void save();
    void penColor();
    void penWidth();
    void about();

private:
    // actiunile utilizatorului
    void createActions();
    void createMenus();

    // verifica daca s-a salvat
    bool maybeSave();

    // Deschide fereastra de salvare si salveaza
    bool saveFile(const QByteArray &fileFormat);

    // ceea ce vom desena
    ScribbleArea *scribbleArea;

    // widgeturile din meniu
    QMenu *saveAsMenu;
    QMenu *fileMenu;
    QMenu *optionMenu;
    QMenu *helpMenu;

    // toate actiunile
    QAction *openAct;

    // actiuni in functie de tip
    QList<QAction *> saveAsActs;
    QAction *exitAct;
    QAction *penColorAct;
    QAction *penWidthAct;
    QAction *printAct;
    QAction *clearScreenAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
};

#endif
