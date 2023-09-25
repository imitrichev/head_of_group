#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "main.h"

using namespace std;

// Функция для проведения голосования
void conductElection(vector<Candidate>& candidates) {
    cout << "Voting for the choice of the headman!" << endl;

    // Вывод списка кандидатов
    cout << "Candidates:" << endl;
    printCandidates(candidates, cout);

    vector<string> electors_surnames;

    // Цикл голосования
    while (true) {
        string surname;
        cout << "Introduce yourself (or enter 0 to finish voting): ";
        cin >> surname;
        if (surname == "0") break;
        // если введенной фамилии нет в массиве, то разрешаем голосование
        if (!hasAlreadyVoted(electors_surnames, surname)) {
            cout << "Enter the number of the candidate you want to vote for: ";
            int choice;
            cin >> choice;

            if (!performVote(surname, choice, candidates, electors_surnames)) {
                cout << "Invalid choice!" << endl;
                continue;
            }

            cout << "Your vote confirmed. Next!" << endl;
        }
        else {
            cout << "Stop right there you criminal scum! You have already voted!" << endl;
        }
    }

    // Сортировка кандидатов по убыванию голосов
    candidatesOrderByVotesDesc(candidates);

    // Вывод результатов голосования
    cout << "Voting results:" << endl;
    printVotingResults(candidates, cout);
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
