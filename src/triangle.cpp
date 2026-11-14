#include "triangle.hpp"
#include <algorithm>
#include <iostream>
#include <algorithm>

Triangle::Triangle(Point center, std::string name, int base, int height)
		: Shape(center, name), base(base), height(height){}


double Triangle::area() const{
	return (base * height) / 2.0;

}

void Triangle::draw(std::ostream& out) const{
	int offset = std::max(height, base);

	for(int y = 0; y < height; y +=2){
		for(int x = 0; x < (offset -y) /2; ++x){
			out << ' ';
		}

		for(int n = 0; n <=y; ++n)
			out << '*';

		out << std::endl;

	}

}

Triangle* Triangle::clone() const{
	return new Triangle(*this);
}
