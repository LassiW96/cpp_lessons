///////////////////////////////////////////////////////////////////////////////////////////////
// Source file of the WaveWidget
//
///////////////////////////////////////////////////////////////////////////////////////////////

# include "WaveWidget.h"
# include <QPainter>

//_____________________________________________________________________________________________
// Constructor
WaveWidget::WaveWidget(const std::vector<std::pair<double, double>>& pts, QWidget* parent) 
                        : QWidget(parent), points(pts) {}

//_____________________________________________________________________________________________
// PaintEvent function
void WaveWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    // Center the widget
    int cx = width() / 2;
    int cy = width() / 2;

    // Scaling factor
    double scale = 100.0;

    // Draw polyline
    QPolygonF   poly;
    for (auto& p : points) {
        poly << QPointF(cx + p.first * scale, cy - p.second * scale);
    }
    painter.drawPolyline(poly);
}
