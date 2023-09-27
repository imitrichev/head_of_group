#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "gtest/gtest.h"

using namespace std;

// Структура для хранения информации о кандидате
struct Candidate {
    string name;
    int votes;

    Candidate(string n) {
        name = n;
        votes = 0;
    }
};

// Функция для проведения голосования
void conductElection(vector<Candidate>& candidates) {
    cout << "Голосование за выбор старосты!" << endl;

    // Вывод списка кандидатов
    cout << "Кандидаты:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << endl;
    }

    // Цикл голосования
    while (true) {
        cout << "Введите номер кандидата, за которого хотите проголосовать (0 - закончить голосование): ";
        int choice;
        cin >> choice;

        if (choice < 0 || choice > candidates.size()) {
            cout << "Недопустимый выбор!" << endl;
            continue;
        }
        else if (choice == 0) {
            break;
        }

        // Увеличение количества голосов кандидата
        candidates[choice - 1].votes++;
    }

    // Сортировка кандидатов по убыванию голосов
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });

    // Вывод результатов голосования
    cout << "Результаты голосования:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " голосов" << endl;
    }
}
//Тестирование конструктора Candidate:
TEST(CandidateTest, Constructor) {
    Candidate candidate("Иванов");
    EXPECT_EQ(candidate.name, "Иванов");
    EXPECT_EQ(candidate.votes, 0);
}
//Тестирование функции увеличения голосов:
TEST(CandidateTest, IncrementVotes) {
    Candidate candidate("Иванов");
    candidate.votes++;
    EXPECT_EQ(candidate.votes, 1);
    candidate.votes += 3;
    EXPECT_EQ(candidate.votes, 4);
}
//Тестирование функции проведения голосования с вводом:
TEST(ElectionTest, ConductElectionWithInput) {
    std::vector<Candidate> candidates;
    candidates.push_back(Candidate("Иванов"));
    candidates.push_back(Candidate("Петров"));

    std::stringstream input("1\n2\n0\n");
    std::streambuf* originalInput = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    std::stringstream output;
    std::streambuf* originalOutput = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    conductElection(candidates);

    std::string expectedOutput = 
        "Голосование за выбор старосты!\n"
        "Кандидаты:\n"
        "1. Иванов\n"
        "2. Петров\n"
        "Введите номер кандидата, за которого хотите проголосовать (0 - закончить голосование): "
        "Введите номер кандидата, за которого хотите проголосовать (0 - закончить голосование): "
        "Введите номер кандидата, за которого хотите проголосовать (0 - закончить голосование): "
        "Результаты голосования:\n"
        "1. Иванов: 1 голосов\n"
        "2. Петров: 1 голосов\n";

    EXPECT_EQ(output.str(), expectedOutput);

    std::cin.rdbuf(originalInput);
    std::cout.rdbuf(originalOutput);
}
//Тестирование функции проведения голосования без ввода (с использованием мокирования cin):
TEST(ElectionTest, ConductElectionWithoutInput) {
    std::vector<Candidate> candidates;
    candidates.push_back(Candidate("Иванов"));
    candidates.push_back(Candidate("Петров"));

    std::streambuf* originalInput = std::cin.rdbuf();
    std::istringstream input("1\n2\n0\n");
    std::cin.rdbuf(input.rdbuf());

    std::stringstream output;
    std::streambuf* originalOutput = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    conductElection(candidates);

    std::string expectedOutput = 
        "Голосование за выбор старосты!\n"
        "Кандидаты:\n"
        "1. Иванов\n"
        "2. Петров\n"
        "Введите номер кандидата, за которого хотите проголосовать (0 - закончить голосование): "
        "Введите номер кандидата, за которого хотите проголосовать (0 - закончить голосование): "
        "Введите номер кандидата, за которого хотите проголосовать (0 - закончить голосование): "
        "Результаты голосования:\n"
        "1. Иванов: 1 голосов\n"
        "2. Петров: 1 голосов\n";

    EXPECT_EQ(output.str(), expectedOutput);

    std::cin.rdbuf(originalInput);
    std::cout.rdbuf(originalOutput);
}
//Тестирование сценария без кандидатов:
TEST(ElectionTest, NoCandidates) {
    std::vector<Candidate> candidates;
    
    std::stringstream output;
    std::streambuf* originalOutput = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    conductElection(candidates);

    std::string expectedOutput = 
        "Голосование за выбор старосты!\n"
        "Кандидаты:\n"
        "Результаты голосования:\n";

    EXPECT_EQ(output.str(), expectedOutput);

    std::cout.rdbuf(originalOutput);
}

int main(&argc, **argv) {
    // Ввод количества кандидатов
    //int numCandidates;
    //cout << "Введите количество кандидатов: ";
    //cin >> numCandidates;

    // Ввод имён кандидатов
    //vector<Candidate> candidates;
    //for (int i = 0; i < numCandidates; i++) {
        //string name;
        //cout << "Введите фамилию и имя кандидата #" << i + 1 << ": ";
        //cin >> name;
        //candidates.push_back(Candidate(name));
    //}

    // Проведение голосования
    //conductElection(candidates);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
