////////////////////////////////////////////////////////////////////////////////////
// A derived class, Squire, of Shape
////////////////////////////////////////////////////////////////////////////////////

# ifndef SQUIRE_H
# define SQUIRE_H

# include "Shape.h"
# include <cmath>

class Squire : public Shape {
private:
    double side;      // private member - side - to be only used inside this class

public:
    Squire(double s);   // Side length of the squire

    // Overriding the virtual, base class function
    std::string GetName() const override;
    double Area() const override;

    double GetSide() const; // Unique function for this class
};

# endif
