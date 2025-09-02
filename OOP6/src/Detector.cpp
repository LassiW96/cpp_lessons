# include "Detector.h"
# include <fstream>
# include <iostream>
# include <sstream>
# include <iomanip>

Detector::Detector() : pedestal_(0.0) {} // Constructor with initial pedestal value 0.0

Detector::~Detector() {} // Virtual destructor

bool Detector::ReadDatabase(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Error: Cannot open the file: " << filename << "\n";
        return false;
    }

    data_.clear(); // Clear any previous data
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty() || line[0] == '#') continue; // Ignore empty lines and comments

        std::istringstream ss(line);
        double x, y, z, fADC;
        // Filling up the vector data_ with the information in lines
        if (ss >> x >> y >> z >> fADC) {
            data_.emplace_back(x, y, z, fADC);
        } else {
            std::cerr << "Error: Malformed line: " << line << "\n"; // Error for malformed lines
        }
    }
    return true;
}

// Applying pedestal corrections
void Detector::ApplyPedestalCorrections(double pedestal) {
    pedestal_ = pedestal; // Saving the given pedestal value in the detectors internal variable pedestal_
    for (auto& rec : data_) {
        double x, y, z, fADC;
        std::tie(x, y, z, fADC) = rec; // Unpacks the tuple into seperate variables
        fADC -= pedestal_; // Substracting the pedestal value from the original fADC value
        rec = std::make_tuple(x, y, z, fADC); // Recreate the tuple with corrected fADC value
    }
}

// Printing the summary to the console
void Detector::PrintSummary() const {
    std::cout << "Detector data summary:\n";
    for (const auto& rec : data_) {
        double x, y, z, fADC;
        std::tie(x, y, z, fADC) = rec;
        std::cout << std::fixed << std::setprecision(2)
                  << "  X=" << x
                  << "  Y=" << y
                  << "  Z=" << z
                  << "  fADC=" << fADC
                  << "\n";
    }
}
