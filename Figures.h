#pragma once
#define DEBUG
#include <iostream>
class Figures {

public:
	virtual ~Figures() {
#ifdef DEBUG
		std::cout << "Destructor Figures\n";
#endif // DEBUG	
	};
	virtual void display() = 0;
	virtual void setData() = 0;
	virtual void fileDisplay(std::ofstream& out) = 0;
	virtual void fileSetData(std::ifstream& in) = 0;
};