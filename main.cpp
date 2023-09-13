#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
    cout << "Voting for the choice of the headman!" << endl;

    // Вывод списка кандидатов
    cout << "Candidates:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << endl;
    }

    // Цикл голосования
    while (true) {
        cout << "Enter the number of the candidate you want to vote for (0 - finish voting): ";
        int choice;
        cin >> choice;

        if (choice < 0 || choice > candidates.size()) {
            cout << "Invalid choice!" << endl;
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
    cout << "Voting results:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " votes" << endl;
    }
}

int main() {
    // Ввод количества кандидатов
    int numCandidates;
    cout << "Enter the number of candidates: ";
    cin >> numCandidates;

    // Ввод имён кандидатов
    vector<Candidate> candidates;
    for (int i = 0; i < numCandidates; i++) {
        string name;
        cout << "Enter the candidate's name #" << i + 1 << ": ";
        cin >> name;
        candidates.push_back(Candidate(name));
    }

    // Проведение голосования
    conductElection(candidates);

    return 0;
}
