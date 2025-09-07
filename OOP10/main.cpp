///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main script of the 1-D wave to 2-D cicular wave pattern mapping project
//
// This is the initial QT version main script of the project
// Values are hard coded in this version - may have to change this in the future
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

# include "WaveWidget.h"
# include "Wave.h"
# include "WaveformGenerator.h"
# include "CircularMapper.h"

# include <QApplication>
# include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    // Waveform generator object
    WaveformGenerator Gen;

    // Frequencies to add
    Gen.AddWaves(Wave(432.0));
    Gen.AddWaves(Wave(513.74));
    Gen.AddWaves(Wave(647.27));
    //Gen.AddWaves(Wave(12.5));

    // Duration and the number of samples
    auto waveform = Gen.Generate(0.0625, 500);

    CicularMapper Map;                          // Circular mapper object
    auto points = Map.MapToCircle(waveform, 1); // Mapping of the waveform - # cycles

    // Create the widget
    WaveWidget w(points);
    w.resize(600, 600);                         // Size of the widjet window
    w.show();

    return app.exec();
}
