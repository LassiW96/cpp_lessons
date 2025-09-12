//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Experiment class of the simple analyzer project
//
// Functionality:
//      - Mainly sets up experimental conditions 
//      - This has two methods: AddDetector; GetDetector
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

# ifndef EXPERIMENT_H
# define EXPERIMENT_H

# include "Detector.h"
# include <vector>

class Experiment {
public:
Experiment() {}     // Constructor

// Free memory for all detectors in the destructor body
~Experiment() {
    for (auto det : fDetectors) {
        delete det;
    }
}

//_______________________________________________________________________________________________________________
// AddDetector method
// This method adds detectors into the fDetector vector
void AddDetector(Detector* det) 
{
    fDetectors.push_back(det);
}

//_______________________________________________________________________________________________________________
// GetDetector function
// returns the detectors in fDetectors
const std::vector<Detector*>& GetDetectors() const
{
    return fDetectors;
}

private:
std::vector<Detector*> fDetectors;      // Pointer vector for the detectors that is going to be in the experiment

};

# endif
