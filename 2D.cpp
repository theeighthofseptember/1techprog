#include "2D.h"
#include <iostream>
#include <fstream>

F2D::F2D() {
#ifdef DEBUG
	std::cout << "Constructor F2D\n";
#endif // DEBUG	
	type = "";
	paint = "";
	square = 0;
	size.height = 0;
	size.width = 0;

}

F2D::~F2D() {
#ifdef DEBUG
	std::cout << "Destructor F2D\n";
#endif // DEBUG	
}

F2D::F2D(F2D& f2D) {
#ifdef DEBUG
	std::cout << "Constructor copy F2D\n";
#endif // DEBUG	
	type = f2D.type;
	paint = f2D.paint;
	size.height = f2D.size.height;
	size.width = f2D.size.width;
	square = f2D.square;


}

void F2D::display() {
	std::cout << "F2D\n";
	std::cout << "type \t\t:\t" << type << '\n';
	std::cout << "paint \t\t:\t" << paint << '\n';
	std::cout << "height \t\t:\t" << size.height << '\n';
	std::cout << "width \t\t:\t" << size.width << '\n';
	std::cout << "square \t\t:\t" << square << '\n';


}

void F2D::setData() {
	std::cout << "F2D\n";
	std::cout << "type(str) \t:\t"; std::cin >> type; std::cout << '\n';
	std::cout << "paint(str) \t:\t"; std::cin >> paint; std::cout << '\n';
	std::cout << "height(int) \t:\t"; std::cin >> size.height; std::cout << '\n';
	std::cout << "width(int) \t:\t"; std::cin >> size.width; std::cout << '\n';
	std::cout << "square(int) \t:\t"; std::cin >> square; std::cout << '\n';


}

void F2D::fileDisplay(std::ofstream& out) {
	out << "F2D\n";
	out << "type \t\t:\t" << type << '\n';
	out << "paint \t\t:\t" << paint << '\n';
	out << "height \t\t:\t" << size.height << '\n';
	out << "width \t\t:\t" << size.width << '\n';
	out << "square \t\t:\t" << square << '\n';

}

void F2D::fileSetData(std::ifstream& in) {
	in >> type;
	in >> paint;
	in >> size.height;
	in >> size.width;
	in >> square;

}