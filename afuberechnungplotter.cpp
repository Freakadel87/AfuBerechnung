//#include <QtGui>
//#include <cmath>

//#include <afuberechnungplotter.h>

//AfuBerechnungPlotter::AfuBerechnungPlotter(QWidget *parent)
//    : QWidget(parent)
//{
//    setBackgroundRole(QPalette::Dark);
//    setAutoFillBackground(true);
//    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    setFocusPolicy(Qt::StrongFocus);
//    RubberBandIsShown = false;

//    ZoomInButton = new QToolButton(this);
//    //ZoomInButton.setIcon
//    ZoomInButton->adjustSize();
//    connect(ZoomInButton, SIGNAL(clicked()), this, SLOT(ZoomIn()));

//    ZoomOutButton = new QToolButton(this);
//    //ZoomOutButton.setIcon
//    ZoomOutButton->adjustSize();
//    connect(ZoomOutButton, SIGNAL(clicked()), this, SLOT(ZoomOut()));

//    SetPlotSettings(PlotSettings());
//}

//void AfuBerechnungPlotter::SetPlotSettings(const PlotSettings &settings)
//{
//    ZoomStack.clear();
//    ZoomStack.append(settings);
//    CurZoom = 0;
//    ZoomInButton->hide();
//    ZoomOutButton->hide();
//    RefreshPixmap();
//}

//void AfuBerechnungPlotter::ZoomOut()
//{
//    if(CurZoom > 0)
//    {
//        --CurZoom;
//        ZoomOutButton->setEnabled(CurZoom > 0);
//        ZoomInButton->setEnabled(true);
//        ZoomInButton->show();
//        RefreshPixmap();
//    }
//}

//void AfuBerechnungPlotter::ZoomIn()
//{
//    if(CurZoom < ZoomStack.count() - 1)
//    {
//        ++CurZoom;
//        ZoomInButton->setEnabled(CurZoom < ZoomStack.count() - 1);
//        ZoomOutButton->setEnabled(true);
//        ZoomOutButton->show();
//        RefreshPixmap();
//    }
//}

//void AfuBerechnungPlotter::SetCurveData(int id, const QVector<QPointF> &data)
//{
//    CurveMap[id] = data;
//    RefreshPixmap();
//}

//void AfuBerechnungPlotter::ClearCurve(int id)
//{
//    CurveMap.remove(id);
//    RefreshPixmap();
//}

//QSize AfuBerechnungPlotter::MinimumSizeHint() const
//{
//    return QSize(6 * Margin, 4 * Margin);
//}

//QSize AfuBerechnungPlotter::SizeHint() const
//{
//    return QSize(12 * Margin, 8 * Margin);
//}

//void AfuBerechnungPlotter::PaintEvent(QPaintEvent */*event*/)
//{
//    QStylePainter painter(this);
//    painter.drawPixmap(0,0,Pixmap);

//    if(RubberBandIsShown)
//    {
//        painter.setPen(palette().light().color());
//        painter.drawRect(RubberBandRect.normalized()
//                         .adjusted(0,0,-1,-1));
//    }

//    if(hasFocus())
//    {
//        QStyleOptionFocusRect option;
//        option.initFrom(this);
//        option.backgroundColor = palette().dark().color();
//        painter.drawPrimitive(QStyle::PE_FrameFocusRect, option);
//    }
//}

