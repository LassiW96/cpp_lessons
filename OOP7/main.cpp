///////////////////////////////////////////////////////////////////////////////////
// Main script of the class
// This is an example of how to use static casting and dynamic casting
// Thre is an explanation in the Note
///////////////////////////////////////////////////////////////////////////////////

# include "Circle.h"
# include "Squire.h"
# include <iostream>
# include <vector>

using namespace std;

int main() {
    // Creating objects
    Shape* s1 = new Circle(5.0);            // Circle of radius 5.0
    Shape* s2 = new Squire(3.0);            // Squire of side 3.0

    // Creating a vector for both shapes
    vector<Shape*> shapes = {s1, s2};

    // Loop through shapes in the vector
    for (Shape* shape : shapes) {
        cout << shape->GetName() << " Area: " << shape->Area() << endl;

        // Static casting
        // In order to use static cast, we need to assume that we know the object type
        // Unsafe if the object type is not a Circle
        if (shape->GetName() == "Circle") {
            Circle* c = static_cast<Circle*>(shape);
            cout << "[Static cast] Radius: " << c->GetRadius() << endl;
        }

        // Dynamic casting
        // This is safe - returns a nullptr if the object is not the specified type
        if (Circle* c = dynamic_cast<Circle*>(shape)) {
            cout << "[Dynamic cast] Radius: " << c->GetRadius() << endl;
        }
        else if (Squire* sq = dynamic_cast<Squire*>(shape)) {
            cout << "[Dynamic cast] Side: " << sq->GetSide() << endl;
        }
    }

    // Delete created objects
    for (Shape* shape: shapes) {
        delete shape;
    }

    return 0;
}
