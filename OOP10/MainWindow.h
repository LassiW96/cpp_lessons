//////////////////////////////////////////////////////////////////////////////////////////////////////
// Header file of the main window of the gui
// Functionality is in the corresponding source file
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

# include <QMainWindow>
# include <QLineEdit>
# include <QSpinBox>
# include <QPushButton>
# include <QVBoxLayout>

# include "WaveWidget.h"
# include "WaveformGenerator.h"
# include "CircularMapper.h"

class MainWindow : public QMainWindow {
    Q_OBJECT;

public:
    MainWindow(QWidget* parent = nullptr);

private slots:
    void OnGenerate();

private:
    QLineEdit* FreqInput;       // Frequency input field for the user
    QSpinBox* CycInput;         // Cycle input field for the user
    QPushButton* GenBtn;        // Generate buttom
    WaveWidget* waveWidget;

};
