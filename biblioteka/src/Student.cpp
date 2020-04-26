//
// Created by student on 20.04.2020.
//
#include "Student.hpp"
#include <iostream>

Student::Student(std::string imie, std::string nazwisko, double x, double y, int sila) {

    this->imie=imie;
    this->nazwisko=nazwisko;
    this->x=x;
    this->y=y;
    this->sila = sila;
}

void Student::print() {

    std::cout<<"Imie:"<<imie<<" "<<nazwisko<<std::endl;
    std::cout<<"Pierwsza wartosc: "<<x<< "  Druga wartosc:" <<y<<std::endl;
    std::cout<<"Sila: "<<sila;

}