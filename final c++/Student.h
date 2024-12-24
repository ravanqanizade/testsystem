#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    std::string surname;
    std::string password;
public:
    Student();

    Student(std::string name, std::string surname, std::string password);

    std::string getName() const;
    std::string getSurname() const;
    std::string getPassword() const;

    void setName(const std::string& newName);
    void setSurname(const std::string& newSurname);
    void setPassword(const std::string& newPassword);

};