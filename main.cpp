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

// Функция вывода списка кандидатов
void showCandidatesDesk(vector<Candidate>& candidates) {
    cout << "Кандидаты:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << endl;
    }
}

// Функция для добавления кандидата по инициативе голосующего
void addCandidate(vector<Candidate>& candidates) {
    cout << "Введите имя кандидата, которого вы хотите добавить: ";
    string candidate_name;
    cin >> candidate_name;
    cout << endl;

    // Проверка на дублирование кандидата
    for (int i = 0; i < candidates.size(); i++) {
        if (candidate_name == candidates[i].name) {
            cout << "Кандидат с таким именем уже существует!" << endl;
            break;
        }
    }

    // Добавление кандидата
    candidates.push_back(Candidate(candidate_name));
    cout << "Кандидат успешно добавлен!" << endl;
}

// Функция для проведения голосования
void conductElection(vector<Candidate>& candidates) {
    cout << "Голосование за выбор старосты!" << endl;

    // Вывод списка кандидатов
    showCandidatesDesk(candidates);

    // Цикл голосования
    while (true) {
        cout << "Введите номер кандидата, за которого хотите проголосовать (0 - закончить голосование) (-1 - предложить своего кандидата): ";
        int choice;
        cin >> choice;

        if (choice < -1 || choice > int(candidates.size())) {
            cout << "Недопустимый выбор!" << endl;
            continue;
        }
        else if (choice == -1) {
            addCandidate(candidates);
            showCandidatesDesk(candidates);
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

int main() {
    // Ввод количества кандидатов
    int numCandidates;
    cout << "Введите количество кандидатов: ";
    cin >> numCandidates;

    // Ввод имён кандидатов
    vector<Candidate> candidates;
    for (int i = 0; i < numCandidates; i++) {
        string name;
        cout << "Введите имя кандидата #" << i + 1 << ": ";
        cin >> name;
        candidates.push_back(Candidate(name));
    }

    // Проведение голосования
    conductElection(candidates);

    return 0;
}