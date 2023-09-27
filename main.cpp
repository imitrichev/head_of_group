#include <iostream>
#include <string>
#include <vector>
#include "gtest/gtest.h"
#include <math.h>
using namespace std;


// СТРУКТУРА ДЛЯ ХРАНЕНИЯ КАНДИДАТА
struct Candidate {
    string name;
    int votes;

    Candidate(string n) {
        name = n;
        votes = 0;
    }
};


// ФУНКЦИЯ ДЛЯ ПРОВЕДЕНИЯ ГОЛОСОВАНИЯ
bool conductElection(vector<Candidate>& candidates) 
{
    cout << "voting for the election of the headman!" << endl;
    if (candidates.size() == 0) 
    {
      cout << "NO CANDIDATES" << endl;
      return true;
    }
    if (candidates.size() == 1) 
    {
      cout << "NO ELECTIONS" << endl;
      return true;
    }

    // Вывод списка кандидатов
    cout << "Candidates:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << endl;
    }

    // Цикл голосования
    while (true) {
        cout << "Enter the number of the candidate, you want to vote for (0 - finish voting, -1 - change the candidates): ";
        int choice;
        cin >> choice;
        if (choice > (int)candidates.size()) {
            cout << "Invalid choice!" << endl;
            continue;
        }
        else if (choice == 0) {
            break;
        }
        else if (choice == -1) {
            cout << "candidates changing..." << endl;
            return false;
        }
        // Увеличение количества голосов кандидата
        candidates[choice - 1].votes++;
    }

    // Сортировка кандидатов по убыванию голосов
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });

    // Вывод результатов голосования
    cout << "voting result:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " votes" << endl;
    }

    return true;
}


// ФУНКЦИЯ ДЛЯ ПРОВЕДЕНИЯ ГОЛОСОВАНИЯ (ТЕСТЫ)
string conductElectionForTests(vector<Candidate>& candidates, vector<int>& votes) 
{
  if (candidates.size() == 0) 
  {
    return "NO CANDIDATES";
  }
  if (candidates.size() == 1) 
  {
    return "NO ELECTIONS";
  }
  if (votes.size() == 0) 
  {
    return "NOBODY VOTED";
  }
  if (count(votes.begin(), votes.end(), -1))
  {
    return "CHANGE CANDIDATES";
  }

  // Цикл голосования
    for (int i = 0; i < votes.size(); i++) 
    {
      int choice = votes[i];
      if (choice > candidates.size()) {
          return "OUT OF BOUNDS";
      }
      // Увеличение количества голосов кандидата
      candidates[choice - 1].votes++;
    }

  // Сортировка кандидатов по убыванию голосов
  sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
      return a.votes > b.votes;
  });

  return candidates[0].name;
}


// ТЕСТЫ
TEST(FunctionTesting, winner_test) {
    // тест 1
    std::vector<Candidate> candidates = {Candidate("Leo"), Candidate("Aboba"), Candidate("Griga")};
    std::vector<int> votes = {1, 1, 1, 1, 3, 3, 1, 2, 3, 1, 2, 2};
    EXPECT_EQ("Leo", conductElectionForTests(candidates, votes));
    candidates.clear();
    votes.clear();
}

TEST(FunctionTesting, no_elections_test) {
    // тест 2
    std::vector<Candidate> candidates = {Candidate("Leo")};
    std::vector<int> votes = {1, 1, 1, 1, 3, 3, 1, 2, 3, 1, 2, 2};
    EXPECT_EQ("NO ELECTIONS", conductElectionForTests(candidates, votes));
    candidates.clear();
    votes.clear();
}

TEST(FunctionTesting, no_candidates_test) {
    // тест 3
    std::vector<Candidate> candidates;
    std::vector<int> votes = {1, 1, 1, 1, 3, 3, 1, 2, 3, 1, 2, 2};
    EXPECT_EQ("NO CANDIDATES", conductElectionForTests(candidates, votes));
    candidates.clear();
    votes.clear();
}

TEST(FunctionTesting, no_votes_test) {
    // тест 4
    std::vector<Candidate> candidates = {Candidate("Leo"), Candidate("Aboba"), Candidate("Griga") };
    std::vector<int> votes;
    EXPECT_EQ("NOBODY VOTED", conductElectionForTests(candidates, votes));
    candidates.clear();
    votes.clear();
}

TEST(FunctionTesting, out_of_bounds_test) {
    // тест 5
    std::vector<Candidate> candidates = {Candidate("Leo"), Candidate("Aboba"), Candidate("Griga") };
    std::vector<int> votes  = {1, 1, 1, 2, 2, 3, 1, 2, 3, 1, 1, 1, 666, 34, 999};
    EXPECT_EQ("OUT OF BOUNDS", conductElectionForTests(candidates, votes));
    candidates.clear();
    votes.clear();
}

TEST(FunctionTesting, change_candidates_test) {
    // тест 6
    std::vector<Candidate> candidates = {Candidate("Leo"), Candidate("Aboba"), Candidate("Griga") };
    std::vector<int> votes  = {1, 1, 1, -1, 3, 3, 1, 2, 3, -1, 2, 2};
    EXPECT_EQ("CHANGE CANDIDATES", conductElectionForTests(candidates, votes));
    candidates.clear();
    votes.clear();
}

void inputCandidateNames(vector<Candidate>& candidates, int numCandidates) 
{
    for (int i = 0; i < numCandidates; i++) 
    {
        string name;
        cout << "Enter the candidate name #" << i + 1 << ": ";
        cin >> name;
        candidates.push_back(Candidate(name));
    }
}

int main(int argc, char **argv) 
{
  // setlocale(LC_CTYPE, "Russian");

  // ОСНОВНАЯ ЛОГИКА
  // Ввод количества кандидатов
  // int numCandidates;
  // cout << "Enter candidates count: ";
  // cin >> numCandidates;

  // // Ввод имён кандидатов
  // vector<Candidate> candidates;
  // inputCandidateNames(candidates, numCandidates);

  // // Проведение голосования
  // while (true)
  // {
  //     bool val = conductElection(candidates);
  //     if (!val)
  //     {
  //         candidates.clear();
  //         candidates.shrink_to_fit();
  //         cout << "Enter candidates count: ";
  //         cin >> numCandidates;
  //         inputCandidateNames(candidates, numCandidates);
  //     }
  //     else
  //     {
  //         break;
  //     }
  // }

  // return 0;

  // ТЕСТЫ
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


