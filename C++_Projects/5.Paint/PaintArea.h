#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>

class PaintArea:QWidget{
    Q_OBJECT

public:
    PaintArea(QWidget *parent = 0);

    //toate evenimnetele
    bool openImage(const QString &fileName);
    bool saveImages(const QString &fileName, const char *fileFormat);
    void setPenColor (const QColor &newColor);
    void setPenWidth(int newWidth);

    //daca imaginea a fost modificata la ultima salvare
    bool isModified() const{return modified;}
    QColor penColor() const {return myPenColor;}
    int penWidth() const {return myPenWidth;}

public slots:
    void clearImage();
    void print();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override; //actualizarea spatiului de desenare
    void resizeEvent(QResizeEvent *event) override; //ne asiguram ca spatiul de desenare este la fel de mare ca widgetul

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);
    bool modified; //A sau F daca am salvat sau nu modificarile
    bool scribbling; //A sau F daca s-a desenat sau nu ceva
    int myPenWidth;
    QColor myPenColor;
    QImage image; //retine imaginea care a fost desenata
    QPoint lastPoint; //retine locatia la evenimentul curent al mouse-ului
};

#endif // PAINTAREA_H
