#pragma once
#include "Figures.h"
#include <iostream>
/*Для плоской
фигуры определено: тип, размеры, площадь, рисунок на экране. Для объемной
фигуры определено: тип, размеры, объем, рисунок на экране в виде плоской
фигуры*/
struct Size2D {
	int height;
	int width;
};

class F2D : public Figures {
private:
	std::string type;
	Size2D size;
	int square;
	std::string paint;

public:
	~F2D();
	F2D();
	F2D(F2D& f2D);

	void display() override;
	void setData() override;
	void fileDisplay(std::ofstream& out) override;
	void fileSetData(std::ifstream& in) override;
};