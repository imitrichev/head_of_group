#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"

using namespace std;
// Структура для хранения информации о кандидате
struct Candidate {
     string name;
     string surname;
    int votes;

    Candidate( string n,  string s) {
        name = n;
        surname = s;
        votes = 0;
    }
};

// Функция для проведения голосования
 string conductElection( vector<Candidate>& candidates,  vector<int>& votes) {
     cout << "Elections of captain!" <<  endl;

    // Вывод списка кандидатов
     cout << "Candidates:" <<  endl;
    for (int i = 0; i < candidates.size(); i++) {
         cout << i + 1 << ". " << candidates[i].surname << " "<< candidates[i].name <<  endl;
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
     cout << "Election results:" <<  endl;
    for (int i = 0; i < candidates.size(); i++) {
         cout << i + 1 << ". " << candidates[i].surname << " "<< candidates[i].name << ": " << candidates[i].votes << " votes" <<  endl;
    }

    // Возвращаем фамилию и имя кандидата победителя
    return candidates[0].surname + " " + candidates[0].name;
}
// Тест проверяет правильность работы функции проведения выборов в обычных условиях с несколькими кандидатами и голосами.
TEST(FunctionTesting, test_elections) {
     vector<Candidate> candidates = {Candidate("Nikita", "Sidorenko"), Candidate("Ryan", "Gosling"), Candidate("Mikhail", "Sidorenko") };
     vector<int> votes = {1, 1, 1, 2, 2, 3, 1, 2, 3, 1, 1, 1};
    EXPECT_EQ("Sidorenko Nikita", conductElection(candidates, votes));
    candidates.clear();
    votes.clear();
}
// Тест проверяет, что функция правильно обрабатывает случай, когда всего один кандидат
TEST(FunctionTesting, test_elections_single_candidate) {
         vector<Candidate> candidates = {Candidate("Nikita", "Sidorenko") };
     vector<int> votes = {1, 1, 1, 2, 2, 3, 1, 2, 3, 1, 1, 1};
    EXPECT_EQ("NO ELECTIONS", conductElection(candidates, votes));
    candidates.clear();
    votes.clear();
}

// Тест проверяет, что функция правильно обрабатывает случай, когда нет кандидатов.
TEST(FunctionTesting, test_elections_no_candidates) {
       vector<Candidate> candidates;
     vector<int> votes = {1, 1, 1, 2, 2, 3, 1, 2, 3, 1, 1, 1};
    EXPECT_EQ("NO CANDIDATES", conductElection(candidates, votes));
    candidates.clear();
    votes.clear();
}
// Тест проверяет, что функция правильно обрабатывает случай, когда нет голосов.
TEST(FunctionTesting, test_elections_no_votes) {
    vector<Candidate> candidates = {Candidate("Nikita", "Sidorenko"), Candidate("Ryan", "Gosling"), Candidate("Mikhail", "Sidorenko") };
    vector<int> votes;
    EXPECT_EQ("NO VOTES", conductElection(candidates, votes));
    candidates.clear();
    votes.clear();
}
// Тест проверяет, что функция правильно обрабатывает случай, когда имеются незаконные голоса (голоса за несуществующих кандидатов).
TEST(FunctionTesting, test_elections_illegal_votes) {
    vector<Candidate> candidates = {Candidate("Nikita", "Sidorenko"), Candidate("Ryan", "Gosling"), Candidate("Mikhail", "Sidorenko") };
    vector<int> votes  = {1, 1, 1, 2, 2, 3, 1, 2, 3, 1, 1, 1, 50, 46, 78};
    EXPECT_EQ("ILLEGAL VOTE", conductElection(candidates, votes));
    candidates.clear();
    votes.clear();
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
