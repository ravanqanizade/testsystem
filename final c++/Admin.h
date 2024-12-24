#include <vector>
#include "Student.h"


class Admin {
private:
    std::vector<Student> students;
public:
    Admin() {}
    void addStudent(std::string& name, std::string& surname, std::string password);
    void deleteStudent(const std::string& delname, const std::string& delsurname);
    void modifyStudent(std::string& oldName, std::string& oldSurname, std::string& newName, std::string& newSurname, std::string& newPassword);
    std::vector<Student> getStudent() const;


};