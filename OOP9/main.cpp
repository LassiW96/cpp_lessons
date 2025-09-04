///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main script of the 1-D wave to 2-D cicular wave pattern mapping project
//
// This projrct serves the purpose as follows: gets one or more frequencies from the user,
// supperimpose them into one wave, and wrapps it around a circle. Number of cycles around
// the loop is also obtained from the user.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

# include "Wave.h"
# include "WaveformGenerator.h"
# include "CircularMapper.h"

# include <iostream>

using namespace std;

int main() {
    WaveformGenerator WGen;     // Waveform generator object

    // Get the number of frequencies that the user has and store it in Nfreq
    int Nfreq;
    cout << "Enter the number of frquencies: ";
    cin >> Nfreq;

    // Get frequencies, add them, and create a single wave using a loop
    for (int i = 0; i < Nfreq; i++) {
        double freq;
        cout << "Enter the frequency " << (i+1) << " : ";
        cin >> freq;
        
        // Add waves using the generator
        WGen.AddWaves(Wave(freq));
    }

    // Get the number of cycles from the user and store it in Cycles
    int Cycles;
    cout << "Enter the number of cycles around the loop: ";
    cin >> Cycles;

    int Samples = 200;        // Resolution of the waves - hard coded for now.
    double Duration = 1.0;      // Duration of the wave in seconds - this is also hard coded for now

    // Generate the Waveform using the above Duration and samples
    auto WaveForm = WGen.Generate(Duration, Samples);

    // Mapping - get the {x, y} points of the circle
    CicularMapper CMap;     // Circular mapper object
    auto Points = CMap.MapToCircle(WaveForm, Cycles);

    cout << "-----------------------------------------------------------------\n";
    cout << "-----------------------Mapped points-----------------------------\n";
    cout << "-----------------------------------------------------------------\n";

    for (auto& p : Points) {
        cout << p.first << " , " << p.second << endl;
    }

    return 0;
}
