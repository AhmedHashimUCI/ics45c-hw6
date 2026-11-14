#include <iostream>
#include <string>
#include "picture.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "triangle.hpp"
using namespace std;

int main() {
    Picture collage;

    Circle circle{{0, 0}, "Circle_1", 3};
    Rectangle rectangle{{2, 4}, "Rectangle_1", 6, 4};
    Triangle triangle{{1, 2}, "Triangle_1", 5, 5};
    Square square{{3, 3}, "Square_1", 4};

    collage.add(circle);
    collage.add(rectangle);
    collage.add(triangle);
    collage.add(square);

    std::cout << "Picture:\n";
    collage.print_all(std::cout);

    std::cout << "\nDrawings:\n";
    collage.draw_all(std::cout);

    std::cout << "\nTotal area = "
              << collage.total_area() << '\n';

    return 0;
}
