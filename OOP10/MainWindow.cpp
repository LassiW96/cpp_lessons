///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Source file of the Main Window
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

# include "MainWindow.h"
# include <QStringList>

//_________________________________________________________________________________________________________
// Main Window constructor

MainWindow::MainWindow(QWidget* parent)
            : QMainWindow(parent) 
{
    QWidget* central = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(central);

    FreqInput = new QLineEdit("432.0, 513.74, 647.27, ...", this);
    // Two arguments are:
    // Text that will already appear when the app starts, and the pointer to the main window object "this"

    CycInput = new QSpinBox(this);  // Cycle input box

    CycInput->setRange(1, 20);      // Range of cycle values
    CycInput->setValue(1);          // Takes only one value

    // Generate button
    // Agin arguments are as described above
    GenBtn = new QPushButton("Generate", this);

    waveWidget = new WaveWidget({}, this);  // Start fresh

    // Adding widgets to the layout
    layout->addWidget(FreqInput);
    layout->addWidget(CycInput);
    layout->addWidget(GenBtn);
    layout->addWidget(waveWidget);

    setCentralWidget(central);

    connect(GenBtn, &QPushButton::clicked, this, &MainWindow::OnGenerate);
}

//____________________________________________________________________________________________________________
// OnGenerate - wavrform generation and wrapping function

void MainWindow::OnGenerate() 
{
    QString text = FreqInput->text();
    QStringList parts = text.split(",", Qt::SkipEmptyParts);    // Split the word from "," and skip white spaces

    WaveformGenerator Gen;
    for (QString& part : parts) {
        bool ok;
        double f = part.trimmed().toDouble(&ok);    // Convert the trimmed word into a double

        if (ok) {
            Gen.AddWaves(Wave(f));
        }
    }

    // Generate waves from the created array
    // Hard coding the duration and the # of samples for now
    double duration = 0.0625;
    int samples = 500;

    auto waveform = Gen.Generate(duration, samples);

    // Mapping
    CicularMapper Map;
    auto points = Map.MapToCircle(waveform, CycInput->value());

    waveWidget->SetPoints(points);
    waveWidget->update();

}
