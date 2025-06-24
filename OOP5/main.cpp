# include <iostream>
# include "Scintillator_v1.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " detmap.dat\n";
        return 1;
    }

    std::string dbFile = argv[1];
    Scintillator_v1 det; // Creating the object, det, from Scintillator_v1 class
    // Executing the ReadDatabase function on dbFile (data base file)
    if (!det.ReadDatabase(dbFile)) {
        return 2;
    }

    det.PrintData(); // Printing the values in the database file
    return 0;
}
