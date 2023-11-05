#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

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

// Проверка на корректность создания кандидата
int test0() {

    Candidate candidate("Fedor");

    if (candidate.name == "Fedor" && candidate.votes == 0) {
        return 0;
    }

    return -1;

}

// Проверка на корректность создания множества кандидатов
int test1() {

    int numCandidates = 5;
    vector<string> names = { "Oleg", "Shrek", "Semen", "Ostolpho", "Igor" };
    vector<Candidate> candidates;

    for (int i = 0; i < numCandidates; i++) {
        candidates.push_back(names[i]);
    }

    bool name_flag = false;
    for (int i = 0; i < numCandidates; i++) {

        name_flag = false;

        for (int j = 0; j < candidates.size(); j++) {
            if (names[i] == candidates[j].name) {
                name_flag = true;
                break;
            }
        }

        if (!name_flag) {
            return -1;
        }

    }

    return 0;
}

// Проверка функции добавление кандидата
int test2() {

    vector<Candidate> candidates;
    candidates.push_back(Candidate("Candidate1"));
    candidates.push_back(Candidate("Candidate2"));

    istringstream input_stream("Candidate3\n");
    cin.rdbuf(input_stream.rdbuf());

    addCandidate(candidates);

    if (candidates.size() == 3) {
        return 0;
    }

    return -1;
}

// Проверка на корректность присуждения голосов
int test3() {

    vector<Candidate> candidates;
    candidates.push_back(Candidate("Candidate1"));
    candidates.push_back(Candidate("Candidate2"));

    istringstream input_stream("1\n1\n2\n1\n0\n");
    cin.rdbuf(input_stream.rdbuf());

    conductElection(candidates);

    if (candidates[0].votes == 3 && candidates[1].votes == 1) {
        return 0;
    }

    return -1;
}

// Проверка на недопустимых значениях 
int test4() {

    vector<Candidate> candidates;
    candidates.push_back(Candidate("Candidate1"));
    candidates.push_back(Candidate("Candidate2"));

    istringstream input_stream("4\n6\n4\n78\n0\n");
    cin.rdbuf(input_stream.rdbuf());

    conductElection(candidates);

    if (candidates[0].votes == 0 && candidates[1].votes == 0) {
        return 0;
    }

    return -1;
}

int main() {

    setlocale(LC_ALL, "Russian");
    

    if (test0() == 0) {
        cout << "Тест0 успешно завершен, ошибок не обнаружено!" << endl;
    }
    else {
        cout << "Тест0 выявил ошибку!" << endl;
    }

    if (test1() == 0) {
        cout << "Тест1 успешно завершен, ошибок не обнаружено!" << endl;
    }
    else {
        cout << "Тест1 выявил ошибку!" << endl;
    }

    if (test2() == 0) {
        cout << "Тест2 успешно завершен, ошибок не обнаружено!" << endl;
    }
    else {
        cout << "Тест2 выявил ошибку!" << endl;
    }

    if (test3() == 0) {
        cout << "Тест3 успешно завершен, ошибок не обнаружено!" << endl;
    }
    else {
        cout << "Тест3 выявил ошибку!" << endl;
    }

    if (test4() == 0) {
        cout << "Тест4 успешно завершен, ошибок не обнаружено!" << endl;
    }
    else {
        cout << "Тест4 выявил ошибку!" << endl;
    }

    /* ======== main part ========
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
    */

    return 0;
}