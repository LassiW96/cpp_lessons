# include "Scintillator_v1.h"
# include <fstream>
# include <iostream>
# include <sstream>

bool Scintillator_v1::ReadDatabase(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Error: cannot open the file; " << filename << "\n"; // If there is no file, print the error
        return false;
    }

    data_.clear(); // Clear previously stored data
    std::string line;
    // Read one line at a time in the input file
    while (std::getline(in, line)) {
        if (line.empty() || line[0] == '#') continue; // Skip empty/comments
        std::istringstream ss(line); // Wrap the line so it can be parsed as an input
        double x, y, z, fADC;
        // Extracting 4 numbers from the string stream
        if (ss >> x >> y >> z >> fADC) {
            data_.emplace_back(x, y, z, fADC); // Appends the vector data_
        } else {
            std::cerr << "Warning: malformed line: " << line << "\n";
        }
    }

    return true;
}

void Scintillator_v1::PrintData() const {
    std::cout << "Read " << data_.size() << " entries:\n";
    for (const auto& rec : data_) {
        double x, y, z, fADC;
        std::tie(x, y, z, fADC) = rec;
        std::cout
            << "    X=" << x
            << "    Y=" << y
            << "    Z=" << z
            << "    fADC=" << fADC
            << "\n";
    }
}
