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
bool conductElection(vector<Candidate>& candidates) {
    cout << "voting for the election of the headman!" << endl;

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

int main() {
    // setlocale(LC_CTYPE, "Russian");
    // Ввод количества кандидатов
    int numCandidates;
    cout << "Enter candidates count: ";
    cin >> numCandidates;

    // Ввод имён кандидатов
    vector<Candidate> candidates;
    inputCandidateNames(candidates, numCandidates);

    // Проведение голосования
    while (true)
    {
        bool val = conductElection(candidates);
        if (!val)
        {
            candidates.clear();
            candidates.shrink_to_fit();
            cout << "Enter candidates count: ";
            cin >> numCandidates;
            inputCandidateNames(candidates, numCandidates);
        }
        else
        {
            break;
        }
    }

    return 0;
}
