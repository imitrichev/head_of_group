#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

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

void sortCandidates(vector<Candidate>& candidates){
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });
}

void conductElection(vector<Candidate>& candidates, vector<int>& votes){
    for (int i = 0; i < votes.size(); ++i) {
        candidates[votes[i] - 1].votes++;
    }

    sortCandidates(candidates);
}

void conductVotingRound(vector<Candidate>& candidates){
    // Вывод списка кандидатов
    cout << "Кандидаты:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << endl;
    }

    // Первый тур голосования

    vector<int> votes;
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
        votes.push_back(choice);
    }


    conductElection(candidates, votes);

    // Вывод результатов голосования
    cout << "Результаты голосования:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " голосов" << endl;
    }
}

// Функция для проведения голосования
void conductElection(vector<Candidate>& candidates, bool isSecondRound = false) {
    cout << "Голосование за выбор старосты!" << endl;


    // Первый тур голосования
    conductVotingRound(candidates);

    if (!isSecondRound || candidates.size() < 2){
        cout << "Победитель " << candidates[0].name << endl;
        return;
    }

    candidates.erase(candidates.begin() + 2, candidates.end());

    // Второй тур голосования
    cout << "Второй тур!" << endl;
    conductVotingRound(candidates);

    cout << "Победитель " << candidates[0].name << endl;
}

TEST(ElectionTests, TestCandidateCtor){
    // Arrange
    string name = "Ivan Sergeev";

    // Act
    Candidate candidate(name);

    // Assert
    EXPECT_EQ(candidate.name, name);
}

TEST(ElectionTests, TestConductElection){
    // Arrange
    Candidate candidate1("Ivan Sergeev");
    Candidate candidate2("Petr Sergeev");
    Candidate candidate3("Egor Sergeev");
    Candidate candidate4("Sergey Sergeev");

    vector<Candidate> candidates;
    candidates.push_back(candidate1);
    candidates.push_back(candidate2);
    candidates.push_back(candidate3);
    candidates.push_back(candidate4);

    vector<int> votes;
    votes.push_back(1);
    votes.push_back(1);
    votes.push_back(1);
    votes.push_back(2);
    votes.push_back(2);
    votes.push_back(3);
    votes.push_back(4);

    // Act
    conductElection(candidates, votes);

    // Assert
    EXPECT_EQ(candidates[0].name, candidate1.name);
}

TEST(ElectionTests, TestSingleRoundElection){
    // Arrange
    Candidate candidate1("Ivan Sergeev");
    Candidate candidate2("Petr Sergeev");
    Candidate candidate3("Egor Sergeev");
    Candidate candidate4("Sergey Sergeev");

    vector<Candidate> candidates;
    candidates.push_back(candidate1);
    candidates.push_back(candidate2);
    candidates.push_back(candidate3);
    candidates.push_back(candidate4);

    // Act
    std::istringstream input_stream("1\n1\n1\n1\n2\n2\n3\n4\n0\n");
    std::cin.rdbuf(input_stream.rdbuf());

    conductElection(candidates);

    // Assert
    EXPECT_EQ(candidates[0].name, "Ivan Sergeev");
}

TEST(ElectionTests, TestDoubleRoundElection){
    // Arrange
    Candidate candidate1("Ivan Sergeev");
    Candidate candidate2("Petr Sergeev");
    Candidate candidate3("Egor Sergeev");
    Candidate candidate4("Sergey Sergeev");

    vector<Candidate> candidates;
    candidates.push_back(candidate1);
    candidates.push_back(candidate2);
    candidates.push_back(candidate3);
    candidates.push_back(candidate4);

    // Act
    std::istringstream input_stream("1\n1\n1\n1\n2\n2\n3\n4\n0\n");
    std::cin.rdbuf(input_stream.rdbuf());

    conductElection(candidates, true);

    // Assert
    ASSERT_TRUE(candidates[0].name == candidate1.name && candidates.size() == 2);
}

TEST(ElectionTests, TestCandidateSorting){
    // Arrange
    Candidate candidate1("Ivan Sergeev");
    Candidate candidate2("Petr Sergeev");
    Candidate candidate3("Egor Sergeev");
    Candidate candidate4("Sergey Sergeev");

    vector<Candidate> candidates;

    candidate1.votes = 3;
    candidate2.votes = 2;
    candidate3.votes = 1;
    candidate4.votes = 0;

    candidates.push_back(candidate1);
    candidates.push_back(candidate2);
    candidates.push_back(candidate3);
    candidates.push_back(candidate4);

    vector<Candidate> candidates2(candidates);

    // Act
    sortCandidates(candidates);
    sort(candidates2.begin(), candidates2.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });


    // Assert
    for (int i = 0; i < candidates.size(); ++i) {
        if (candidates[i].name != candidates2[i].name){
            FAIL();
        }
    }

    SUCCEED();
}

int main(int argc, char **argv) {
//    // Ввод количества кандидатов
//    int numCandidates;
//    cout << "Введите количество кандидатов: ";
//    cin >> numCandidates;
//
//    // Ввод имён кандидатов
//    vector<Candidate> candidates;
//    for (int i = 0; i < numCandidates; i++) {
//        string name;
//        cout << "Введите имя кандидата #" << i + 1 << ": ";
//        cin >> name;
//        candidates.push_back(Candidate(name));
//    }
//
//    // Проведение голосования
//    conductElection(candidates);

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
