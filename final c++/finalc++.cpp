#include <conio.h>
#include "Admin.h"
#include "Test.h"


void saveToFile(Admin& admin, std::string fileName) {
    std::ofstream file(fileName, std::ios::out);
    if (file.is_open()) {
        for (const auto& student : admin.getStudent()) {
            file << student.getName() << " " << student.getSurname() << " " << student.getPassword() << std::endl;
        }
        file.close();
    }
}

void loadFromFile(Admin& admin, std::string fileName) {
    std::ifstream file(fileName);
    if (file.is_open()) {
        std::string name, surname, password;
        while (file >> name >> surname >> password) {
            admin.addStudent(name, surname, password);
        }
        file.close();
    }
}

void printChoiceMenu(int currentOption) {
    system("cls");
    std::cout << (currentOption == 1 ? "\33[1;44m > " : "  ") << "Log in for Admin" << (currentOption == 1 ? " < \033[0m" : "  ") << std::endl;
    std::cout << (currentOption == 2 ? "\33[1;44m > " : "  ") << "Log in for Students" << (currentOption == 2 ? " < \033[0m" : "  ") << std::endl;
}

void printAdminMenu(int searchOption) {
    system("cls");
    std::cout << (searchOption == 1 ? "\33[1;44m > " : "  ") << "Edit students" << (searchOption == 1 ? " < \033[0m" : "  ") << std::endl;
    std::cout << (searchOption == 2 ? "\33[1;44m > " : "  ") << "Edit exams" << (searchOption == 2 ? " < \033[0m" : "  ") << std::endl;
    std::cout << (searchOption == 3 ? "\33[1;44m > " : "  ") << "View exam result" << (searchOption == 3 ? " < \033[0m" : "  ") << std::endl;
    std::cout << (searchOption == 4 ? "\33[1;44m > " : "  ") << "Show students" << (searchOption == 4 ? " < \033[0m" : "  ") << std::endl;
    std::cout << (searchOption == 5 ? "\33[1;44m > " : "  ") << "Return to main menu" << (searchOption == 5 ? " < \033[0m" : "  ") << std::endl;
}

void printStudentMenu(int StudentMenuOption) {
    std::cout << (StudentMenuOption == 1 ? "\33[1;44m > " : "  ") << "Start exam" << (StudentMenuOption == 1 ? " < \033[0m" : "  ") << std::endl;
    std::cout << (StudentMenuOption == 2 ? "\33[1;44m > " : "  ") << "Continue exam" << (StudentMenuOption == 2 ? " < \033[0m" : "  ") << std::endl;
    std::cout << (StudentMenuOption == 3 ? "\33[1;44m > " : "  ") << "View your result" << (StudentMenuOption == 3 ? " < \033[0m" : "  ") << std::endl;
    std::cout << (StudentMenuOption == 4 ? "\33[1;44m > " : "  ") << "Return to main menu" << (StudentMenuOption == 4 ? " < \033[0m" : "  ") << std::endl;
}

void printEditStudentMenu(int EditStudentOption) {
    system("cls");
    std::cout << (EditStudentOption == 1 ? "\33[1;44m > " : "  ") << "Add students" << (EditStudentOption == 1 ? " < \033[0m" : "  ") << std::endl;
    std::cout << (EditStudentOption == 2 ? "\33[1;44m > " : "  ") << "Delete students" << (EditStudentOption == 2 ? " < \033[0m" : "  ") << std::endl;
    std::cout << (EditStudentOption == 3 ? "\33[1;44m > " : "  ") << "Modify students" << (EditStudentOption == 3 ? " < \033[0m" : "  ") << std::endl;
    std::cout << (EditStudentOption == 4 ? "\33[1;44m > " : "  ") << "Return back" << (EditStudentOption == 4 ? " < \033[0m" : "  ") << std::endl;
}

void printEditExamMenu(int EditExamMenuOption) {
    std::cout << (EditExamMenuOption == 1 ? "\33[1;44m > " : "  ") << "Add exam" << (EditExamMenuOption == 1 ? " < \033[0m" : "  ") << std::endl;
    std::cout << (EditExamMenuOption == 2 ? "\33[1;44m > " : "  ") << "Show exam" << (EditExamMenuOption == 2 ? " < \033[0m" : "  ") << std::endl;
    std::cout << (EditExamMenuOption == 3 ? "\33[1;44m > " : "  ") << "Return back" << (EditExamMenuOption == 3 ? " < \033[0m" : "  ") << std::endl;
}

