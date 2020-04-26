//
// Created by student on 20.04.2020.
//

#ifndef POBIPROJECT_STUDENT_HPP
#define POBIPROJECT_STUDENT_HPP
#include <string>

struct Student {
    Student(std::string imie, std::string nazwisko, double x, double y, int sila);

    std::string imie;
    std::string nazwisko;
    double x;
    double y;
    int sila;

    void print();

};

#endif //POBIPROJECT_STUDENT_HPP
