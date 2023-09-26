#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>

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

void inputcandidates(vector<Candidate>& candidates) {
    cout << "Voting for the choice of the headman!" << endl;

    // Вывод списка кандидатов
    cout << "Candidates:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << endl;
    }
}

void circle(vector<Candidate>& candidates) {
    // Цикл голосования
    while (true) {
        cout << "Enter the number of the candidate you want to vote for (0 - finish voting): ";
        int choice;
        cin >> choice;

        if (choice < 0 || choice > candidates.size()) {
            cout << "Unacceptable choice!" << endl;
            continue;
        }
        else if (choice == 0) {
            break;
        }

        char sure;
        cout << "Are you sure Y/N?: ";
        cin >> sure;

        if (sure != 'Y' && sure != 'N') {
            cout << "Unacceptable choice!" << endl;
        }
        else if (sure == 'N') {
            continue;
        }

        else if (sure == 'Y') {
            // Увеличение количества голосов кандидата
            candidates[choice - 1].votes++;
        }



    }
}

void sortcandidates(vector<Candidate>& candidates) {
    // Сортировка кандидатов по убыванию голосов
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
        });
}

void outputcandidates(vector<Candidate>& candidates) {
    // Вывод результатов голосования
    cout << "Voting results:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " voices" << endl;
    }
}
