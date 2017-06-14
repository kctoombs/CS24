// rugfit.cpp - calculates fit of rug to a floor
// Aaron Chang, Kenneth Toombs. 10/13/14

#include <iostream>
using namespace std;

// definition of class Rectangle
// (usually would be in a separate file named rectangle.h)
class Rectangle {

public:
    // declare constructor and get/set methods (already done)
    Rectangle(double w, double l);  // constructor
    double getWidth() const;        // accessor for width
    double getLength() const;       // accessor for length
    void setWidth(double);          // mutator for width
    void setLength(double);         // mutator for length

    // DECLARE (const) METHOD TO RETURN AREA OF RECTANGLE
    
    double Area() const;
private:
    double width, length;

}; // end of class definition

// implementation of class Rectangle here to main function
// (usually would be in a separate file named rectangle.cpp,
// and this separate file would #include "rectangle.h")

// implement constructor
Rectangle::Rectangle(double w, double l) : width(w), length(l) {
} // no constructor body: use initialization list

// implement accessors and mutators for width and length
double Rectangle::getWidth() const {
    return width;
}
double Rectangle::getLength() const {
    return length;
}
void Rectangle::setWidth(double w) {
    width = w;
}
void Rectangle::setLength(double l) {
    length = l;
}

// IMPLEMENT THE AREA METHOD HERE
double Rectangle::Area() const {
  return length*width;
}




// change main where instructed in UPPER CASE below
// (usually would #include "rectangle.h" before main)
int main() {
    
    double width, length;

    // create Rectangle named "floor" for sizes input by user
    cout << "enter width and length of floor: ";
    cin >> width >> length;
    Rectangle floor(width, length);

    // CREATE Rectangle NAMED "rug" FOR SIZES INPUT BY USER
    cout << "enter width and length of rug: ";
    cin >> width >> length;
    Rectangle rug(width, length);
    
    
    
    

    // FIX TO FIND AREAS OF floor AND rug (USING Rectangle::area)
    // floor.Area();
    // rug.Area();

    // print results
    cout << "floor area: " << floor.Area() << endl;
    cout << "rug area: " << rug.Area() << endl;
    double leftover = rug.Area() - floor.Area();
    cout << "leftover rug area: " <<
        (leftover > 0 ? leftover : 0) << endl;
    cout << "empty floor area: " <<
        (leftover < 0 ? -leftover : 0) << endl;

    return 0;
}
