////////////////////////////////////////////////////////////////////////////////////////////////////////
// Circular mapping part of the generated wave
// This is a mapping of a 1-D wave into a 2-D circular wave loop
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

# pragma once
# include <vector>
# include <utility>
# include <cmath>

class CicularMapper {
public: 
    // Function for the 2-D circle
    // This is a 2-D vector function of the data points in the circle
    std::vector<std::pair<double,double>> MapToCircle(
        const std::vector<double>& waveform,
        int cycles
    ) const {
        // Body of the MapToCircle function
        std::vector<std::pair<double,double>> points;
        int N = waveform.size(); // Size of the waveform vector

        // Mapping loop
        for (int i = 0; i < N; i++) {
            double angle = 2.0 * M_PI * cycles * i / N;     // Angle of the data point in circumference
            double radius = 1.0 + waveform[i];              // Base circle radius + waveform
            
            // Getting the x, y coordinates of the data points
            double x = radius * std::cos(angle);
            double y = radius * std::sin(angle);

            // Store x, y data points in the "points" vector
            points.push_back({x, y});
        }
        return points;
    }

};
