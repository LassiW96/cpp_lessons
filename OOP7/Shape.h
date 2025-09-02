////////////////////////////////////////////////////////////////////////////////////////////////////////
// A simple class to get the area of a circle and a square
// Inheritance, static casting & dynamic casting
// 
// This is the base class for shapes - an abstract class
// There are some notes in NotesOnOOP7 text file
////////////////////////////////////////////////////////////////////////////////////////////////////////

# ifndef SHAPE_H
# define SHAPE_H

# include <string>

class Shape {
public:
    virtual ~Shape() {}

    // usung virtual functions - to be, and must be overridden by derived classes
    virtual std::string GetName() const = 0;
    virtual double Area() const = 0;
};

# endif
