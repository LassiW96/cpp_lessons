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
    
    WaveformGenerator Gen;                      // Waveform generator object
    Gen.AddWaves(Wave(125.0));                    // 2 Hz wave
    Gen.AddWaves(Wave(62.5));                    // 3 Hz wave
    Gen.AddWaves(Wave(250.0));
    Gen.AddWaves(Wave(12.5));

    auto waveform = Gen.Generate(0.1, 500);     // Waveform of 1.0 second duration and 200 samples

    CicularMapper Map;                          // Circular mapper object
    auto points = Map.MapToCircle(waveform, 1); // Mapping of the waveform - # cycles

    // Create the widget
    WaveWidget w(points);                       // WaveWidget object
    w.resize(400, 400);
    w.show();

    return app.exec();
}
