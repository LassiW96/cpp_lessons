/////////////////////////////////////////////////////////////////////////////////////////////////////
// Header file of the Qt widget
// Here, neccessary function for the Widget class is declaired
// Functionality is written in the corresponding cpp file
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

# pragma once
# include <QWidget>
# include <vector>
# include <utility>

class WaveWidget : public QWidget {
    Q_OBJECT

public:
    explicit WaveWidget(const std::vector<std::pair<double, double>>& pts, QWidget* parent = nullptr);

    // Setter function to add frequency points dynamically
    void SetPoints(std::vector<std::pair<double, double>>& pts) { points = pts; }

protected: 
    void paintEvent(QPaintEvent* event) override;

private:
    std::vector<std::pair<double, double>> points;
};
