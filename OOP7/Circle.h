////////////////////////////////////////////////////////////////////////////////////
// A derived class, Circle, of Shape
////////////////////////////////////////////////////////////////////////////////////

# ifndef CIRCLE_H
# define CIRCLE_H

# include "Shape.h"
# include <cmath>

class Circle : public Shape {
private:
    double radius;      // private member - radius - to be only used inside this class

public:
    Circle(double r);   // Circle of a radius r

    // Overriding the virtual, base class function
    std::string GetName() const override;
    double Area() const override;

    double GetRadius() const; // Unique function for this class
};

# endif
