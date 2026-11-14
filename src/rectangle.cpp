#include "rectangle.hpp"
#include <iostream>


Rectangle::Rectangle(Point center, std::string name, int width, int height)
		:Shape(center, name), width(width), height(height){}



double Rectangle::area() const {
	return width * height;

}


void Rectangle::draw(std::ostream& out) const{
	for(int y = 0; y < height; y += 2){
		for(int x = 0; x < width; ++x){
			out << '*';
		}
		
		out << std::endl;


	}


}

Rectangle* Rectangle::clone() const{
	return new Rectangle(*this);

}
