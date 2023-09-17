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

void printCandidates(vector<Candidate>& candidates, ostream& sout) {
    for (int i = 0; i < candidates.size(); i++) {
        sout << i + 1 << ". " << candidates[i].name << endl;
    }
}

bool hasAlreadyVoted(vector<string>& surnames, string surname_to_check) {
    return find(surnames.begin(), surnames.end(), surname_to_check) != surnames.end();
}

void candidatesOrderByVotesDesc(vector<Candidate>& candidates) {
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });
}

void printVotingResults(vector<Candidate>& candidates, ostream& sout) {
    for (int i = 0; i < candidates.size(); i++) {
        sout << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " votes" << endl;
    }
}

bool performVote(string surname, int choice, vector<Candidate>& candidates, vector<string>& electors) {
    if (choice <= 0 || choice > candidates.size()) {
        return false;
    }

    // Увеличение количества голосов кандидата
    candidates[choice - 1].votes++;
    // Добавляем избирателя в список проголосовавших
    electors.push_back(surname);

    return true;
}

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
