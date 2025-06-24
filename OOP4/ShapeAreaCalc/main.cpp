# include "Rectangle.h"
# include "Circle.h"
# include <iostream> 

int main () {
    Rectangle rect(9.0, 10.0);
    Circle circ(16.0);

    std::cout << "Rectangle area: " << rect.area() << std::endl;
    std::cout << "Circle area: " << circ.area() << std::endl;

    return 0;
}
