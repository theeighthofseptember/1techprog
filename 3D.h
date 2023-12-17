#pragma once
#include "Figures.h"
#include <iostream>

/*��� �������
������ ����������: ���, �������, �������, ������� �� ������. ��� ��������
������ ����������: ���, �������, �����, ������� �� ������ � ���� �������
������*/
struct Size3D {
	int height;
	int width;
};
class F3D : public Figures {
private:

	std::string type;
	Size3D size;
	int volume;
	std::string paint;

public:
	~F3D();
	F3D();
	F3D(F3D& f3D);

	void display() override;
	void setData() override;
	void fileDisplay(std::ofstream& out) override;
	void fileSetData(std::ifstream& in) override;
};