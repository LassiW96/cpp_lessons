/////////////////////////////////////////////////////////////////////////////////////////////////////
// Calorimeter class of the simple analyzer project
// Inherits from the Detector class
//
// Functionality:
//      - Just returns a text to the console
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

# ifndef CALORIMETER_H
# define CALORIMETER_H

# include "Detector.h"

class Calorimeter : public Detector {
public:
    Calorimeter(const std::string& name) : Detector(name) {}    // Constructor

//____________________________________________________________________________________________________
// ReadData function
    void ReadData() const override
    {
        std::cout << "Reading deposited energy values from the Calorimeter: " << fname << std::endl;
    }
};

# endif
