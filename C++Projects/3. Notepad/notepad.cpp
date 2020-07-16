#include "notepad.h"
#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent): QMainWindow(parent), ui(new Ui::Notepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit); //set textEdit like the central widget (expand on the screen)
}

Notepad::~Notepad()
{
    delete ui;
}

//slot for New
void Notepad::on_actionNew_triggered()
{
    currentFile.clear(); //delete previous file
    ui->textEdit->setText(""); //clear textEdit
}

//slot for Open
void Notepad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file"); //create a dialog box
    QFile file(fileName); //create an object for reading and writing files
    currentFile = fileName; //store fileName
    if (!file.open(QIODevice::ReadOnly | QFile::Text)){ //daca fisierul nu se deschide (poate fi te tip constant)
        QMessageBox::warning(this, "Warning", "Cannot open this file: " + file.errorString()); //error message
        return;
    }

    //daca fisierul se deschide
    setWindowTitle(fileName); //setam titlul
    QTextStream in(&file); //intram in fisier
    QString text = in.readAll(); //citim din fisier
    ui->textEdit->setText(text); //paste in our textEdit
    file.close(); //close that file
}

//slot for save
void Notepad::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as"); //cream un dialog box pentru salvare
    QFile file(fileName); //cream un fisier (obiect) pentru citire/scriere
    currentFile = fileName; //store fileName
    if (!file.open(QFile::WriteOnly | QFile::Text)){ //daca nu se poate scrie in fisier
        QMessageBox::warning(this, "Warning", "Cannot save file" + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);//vom scrie in fisier
    QString text = ui->textEdit->toPlainText();//cream un text in care copiem ceea ce avem in textEdit, facand conversia
    out<<text; //afisam ceea ce am copiat
    file.close();
}

//slot for print
void Notepad::on_actionPrint_triggered()
{
    QPrinter printer; //printer va interactiona cu orice imprimanta detectata
    printer.setPrinterName("Printer");
    QPrintDialog pDialog(&printer, this);//cream un printer dialog
    if (pDialog.exec() == QDialog::Rejected){ //daca nu s-a conectat cu imprimanta
        QMessageBox::warning(this, "Warning", "Cannot acces printer");
        return;
 }
    ui->textEdit->print(&printer); //printam
 }


//slot for exit
void Notepad::on_actionExit_triggered()
{
    QMessageBox msgBox;
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard); // butoane
    msgBox.setDefaultButton(QMessageBox::Save); //buton prestabilit
    int response = msgBox.exec(); //preia legatura Qt
    switch (response){
        case QMessageBox::Save:
            on_actionSave_As_triggered(); //salvam
        break;
    case QMessageBox::Discard:
        QApplication::quit(); //close
        break;
    }

}

//slot for copy
void Notepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

//slot for paste
void Notepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

//slot for cut
void Notepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void Notepad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void Notepad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}
