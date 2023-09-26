#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ofstream out("results.txt");
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
void listCandidates(vector<Candidate>& candidates) {
    cout << "Голосование за выбор старосты!" << endl;

    // Вывод списка кандидатов
    cout << "Кандидаты:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << endl;
    }
}

void vote(vector<Candidate>& candidates)
{
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
}
void sortCandidates(vector<Candidate>& candidates)
{
    // Сортировка кандидатов по убыванию голосов
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
        });

}

void resultsVote(vector<Candidate>& candidates, ofstream& out)
{
    // Вывод результатов голосования
    out << "Результаты голосования: " << endl;
    for (int i = 0; i < candidates.size(); i++) {
        out << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " голосов" << endl;
    }
    cout << "Результаты голосования отправлены на файл results.txt" << endl;
}