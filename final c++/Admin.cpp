#include "Admin.h"

void Admin::addStudent(std::string& name, std::string& surname, std::string password) {
    students.push_back(Student(name, surname, password));
}

void Admin::deleteStudent(const std::string& delname, const std::string& delsurname) {
    for (auto i = students.begin(); i != students.end(); ++i) {
        if (i->getName() == delname && i->getSurname() == delsurname) {
            students.erase(i);
            break;
        }
    }
}

void Admin::modifyStudent(std::string& oldName, std::string& oldSurname, std::string& newName, std::string& newSurname, std::string& newPassword) {
    for (auto& student : students) {
        if (student.getName() == oldName && student.getSurname() == oldSurname) {
            student.setName(newName);
            student.setSurname(newSurname);
            student.setPassword(newPassword);
            break;
        }
    }
}


std::vector<Student> Admin::getStudent() const {
    return students;
}


