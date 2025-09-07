////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Header file for the superposition, when there are more than one waves
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

# pragma once
# include "Wave.h"
# include <vector>

class WaveformGenerator {
private: 
    std::vector<Wave> waves; // Vector to hold multiple wave objects of the class Wave

public:
    // Function to store wave objects in the "waves" vector
    void AddWaves(const Wave& wave) {
        waves.push_back(wave);
    }

    // Main superposition function
    // duration - time duration of the signal
    // TotSamples - how many samples (points you calculate) you want to divide the wave
    //              more samples - smoother curve
    std::vector<double> Generate(double duration, int TotSamples) {
        std::vector<double> Data(TotSamples, 0.0);              // Data vector to store sampled data points, all starts with 0.0

        for (int i = 0; i < TotSamples; i++) {
            // Calculating the time stamp
            double t = (duration * i) / TotSamples;

            // Get the value at the time stamp, add it and create the final Data vector
            for (const auto& w : waves) {
                Data[i] += w.GetValue(t);
            }
        }

        return Data;
    }

};
