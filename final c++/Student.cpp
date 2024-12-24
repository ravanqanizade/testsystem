#include "Student.h"

Student::Student(std::string name, std::string surname, std::string password) : name(name), surname(surname), password(password) {}

Student::Student() : name(""), surname(""), password("") {}

std::string Student::getName() const {
    return name;
}

std::string Student::getSurname() const {
    return surname;
}

std::string Student::getPassword() const {
    return password;
}

void Student::setName(const std::string& newName) { name = newName; }
void Student::setSurname(const std::string& newSurname) { surname = newSurname; }
void Student::setPassword(const std::string& newPassword) { password = newPassword; }