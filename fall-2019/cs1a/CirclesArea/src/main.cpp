#include "main.hpp"

int main()
{
    int x1 {}, y1 {};
    std::cout << "Enter your center of the circle: ";
    std::cin >> x1 >> y1;

    int x2 {}, y2 {};
    std::cout << "Enter a point on the circle: ";
    std::cin >> x2 >> y2;

    double radius {distance(x1, y1, x2, y2)};
    std::cout << "Distance between two points: " << radius << "\n";
    std::cout << "Radius of the circle is: " << radius << "\n";

    std::cout << "Circumference is: " << circumference(radius) << "\n";
    std::cout << "Area of the circle is: " << area(radius) << "\n";

}