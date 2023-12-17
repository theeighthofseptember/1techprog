#include "3D.h"
#include <iostream>

#include <fstream>
F3D::F3D() {
#ifdef DEBUG
	std::cout << "Constructor F3D\n";
#endif // DEBUG	
	type = "";
	paint = "";
	volume = 0;
	size.height = 0;
	size.width = 0;

}

F3D::~F3D() {
#ifdef DEBUG
	std::cout << "Destructor F3D\n";
#endif // DEBUG	
}

F3D::F3D(F3D& f3D) {
#ifdef DEBUG
	std::cout << "Constructor copy F3D\n";
#endif // DEBUG	
	type = f3D.type;
	paint = f3D.paint;
	size.height = f3D.size.height;
	size.width = f3D.size.width;
	volume = f3D.volume;

}

void F3D::display() {
	std::cout << "F3D\n";
	std::cout << "type \t\t:\t" << type << '\n';
	std::cout << "paint \t\t:\t" << paint << '\n';
	std::cout << "height \t\t:\t" << size.height << '\n';
	std::cout << "width \t\t:\t" << size.width << '\n';
	std::cout << "volume \t\t:\t" << volume << '\n';

}

void F3D::setData() {
	std::cout << "F3D\n";
	std::cout << "F2D\n";
	std::cout << "type(str) \t:\t"; std::cin >> type; std::cout << '\n';
	std::cout << "paint(str) \t:\t"; std::cin >> paint; std::cout << '\n';
	std::cout << "height(int) \t:\t"; std::cin >> size.height; std::cout << '\n';
	std::cout << "width(int) \t:\t"; std::cin >> size.width; std::cout << '\n';
	std::cout << "volume(int) \t:\t"; std::cin >> volume; std::cout << '\n';

}

void F3D::fileDisplay(std::ofstream& out) {
	out << "F3D\n";
	out << "type \t\t:\t" << type << '\n';
	out << "paint \t\t:\t" << paint << '\n';
	out << "height \t\t:\t" << size.height << '\n';
	out << "width \t\t:\t" << size.width << '\n';
	out << "volume \t\t:\t" << volume << '\n';

}

void F3D::fileSetData(std::ifstream& in) {
	in >> type;
	in >> paint;
	in >> size.height;
	in >> size.width;
	in >> volume;


}