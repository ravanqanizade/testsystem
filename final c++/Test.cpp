#include "Test.h"


Question::Question(std::string question, std::string subject, std::string answer1, std::string answer2, std::string answer3, std::string correctAnswer) : question(question), subject(subject), answer1(answer1), answer2(answer2), answer3(answer3), correctAnswer(correctAnswer) {}

std::string Question::getQuestion() const {
    return question;
}

std::string Question::getSubject() const {
    return subject;
}

std::string Question::getAnswer1() const {
    return answer1;
}
std::string Question::getAnswer2() const {
    return answer2;
}
std::string Question::getAnswer3() const {
    return answer3;
}
std::string Question::getcorrectAnswer() const {
    return correctAnswer;
}

void Test_System::writeTestsToFile(const std::string& fileName) const {
    std::ofstream file(fileName, std::ios::binary | std::ios::app);
    if (file.is_open()) {
        int numQuestions = test_questions.size();
        file.write(reinterpret_cast<const char*>(&numQuestions), sizeof(numQuestions));

        for (const auto& question : test_questions) {
            int subjectSize = question.getSubject().size();
            file.write(reinterpret_cast<const char*>(&subjectSize), sizeof(subjectSize));
            file.write(question.getSubject().c_str(), subjectSize);

            int questionSize = question.getQuestion().size();
            file.write(reinterpret_cast<const char*>(&questionSize), sizeof(questionSize));
            file.write(question.getQuestion().c_str(), questionSize);

            int answer1size = question.getAnswer1().size();
            file.write(reinterpret_cast<const char*>(&answer1size), sizeof(answer1size));
            file.write(question.getAnswer1().c_str(), answer1size);

            int answer2size = question.getAnswer2().size();
            file.write(reinterpret_cast<const char*>(&answer2size), sizeof(answer2size));
            file.write(question.getAnswer2().c_str(), answer2size);

            int answer3size = question.getAnswer3().size();
            file.write(reinterpret_cast<const char*>(&answer3size), sizeof(answer3size));
            file.write(question.getAnswer3().c_str(), answer3size);

            int correctAnswerSize = question.getcorrectAnswer().size();
            file.write(reinterpret_cast<const char*>(&correctAnswerSize), sizeof(correctAnswerSize));
            file.write(question.getcorrectAnswer().c_str(), correctAnswerSize);
        }
        file.close();
    }
}



void Test_System::readTestsFromFile(const std::string& fileName) {
    std::ifstream file(fileName, std::ios::binary);
    if (file.is_open()) {
        int numQuestions;
        file.read(reinterpret_cast<char*>(&numQuestions), sizeof(numQuestions));

        for (int i = 0; i < numQuestions; ++i) {

            int subjectSize, questionSize, answer1size, answer2size, answer3size, correctAnswerSize;

            file.read(reinterpret_cast<char*>(&subjectSize), sizeof(subjectSize));
            std::string subject(subjectSize, '\0');
            file.read(&subject[0], subjectSize);

            file.read(reinterpret_cast<char*>(&questionSize), sizeof(questionSize));
            std::string question(questionSize, '\0');
            file.read(&question[0], questionSize);

            file.read(reinterpret_cast<char*>(&answer1size), sizeof(answer1size));
            std::string answer1(answer1size, '\0');
            file.read(&answer1[0], answer1size);

            file.read(reinterpret_cast<char*>(&answer2size), sizeof(answer2size));
            std::string answer2(answer2size, '\0');
            file.read(&answer2[0], answer2size);

            file.read(reinterpret_cast<char*>(&answer3size), sizeof(answer3size));
            std::string answer3(answer3size, '\0');
            file.read(&answer3[0], answer3size);

            file.read(reinterpret_cast<char*>(&correctAnswerSize), sizeof(correctAnswerSize));
            std::string correctAnswer(correctAnswerSize, '\0');
            file.read(&correctAnswer[0], correctAnswerSize);

            test_questions.push_back(Question(subject, question, answer1, answer2, answer3, correctAnswer));
        }
        file.close();
    }
}

void Test_System::addQuestion(std::string& subject, std::string& question, std::string& answer1, std::string& answer2, std::string& answer3, std::string& correctAnswer) {
    test_questions.push_back(Question(subject, question, answer1, answer2, answer3, correctAnswer));
}


void Test_System::printQuestions(const std::string& subject, int& currentQuestionIndex) const {

    while (currentQuestionIndex < test_questions.size()) {
        const auto& question = test_questions[currentQuestionIndex];
        if (question.getSubject() == subject) {
            std::cout << question.getQuestion() << std::endl;
            std::cout << "  " << "\nchoice A: " << question.getAnswer1() << "\nchoice B: " << question.getAnswer2() << "\nchoice C: " << question.getAnswer3() << std::endl;
            std::cout << "\n";
            currentQuestionIndex++;
            break;
        }
        currentQuestionIndex++;
    }
}

int Test_System::getCounterOfTest(std::string& subject) const {
    int count = 0;

    for (const auto& it : test_questions) {
        if (it.getSubject() == subject) {
            count++;
        }
    }

    return count;
}


