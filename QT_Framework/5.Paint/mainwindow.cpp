#include <QtWidgets>

#include "mainwindow.h"
#include "ScribbleArea.h"

MainWindow::MainWindow()
{
    // Cream panoul de desen (widget) si il facem central
    scribbleArea = new ScribbleArea;
    setCentralWidget(scribbleArea);

    // cream actiuni si meniuri
    createActions();
    createMenus();

    // setam titlul
    setWindowTitle(tr("Scribble"));

    // dimensionare
    resize(500, 500);
}

// User-il incearca s ainchida aplicatia
void MainWindow::closeEvent(QCloseEvent *event)
{
    // daca mybeSave() = true => nu s-au facut schimbari si se inchide
    if (maybeSave()) {
        event->accept();
    } else {

        // daca au fost facute schimbari, se ignora inchiderea aplicatiei
        event->ignore();
    }
}

// 1. Verificam daca imaginea curenta a fost modificata
// 2. Deschidem o fereastra de dialog pentru a deschide un nou fisier
void MainWindow::open()
{
    // Verificam daca s-au facut modificari de la ultima salvare
    // maybeSave() returneaza true daca nu s-au facut modificari
    if (maybeSave()) {

        // deschidem fisierul, tr seteaza titlul ferestrei, QDir deschide directorul curent
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());

        // Daca avem un nume de fisier, se incarca imagine si se insereaza in panoul de desenare
        if (!fileName.isEmpty())
            scribbleArea->openImage(fileName);
    }
}

// Save as
void MainWindow::save()
{
    // QAction - actiunea utilizatorului (click)
    QAction *action = qobject_cast<QAction *>(sender());

    // Stocheaza multimea de biti a informatiei utilizatorului
    QByteArray fileFormat = action->data().toByteArray();
    saveFile(fileFormat);
}

// Culoarea stiloului
void MainWindow::penColor()
{
    // Stocam culoarea curenta
    QColor newColor = QColorDialog::getColor(scribbleArea->penColor());
    // Schimbam culoarea
    if (newColor.isValid())
        scribbleArea->setPenColor(newColor);
}

// Latimea stiloului
void MainWindow::penWidth()
{
    bool ok;

    // tr - titlu,tr - textul ferestrei, scribbleArea->penWidth() - latimea curenta a stiloului,
    // Definim min, max, step si butonul ok
    int newWidth = QInputDialog::getInt(this, tr("Scribble"),tr("Select pen width:"),scribbleArea->penWidth(),1, 50, 1, &ok);
    // Schimbam grosimea
    if (ok)
        scribbleArea->setPenWidth(newWidth);
}

// dialog about
void MainWindow::about()
{
    QMessageBox::about(this, tr("About Scribble"),tr("<p>This <b> Scribble</b> is awesome!</p>"));
}

// Definim meniul care apeleaza functiile
void MainWindow::createActions()
{
    // actiune legata de meniu
    openAct = new QAction(tr("&Open..."), this);

    // scurtatura
    openAct->setShortcuts(QKeySequence::Open);

    // functionalitate
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    // Lista cu formatele photo; QImageWriter - scrie imaginile in fisiere
    foreach (QByteArray format, QImageWriter::supportedImageFormats()) {
        QString text = tr("%1...").arg(QString(format).toUpper());

        // cream o actiune pentru fiecare format de fisier
        QAction *action = new QAction(text, this);

        // Setam o actiune pentru fiecare format
        action->setData(format);

        // Cand se da click -> save
        connect(action, SIGNAL(triggered()), this, SLOT(save()));

        // Ii atasam fiecare format de fisier lui Save as
        saveAsActs.append(action);
    }

    // printare
    printAct = new QAction(tr("&Print..."), this);
    connect(printAct, SIGNAL(triggered()), scribbleArea, SLOT(print()));

    // exit
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    // culoare stilou
    penColorAct = new QAction(tr("&Pen Color..."), this);
    connect(penColorAct, SIGNAL(triggered()), this, SLOT(penColor()));

    // grosime stilou
    penWidthAct = new QAction(tr("Pen &Width..."), this);
    connect(penWidthAct, SIGNAL(triggered()), this, SLOT(penWidth()));

    // stergere desen
    clearScreenAct = new QAction(tr("&Clear Screen"), this);
    clearScreenAct->setShortcut(tr("Ctrl+L"));
    connect(clearScreenAct, SIGNAL(triggered()),
            scribbleArea, SLOT(clearImage()));

    // despre
    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    // despre Qt
    aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

// bara de meniu
void MainWindow::createMenus()
{
    // Cream Save As si lista cu tipul d efisiere
    saveAsMenu = new QMenu(tr("&Save As"), this);
    foreach (QAction *action, saveAsActs)
        saveAsMenu->addAction(action);

    // Legam toate actiunile de fisier
    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(openAct);
    fileMenu->addMenu(saveAsMenu);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    // Legam toate actiunile de Optiuni
    optionMenu = new QMenu(tr("&Options"), this);
    optionMenu->addAction(penColorAct);
    optionMenu->addAction(penWidthAct);
    optionMenu->addSeparator();
    optionMenu->addAction(clearScreenAct);

    // Legam toate actiunile de Help
    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    // Adaugam itemii barii de meniu
    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(optionMenu);
    menuBar()->addMenu(helpMenu);
}

bool MainWindow::maybeSave()
{
    // Verificam daca s-a schimbat ceva
    if (scribbleArea->isModified()) {
       QMessageBox::StandardButton ret;

       // Titlu, text si butoane
       ret = QMessageBox::warning(this, tr("Scribble"),tr("The image has been modified.\n" "Do you want to save your changes?"),
                          QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

       // Daca este apasat butonul save, se apeleaza salvarea fisierului
        if (ret == QMessageBox::Save) {
            return saveFile("png");

        // Cancel -> nu face nimic
        } else if (ret == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;
}

bool MainWindow::saveFile(const QByteArray &fileFormat)
{
    // Definim cale, nume si tipul default
    QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;

    // Selectam fisierul si formatul preferat + extensii
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                               initialPath,
                               tr("%1 Files (*.%2);;All Files (*)")
                               .arg(QString::fromLatin1(fileFormat.toUpper()))
                               .arg(QString::fromLatin1(fileFormat)));

    // Nu e fisier -> nu facem nimic
    if (fileName.isEmpty()) {
        return false;
    } else {

        // apelam salvarea fisierului
        return scribbleArea->saveImage(fileName, fileFormat.constData());
    }
}
