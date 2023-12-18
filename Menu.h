#pragma once

#include "Figures.h"
#include "2D.h"
#include "3D.h"
#include "Keepeer.h"

int action;
int actionAdd;
int val = 0;

void MenuMain() {

	std::cout << "Select command\n";
	std::cout << "1 - Add Element\n";
	std::cout << "2 - Delete Element\n";
	std::cout << "3 - Change Element\n";
	std::cout << "4 - Display\n";
	std::cout << "5 - Save to file\n";
	std::cout << "6 - Extract from file\n";
	std::cout << "0 - Exit\n";
	std::cout << "Your choice: ";
	while (!(std::cin >> action)) {
		std::cout << "Select comand again.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		if (std::cin >> action)
			break;
	}
}

void MenuAddPrint() {
	std::cout << "Select type of Element\n";
	std::cout << "1 - 2D\n";
	std::cout << "2 - 3D\n";
	std::cout << "0 - Exit\n";
	std::cout << "Your choice: ";
	while (!(std::cin >> actionAdd)) {
		std::cout << "Select comand again.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		if (std::cin >> actionAdd)
			break;
	}
}

void MenuAdd(Keeper* keep) {
	actionAdd = 1;
	F2D* f2D;
	F3D* f3D;


	while (actionAdd != 0) {
		MenuAddPrint();
		switch (actionAdd) {
		case 0:
			break;
		case 1:
			system("cls");

			f2D = new F2D;
			f2D->setData();
			keep->addElement(f2D);

			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");

			f3D = new F3D;
			f3D->setData();
			keep->addElement(f3D);

			system("pause");
			system("cls");
			break;
		default:
			system("cls");

			std::cout << "Select comand again.\n";

			system("pause");
			system("cls");
			break;
		}
	}
}

void Menu() {
	Keeper* keep = new Keeper;
	action = 1;

	while (action != 0) {
		MenuMain();
		switch (action) {
		case 0:
			break;
		case 1:
			system("cls");

			MenuAdd(keep);

			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			try {
				if (keep->getCount() == 0) throw std::exception("Keeper is empty\n");
				val = 0;
				std::cout << "Index of Elemnt to delete: ";
				while (!(std::cin >> val)) {
					std::cout << "Index of Elemnt to delete: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
					if (std::cin >> val)
						break;
				}
				if (val <= 0) throw std::exception("Index cannot <0 or =0\n");
				if (keep->getCount() < val)  throw std::exception("This Element doesn't exist\n");
				(*(keep))[val].display();
				keep->deleteElement(val);
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << '\n';
			}

			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");

			try {
				if (keep->getCount() == 0) throw std::exception("Keeper is empty\n");
				val = 0;
				std::cout << "Index of Elemnt to edit: ";
				while (!(std::cin >> val)) {
					std::cout << "Index of Elemnt to edit: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
					if (std::cin >> val)
						break;
				}
				if (val <= 0) throw std::exception("Index cannot <0 or =0\n");
				if (keep->getCount() < val)  throw std::exception("This Element doesn't exist\n");
				(*(keep))[val].display();
				keep->editElement(val);
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << '\n';
			}

			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");

			keep->displayKeep();

			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");

			keep->fileDisplayKeep();

			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");

			keep->fileSetDataKeep();

			system("pause");
			system("cls");
			break;
		default:
			system("cls");

			std::cout << "Select comand again.\n";

			system("pause");
			system("cls");
			break;
		}
	}
	delete keep;
};