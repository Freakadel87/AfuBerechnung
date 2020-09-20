//#ifndef AFUBERECHNUNGPLOTTER_H
//#define AFUBERECHNUNGPLOTTER_H

//#include <QMap>
//#include <QPixmap>
//#include <QVector>
//#include <QWidget>
//#include <QIcon>
//#include <QToolButton>
//#include <QStylePainter>
//#include <QStyleOptionFocusRect>

//class QToolButton;
//class PlotSettings;

//class AfuBerechnungPlotter : public QWidget
//{
//    Q_OBJECT

//public:
//    AfuBerechnungPlotter(QWidget *parent = 0);

//    void SetPlotSettings(const PlotSettings &settings);
//    void SetCurveData(int id, const QVector<QPointF> &data);
//    void ClearCurve(int id);
//    QSize MinimumSizeHint() const;
//    QSize SizeHint() const;

//public slots:
//    void ZoomIn();
//    void ZoomOut();

//protected:
//    void PaintEvent(QPaintEvent *event);
//    void ResizeEvent(QResizeEvent *event);
//    void MousePressEvent(QMouseEvent *event);
//    void MouseMoveEvent(QMouseEvent *event);
//    void MouseReleaseEvent(QMouseEvent *event);
//    void KeyPressEvent(QKeyEvent *event);
//    void WheelEvent(QWheelEvent *event);

//private:
//    void UpdateRubberBandRegion();
//    void RefreshPixmap();
//    void DrawGrid(QPainter *painter);
//    void DrawCurves(QPainter *painter);

//    enum { Margin = 50};

//    QToolButton *ZoomInButton;
//    QToolButton *ZoomOutButton;
//    QMap<int, QVector<QPointF> > CurveMap;
//    QVector<PlotSettings> ZoomStack;
//    int CurZoom;
//    bool RubberBandIsShown;
//    QRect RubberBandRect;
//    QPixmap Pixmap;
//};

//class PlotSettings
//{
//public:
//    PlotSettings();

//    void Scroll(int dx, int dy);
//    void Adjust();

//    double SpanX() const { return MaxX - MinX; }
//    double SpanY() const { return MaxY - MinY; }

//    double MinX;
//    double MaxX;
//    int NumXTicks;
//    double MinY;
//    double MaxY;
//    int NumYTicks;

//private:
//    static void adjustAxis(double &min, double &max, int &numTicks);
//};

//#endif // AFUBERECHNUNGPLOTTER_H
