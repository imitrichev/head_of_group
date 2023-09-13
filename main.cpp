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

    vector<string> electors_surnames;

    // Цикл голосования
    while (true) {
        string surname;
        cout << "Introduce yourself (or enter 0 to finish voting): ";
        cin >> surname;
        if (surname == "0") break;
        // если введенной фамилии нет в массиве, то разрешаем голосование
        if (find(electors_surnames.begin(), electors_surnames.end(), surname) == electors_surnames.end()) {
            cout << "Enter the number of the candidate you want to vote for: ";
            int choice;
            cin >> choice;

            if (choice < 0 || choice > candidates.size()) {
                cout << "Invalid choice!" << endl;
                continue;
            }

            // Увеличение количества голосов кандидата
            candidates[choice - 1].votes++;
            // Добавляем избирателя в список проголосовавших
            electors_surnames.push_back(surname);
            cout << "Your vote confirmed. Call the next elector" << endl;
        }
        else {
            cout << "Stop right there you criminal scum! You have already voted!" << endl;
        }
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
