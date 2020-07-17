#ifndef SCRIBBLEAREA_H
#define SCRIBBLEAREA_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>

class ScribbleArea : public QWidget
{
    Q_OBJECT

public:
    ScribbleArea(QWidget *parent = 0);

    // toate evenimentele
    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);

    // modificarile imaginii
    bool isModified() const { return modified; }
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }

public slots:

    // evenimente
    void clearImage();
    void print();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    // actualizarea panoului de desenare
    void paintEvent(QPaintEvent *event) override;

    // ne asiguram ca panoul de desen are aceeasi dimensiune ca MainWindow
    void resizeEvent(QResizeEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);

    // A/F daca a fost sau nu modificat
    bool modified;

    // A/F daca s-a desenat sau nu ceva
    bool scribbling;

    // latimea creionului si culoarea
    int myPenWidth;
    QColor myPenColor;

    // stocheaza imaginea desenata
    QImage image;

    //stocheaza locatia evenimentului realizat de mouse
    QPoint lastPoint;
};

#endif
