#include <QtWidgets>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QPrinter>
#include <QPrintDialog>
#endif
#endif

#include "ScribbleArea.h"

ScribbleArea::ScribbleArea(QWidget *parent): QWidget(parent)
{
    // Setam widgetul in stanga sus, chiar daca se redimensioneaza
    setAttribute(Qt::WA_StaticContents);

    // Default
    modified = false;
    scribbling = false;
    myPenWidth = 1;
    myPenColor = Qt::blue;
}

// Incarcam imaginea si o inseram in widget
bool ScribbleArea::openImage(const QString &fileName)
{
    QImage loadedImage;

    // Daca nu s-a incarcat imaginea se renunta
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    modified = false;
    update();
    return true;
}

// salvam imaginea curenta
bool ScribbleArea::saveImage(const QString &fileName, const char *fileFormat)
{
    // aici se stocheaza img
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());

    if (visibleImage.save(fileName, fileFormat)) {
        modified = false;
        return true;
    } else {
        return false;
    }
}

// culoare stilou
void ScribbleArea::setPenColor(const QColor &newColor)
{
    myPenColor = newColor;
}

// latime stilou
void ScribbleArea::setPenWidth(int newWidth)
{
    myPenWidth = newWidth;
}

// clear = fundal alb
void ScribbleArea::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    modified = true;
    update();
}

// Daca se apasa butonul mouse-ului, se verifica daca este butonul stang, se comunica pozitia cursorului si se confirma ca se deseneaza
void ScribbleArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        scribbling = true;
    }
}

// Daca se misca mouse-ul (cand e apasat butonul) apelam drawLine (deseneaza) pe toata miscarea
void ScribbleArea::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && scribbling)
        drawLineTo(event->pos());
}

// Daca se elibereaza butonul, oprim desenarea
void ScribbleArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && scribbling) {
        drawLineTo(event->pos());
        scribbling = false;
    }
}

// Qpainter - furnizeaza functii pentru a desena pe widget
//QPaintEvent - trimis catre widgeturi pentru update
void ScribbleArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Returneaza patratul care trebuie actualizat
    QRect dirtyRect = event->rect();

    // Deseneaza
    painter.drawImage(dirtyRect, image, dirtyRect);
}

// Redimensionare
void ScribbleArea::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void ScribbleArea::drawLineTo(const QPoint &endPoint)
{
    // deseneaza in widget
    QPainter painter(&image);

    // setarile initiale ale  stiloului
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));

    // desenam o linise
    painter.drawLine(lastPoint, endPoint);

    // imaginea nu a fost salvata
    modified = true;

    int rad = (myPenWidth / 2) + 2;

    // apelam patratul pentru a fi actualizat
    update(QRect(lastPoint, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));

    // Ultima pozitie unde s-a oprit desenul
    lastPoint = endPoint;
}

// cand se redimensioneaza se creeaza o noua imagine cu modificari
void ScribbleArea::resizeImage(QImage *image, const QSize &newSize)
{
    // Verificam daca trebuie sa redesenam
    if (image->size() == newSize)
        return;

    // Cream o noua imagine pentru si o afisam (alba)
    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));

    // Desenam imaginea
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

// Printam
void ScribbleArea::print()
{

#if QT_CONFIG(printdialog)

    QPrinter printer(QPrinter::HighResolution);

    // Print dialog
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = image.size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(image.rect());
        painter.drawImage(0, 0, image);
    }
#endif // QT_CONFIG(printdialog)
}
