/////////////////////////////////////////////////////////////////////////////////////////////////////
// Detector class of the simple analyzer project
// There are more information in the OOP11Notes.txt
//
// Functionality:
//      - Base class for derived detectors : Scintillator & Calorimeter
//      - Creates virtual functions to be overriden in derived classes
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

# ifndef DETECTOR_H
# define DETECTOR_H

# include <string>
# include <iostream>
class Detector {
public:
Detector(const std::string& name) : fname(name) {}  // Constructor
virtual ~Detector() {};                                // Destructor - make virtual in base classes

//____________________________________________________________________________________________________
// Methods

// Just a void function to return what the detector is doing 
virtual void ReadData() const = 0;

// Method to return the name of the detector
const std::string& GetName() const
{
    return fname;
}

protected:
std::string fname;      // Member variable

};

# endif
