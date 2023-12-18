#pragma once
#include "Figures.h"
#include <iostream>
#include <fstream>
#include "3D.h"
#include "2D.h"

class Keeper {

private:

    class Element {        //  one Element in keeper
    public:
        Figures* value;
        Element* prev;

        Element(Figures* data, Element* prev = nullptr) {
#ifdef DEBUG
            std::cout << "Constructor Element\n";
#endif // DEBUG	
            this->value = data;
            this->prev = prev;
        }
        ~Element() {
            delete this->value;
            //delete this->prev;
        }
    };
    int count;
    Element* head;
    Element* help;

public:
    Keeper() {
#ifdef DEBUG
        std::cout << "Constuctor Keeper\n";
#endif // DEBUG	
        count = 0;
        head = nullptr;
        help = nullptr;
    }

    ~Keeper() {
#ifdef DEBUG
        std::cout << "Destructor Keeper\n";
#endif // DEBUG	
        while (head != nullptr && count != 0) {
            help = head;
            head = head->prev;
            delete help;
            count--;
        }
        delete head;
    }

    int getCount() { return count; }

    Figures& operator[] (const int index) {
        int cnt = getCount();
        Element* cur;
        cur = this->head;

        while (cur != nullptr) {
            if (cnt == index) {
                return  *(cur->value);
            }
            cur = cur->prev;
            cnt--;
        }
    }

    void addElement(Figures* x) {
        if (head == nullptr) {
            head = new Element(x);
            head->value = x;
        }
        else {
            help = new Element(x);
            help->prev = head;
            head = help;
            head->value = x;
        }
        count++;
    }

    void deleteElement(const int index) {	//

        if (getCount() == 1) {	//1 elem = head
            delete this->head;
            head = nullptr;
            count--;
        }
        else if (index == getCount()) {	//last
            Element* cur = this->head;
            head = head->prev;
            delete cur;
            count--;
        }
        else {		//not last and >1 elem
            Element* cur = this->head;
            Element* current1 = this->head;
            int c = getCount();
            bool flag = 0;
            while (flag != 1) {
                if (c == index) {
                    int r = getCount();
                    while (r != (c + 1)) {
                        current1 = current1->prev;
                        r--;
                    }
                    Element* temp = cur;
                    cur = cur->prev;
                    current1->prev = cur;
                    delete temp;
                    flag = 1;
                    count--;

                }
                else {
                    cur = cur->prev;
                    c--;
                }
            }
        }
    }

    void displayKeep() {
        try {
            if (getCount() == 0) throw std::exception("Keeper is empty\n");
            std::cout << "\nAll Elements" << std::endl;

            /*for (int i = 1;i < getCount() + 1;i++) {                          //display from 1 to Count //slower
                std::cout << "-------Element # " << i << "-------" << std::endl;
                (*this)[i].display();
            }*/

            help = head;                                                        //display from Count to 1 //faster
            int i = getCount();                                                 //because i use keeper as queue (head = #-count Element
            while (help != nullptr && i != 0) {

                std::cout << "-------Element # " << i << "-------" << std::endl;
                (help->value)->display();
                help = help->prev;
                i--;
            }
            std::cout << "\nCount of Elements: " << getCount() << std::endl << std::endl;
        }
        catch (const std::exception& ex) {

            std::cout << ex.what() << '\n';
        }
    }

    void editElement(const int index) {
        std::cout << "\nChange Data\n";
        (*this)[index].setData();
    }


    void fileDisplayKeep() {
        std::ofstream out;          //
        out.open("out.txt", std::ios::out);         //delete prev data in file   
        //std::ios::app - save prev data in file  
        try {
            if (!out.is_open()) throw std::exception("File don't open\n");
            if (getCount() == 0) out << "Keeper is empty\n";
            std::cout << "yeah\n";
            for (int i = 1; i < getCount() + 1; ++i) {
                out << "-------Element # " << i << "-------\n";

                //code for definition a type of element
                if (sizeof((*this)[i]) == sizeof(F2D)) {
                    out << "type::F2D\n";
                }
                else if (sizeof((*this)[i]) == sizeof(F3D)) {
                    out << "type::F3D\n";
                }

                (*this)[i].fileDisplay(out);
                out << '\n';
            }
        }
        catch (const std::exception& ex) {
            std::cout << ex.what();
        }
        out.close();
    }

    void fileSetDataKeep() {
        int countElementFile = 0;
        F2D* f2D;
        F3D* f3D;
        std::string str;
        std::ifstream in;          
        in.open("in.txt");      

        try {
            if (!in.is_open()) throw std::exception("File don't open\n");
            std::cout << "yeah\n";
            if (in.eof()) throw std::exception("File is empty\n");
            in >> countElementFile;
            for (int i = 0; i < countElementFile; i++) {

                in >> str;
                if (str == "F2D") {
                    f2D = new F2D;
                    f2D->fileSetData(in);
                    this->addElement(f2D);
                }
                else if (str == "F3D") {
                    f3D = new F3D;
                    f3D->fileSetData(in);
                    this->addElement(f3D);
                }

            }
        }
        catch (const std::exception& ex) {
            std::cout << ex.what();
        }
        in.close();
    }
};