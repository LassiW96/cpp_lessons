//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main script of the class
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

# include "Experiment.h"
# include "Scintillator.h"
# include "Calorimeter.h"

int main () {
    // Set up the experiment
    Experiment exp;

    // Create detectors on the heap
    Detector* S1 = new Scintillator("S1");
    Detector* S2 = new Scintillator("S2");
    Detector* C1 = new Calorimeter("C1");

    // Add detectors into the experiment 
    exp.AddDetector(S1);
    exp.AddDetector(S2);
    exp.AddDetector(C1);

    for (const auto& det : exp.GetDetectors()) {
        std::cout << "Detector: " << det->GetName() << std::endl;   // Get the name of the cooresponding detector
        det->ReadData();    // Accessing ReadData() method through virtual functions
    }

    return 0;       // Memory cleanup
}
