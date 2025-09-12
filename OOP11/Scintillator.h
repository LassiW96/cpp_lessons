/////////////////////////////////////////////////////////////////////////////////////////////////////
// Scintillator class of the simple analyzer project
// Inherited from Detector.h
//
// Functionality:
//      - Just returns a text to the console
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

# ifndef SCINTILLATOR_H
# define SCINTILLATOR_H

# include "Detector.h"

class Scintillator : public Detector {
public:
    Scintillator(const std::string& name) : Detector(name) {}   // Constructor

//__________________________________________________________________________________________________
// ReadData function
    void ReadData() const override 
    {
        std::cout << "Reading light pulses from the Scintillator: " << fname << std::endl;
    }
};

# endif
