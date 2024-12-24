
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class Question {
private:
    std::string question;
    std::string subject;
    std::string answer1;
    std::string answer2;
    std::string answer3;
    std::string correctAnswer;
public:
    Question(std::string question, std::string subject, std::string answer1, std::string answer2, std::string answer3, std::string correctAnswer);

    std::string getQuestion() const;
    std::string getSubject() const;
    std::string getAnswer1() const;
    std::string getAnswer2() const;
    std::string getAnswer3() const;
    std::string getcorrectAnswer() const;
};


class Test_System
{
private:
    std::vector<Question> test_questions;
public:

    void writeTestsToFile(const std::string& fileName) const;

    void readTestsFromFile(const std::string& fileName);

    void addQuestion(std::string& subject, std::string& question, std::string& answer1, std::string& answer2, std::string& answer3, std::string& correctAnswer);

    void printQuestions(const std::string& subject, int& currentQuestionIndex) const;

    int getCounterOfTest(std::string& subject) const;



};
