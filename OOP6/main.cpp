# include <iostream>
# include "Detector.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " detector.dat [pedestal]\n";
        return 1;
    }

    Detector det;
    if (!det.ReadDatabase(argv[1])) {
        return 2;
    }

    if (argc == 3) {
        double pedestal = std::stod(argv[2]);
        det.ApplyPedestalCorrections(pedestal);
    }

    det.PrintSummary();
    return 0;
}
