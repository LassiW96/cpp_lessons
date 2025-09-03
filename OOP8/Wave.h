///////////////////////////////////////////////////////////////////////////////
// Header file of the single wave forming part of the class
//
///////////////////////////////////////////////////////////////////////////////

# pragma once
# include <cmath>

class Wave {
private:
    double frequency;
    double amplitude;
    double phase;

public:
    Wave (double freq, double amp = 1.0, double phase = 0.0)
    : frequency(freq), amplitude(amp), phase(phase) {}

    // Function to generate the wave pattern - A sin(2 pi f t + phi)
    double GetValue(double t) const {
        return amplitude * std::sin(2 * M_PI * frequency * t + phase);
    }
};
