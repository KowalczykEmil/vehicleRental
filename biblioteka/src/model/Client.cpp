//
// Created by student on 26.04.2020.
//
#include <model/Client.hpp>
#include <sstream>

Client::Client() {
    std::cout<<"Zostalem wywolany - Konstruktor bezparametrowy"<<std::endl;
}

Client::Client(std::string firstName, std::string lastName, std::string personalID){
    std::cout<<"Zostalem Wywolany - Konstruktor parametrowy "<<std::endl;
    this->firstName = firstName;
    this->lastName = lastName;
    this->personalID = personalID;
}

Client::~Client() {
    std::cout<<"Jestem destruktor i zostalem wywolany. Zniszczono obiekt! "<<std::endl;
}

std::string Client::clientinfo() {
    return firstName + " "+lastName + " "+ personalID;
}

void Client::setLastName(std::string lastName) {
    this->lastName = std::move(lastName);
}

void Client::setFirstName(std::string firstName) {
    this->firstName = std::move(firstName);
}

void Client::setPersonalId(std::string personalID) {
    this->personalID = std::move(personalID);
}
