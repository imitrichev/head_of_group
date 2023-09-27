#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"

using namespace std;
// Структура для хранения информации о кандидате
struct Candidate {
    std::string name;
    std::string surname;
    int votes;

    Candidate(std::string n, std::string s) {
        name = n;
        surname = s;
        votes = 0;
    }
};

// Функция для проведения голосования
std::string conductElection(std::vector<Candidate>& candidates, std::vector<int>& votes) {
    std::cout << "Elections of captain!" << std::endl;

    // Вывод списка кандидатов
    std::cout << "Candidates:" << std::endl;
    for (int i = 0; i < candidates.size(); i++) {
        std::cout << i + 1 << ". " << candidates[i].surname << " "<< candidates[i].name << std::endl;
    }

    if (candidates.size() == 0) {
        return "NO CANDIDATES";
    }
    if (candidates.size() == 1) {
        return "NO ELECTIONS";
    }
    if (votes.size() == 0) {
        return "NO VOTES";
    }

    

    // Цикл голосования
    for (int i = 0; i < votes.size(); i++) {
        int choice = votes[i];
        if (choice > candidates.size()) {
            return "ILLEGAL VOTE";
        }

        // Увеличение количества голосов кандидата
        candidates[choice - 1].votes++;
    }

    // Сортировка кандидатов по убыванию голосов
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });

    // Вывод результатов голосования
    std::cout << "Election results:" << std::endl;
    for (int i = 0; i < candidates.size(); i++) {
        std::cout << i + 1 << ". " << candidates[i].surname << " "<< candidates[i].name << ": " << candidates[i].votes << " votes" << std::endl;
    }

    // Возвращаем фамилию и имя кандидата победителя
    return candidates[0].surname + " " + candidates[0].name;
}

//Тестирование конструктора Candidate:
TEST(CandidateTest, Constructor) {
    Candidate candidate("Иванов");
    EXPECT_EQ(candidate.name, "Иванов");
    EXPECT_EQ(candidate.votes, 0);
}
TEST(FunctionTesting, test_elections) {
    // тест 1
    std::vector<Candidate> candidates = {Candidate("Nikita", "Sidorenko"), Candidate("Ryan", "Gosling"), Candidate("Mikhail", "Sidorenko") };
    std::vector<int> votes = {1, 1, 1, 2, 2, 3, 1, 2, 3, 1, 1, 1};
    EXPECT_EQ("Sidorenko Nikita", conductElection(candidates, votes));
    candidates.clear();
    votes.clear();
}

TEST(FunctionTesting, test_elections_single_candidate) {
    // тест 2
    std::vector<Candidate> candidates = {Candidate("Nikita", "Sidorenko") };
    std::vector<int> votes = {1, 1, 1, 2, 2, 3, 1, 2, 3, 1, 1, 1};
    EXPECT_EQ("NO ELECTIONS", conductElection(candidates, votes));
    candidates.clear();
    votes.clear();
}

TEST(FunctionTesting, test_elections_no_candidates) {
    // тест 3
    std::vector<Candidate> candidates;
    std::vector<int> votes = {1, 1, 1, 2, 2, 3, 1, 2, 3, 1, 1, 1};
    EXPECT_EQ("NO CANDIDATES", conductElection(candidates, votes));
    candidates.clear();
    votes.clear();
}

TEST(FunctionTesting, test_elections_no_votes) {
    // тест 4
    std::vector<Candidate> candidates = {Candidate("Nikita", "Sidorenko"), Candidate("Ryan", "Gosling"), Candidate("Mikhail", "Sidorenko") };
    std::vector<int> votes;
    EXPECT_EQ("NO VOTES", conductElection(candidates, votes));
    candidates.clear();
    votes.clear();
}

TEST(FunctionTesting, test_elections_illegal_votes) {
    // тест 5
    std::vector<Candidate> candidates = {Candidate("Nikita", "Sidorenko"), Candidate("Ryan", "Gosling"), Candidate("Mikhail", "Sidorenko") };
    std::vector<int> votes  = {1, 1, 1, 2, 2, 3, 1, 2, 3, 1, 1, 1, 50, 46, 78};
    EXPECT_EQ("ILLEGAL VOTE", conductElection(candidates, votes));
    candidates.clear();
    votes.clear();
}


int main(int argc, char **argv) {
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
