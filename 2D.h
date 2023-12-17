#pragma once
#include "Figures.h"
#include <iostream>
/*��� �������
������ ����������: ���, �������, �������, ������� �� ������. ��� ��������
������ ����������: ���, �������, �����, ������� �� ������ � ���� �������
������*/
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