void showStudents(Admin& admin) {
    for (const auto i : admin.getStudent()) {
        std::cout << "Name: " << i.getName() << "    " << "Surname: " << i.getSurname() << "    " << "Password: " << i.getPassword() << std::endl;
    }
}


int main() {
    Admin admin;
    Test_System test;
    Student student;
    int currentOption = 1;
    loadFromFile(admin, "StudentInfo.txt");
    while (true) {
        printChoiceMenu(currentOption);
        char key = _getch();
        if (key == 72) {
            currentOption = (currentOption - 1 < 1) ? 2 : currentOption - 1;
        }
        else if (key == 80) {
            currentOption = (currentOption + 1 > 2) ? 1 : currentOption + 1;
        }
        else if (key == 13) {
            switch (currentOption) {
            case 1: {
                system("cls");
                int searchOption = 1;
                bool searchMenuActive = true;
                std::string AdminLogin;
                std::string AdminPass;
                std::cout << "Log in: ";
                std::getline(std::cin, AdminLogin);
                std::cout << "Password: ";
                std::getline(std::cin, AdminPass);
                if (AdminLogin == "Admin" && AdminPass == "admin") {
                    while (searchMenuActive) {
                        system("cls");
                        printAdminMenu(searchOption);
                        char key = _getch();
                        if (key == 72) {
                            searchOption = (searchOption - 1 < 1) ? 5 : searchOption - 1;
                        }
                        else if (key == 80) {
                            searchOption = (searchOption + 1 > 5) ? 1 : searchOption + 1;
                        }
                        else if (key == 13) {
                            switch (searchOption) {
                            case 1: {
                                int EditStudentOption = 1;
                                bool EditStudentMenuActive = true;
                                while (EditStudentMenuActive) {
                                    system("cls");
                                    printEditStudentMenu(EditStudentOption);
                                    char key = _getch();
                                    if (key == 72) {
                                        EditStudentOption = (EditStudentOption - 1 < 1) ? 4 : EditStudentOption - 1;
                                    }
                                    else if (key == 80) {
                                        EditStudentOption = (EditStudentOption + 1 > 4) ? 1 : EditStudentOption + 1;
                                    }
                                    else if (key == 13) {
                                        switch (EditStudentOption) {
                                        case 1: {
                                            system("cls");
                                            std::string StudentName;
                                            std::string StudentSurname;
                                            std::string StudentPass;
                                            std::cout << "Enter name: ";
                                            std::getline(std::cin, StudentName);
                                            std::cout << "Enter surname: ";
                                            std::getline(std::cin, StudentSurname);
                                            std::cout << "Enter password: ";
                                            std::getline(std::cin, StudentPass);
                                            admin.addStudent(StudentName, StudentSurname, StudentPass);
                                            std::cout << "\33[1;42m Student added succesfully \033[0m" << std::endl;
                                            saveToFile(admin, "StudentInfo.txt");
                                            _getch();
                                            break;
                                        }
                                        case 2: {
                                            system("cls");
                                            std::string DelName;
                                            std::string DelSurname;
                                            std::cout << "Enter name to delete: ";
                                            std::getline(std::cin, DelName);
                                            std::cout << "Enter surname to delete: ";
                                            std::getline(std::cin, DelSurname);
                                            admin.deleteStudent(DelName, DelSurname);
                                            saveToFile(admin, "StudentInfo.txt");
                                            break;
                                        }
                                        case 3: {
                                            system("cls");
                                            std::string oldName, oldSurname, newName, newSurname, newPassword;
                                            std::cout << "Enter name to modify: ";
                                            std::getline(std::cin, oldName);
                                            std::cout << "Enter surname to modify: ";
                                            std::getline(std::cin, oldSurname);
                                            system("cls");
                                            std::cout << "Enter new name: ";
                                            std::getline(std::cin, newName);
                                            std::cout << "Enter new surname: ";
                                            std::getline(std::cin, newSurname);
                                            std::cout << "Enter new Password: ";
                                            std::getline(std::cin, newPassword);
                                            admin.modifyStudent(oldName, oldSurname, newName, newSurname, newPassword);
                                            std::cout << "\33[1;42m Student modified succesfully \033[0m" << std::endl;
                                            saveToFile(admin, "StudentInfo.txt");
                                            _getch();
                                            break;
                                        }
                                        case 4: {
                                            EditStudentMenuActive = false;
                                            break;
                                        }

                                        default:
                                            break;
                                        }
                                    }

                                }
                            }
                            case 2: {
                                // Edit exams
                                bool EditExamMenuActive = true;
                                int EditExamMenuOption = 1;
                                while (EditExamMenuActive) {
                                    system("cls");
                                    printEditExamMenu(EditExamMenuOption);
                                    char key = _getch();
                                    if (key == 72) {
                                        EditExamMenuOption = (EditExamMenuOption - 1 < 1) ? 3 : EditExamMenuOption - 1;
                                    }
                                    else if (key == 80) {
                                        EditExamMenuOption = (EditExamMenuOption + 1 > 3) ? 1 : EditExamMenuOption + 1;
                                    }
                                    else if (key == 13) {
                                        switch (EditExamMenuOption) {
                                        case 1: {
                                            //add exam
                                            std::string subject, question, answer1, answer2, answer3, correctAnswer;
                                            std::cout << "Enter the subject name: ";
                                            std::getline(std::cin, subject);
                                            std::cout << "Enter the question: ";
                                            std::getline(std::cin, question);
                                            std::cout << "Enter the answer A: ";
                                            std::getline(std::cin, answer1);
                                            std::cout << "Enter the answer B: ";
                                            std::getline(std::cin, answer2);
                                            std::cout << "Enter the answer C: ";
                                            std::getline(std::cin, answer3);
                                            std::cout << "Enter the correct answer: ";
                                            std::getline(std::cin, correctAnswer);
                                            test.addQuestion(subject, question, answer1, answer2, answer3, correctAnswer);
                                            test.writeTestsToFile("Testsystem.bin");
                                            _getch();
                                            break;
                                        }
                                        case 2: {
                                            _getch();
                                            break;
                                        }
                                        case 3: {
                                            EditExamMenuActive = false;
                                            break;
                                        }
                                        default: {

                                            break;
                                        }
                                        }
                                    }

                                }
                                break;
                            }
                            case 3: {
                                // View exam result
                                break;
                            }
                            case 4: {
                                system("cls");
                                showStudents(admin);
                                _getch();
                                break;
                            }
                            case 5: {
                                searchMenuActive = false;
                                break;
                            }
                            default: {
                                std::cout << "Wrong choice!" << std::endl;
                                break;
                            }
                            }
                        }
                    }
                }
                else {
                    std::cout << "\33[1;41m Wrong Admin login or password! \033[0m" << std::endl;
                    _getch();
                    break;
                }
                break;
            }
            case 2: {
                int studentMenuOption = 1;
                bool studentMenuActive = true;
                while (studentMenuActive) {
                    system("cls");
                    printStudentMenu(studentMenuOption);
                    char key = _getch();
                    if (key == 72) {
                        studentMenuOption = (studentMenuOption - 1 < 1) ? 4 : studentMenuOption - 1;
                    }
                    else if (key == 80) {
                        studentMenuOption = (studentMenuOption + 1 > 4) ? 1 : studentMenuOption + 1;
                    }
                    else if (key == 13) {
                        switch (studentMenuOption) {
                        case 1: {
                            system("cls");
                            test.readTestsFromFile("Testsystem.bin");
                            std::string subject;
                            std::string choice;
                            int counterOfQuestion = 0;
                            int index = 0;
                            std::cout << "Enter the subject: ";
                            std::getline(std::cin, subject);
                            while (true) {
                                test.printQuestions(subject, index);
                                while (true) {
                                    std::cout << "Enter your choice: ";
                                    std::getline(std::cin, choice);
                                    if (choice == "A" || choice == "B" || choice == "C") {
                                        break;
                                    }
                                    else {
                                        std::cout << "\33[1;41m Wrong choice! Please select A,B or C. \033[0m" << std::endl;
                                    }
                                }
                                counterOfQuestion++;
                                if (counterOfQuestion == test.getCounterOfTest(subject)) {
                                    counterOfQuestion = 0;
                                    break;
                                }
                            }
                            _getch();
                            break;
                        }
                        case 2: {
                            //continue exam
                            break;
                        }
                        case 3: {
                            //view result
                            break;
                        }
                        case 4: {
                            studentMenuActive = false;
                            break;
                        }

                        default: {
                            break;
                        }
                        }
                    }
                }
                break;
            }
            default: {
                std::cout << "Wrong choice!" << std::endl;
                break;
            }
            }
        }
    }

    return 0;
}
