#include <iostream>
#include "main.h"

using namespace std;

ofstream out("results.txt");
int main() {
    setlocale(LC_ALL, "");
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
    listCandidates(candidates, cout); 
    vote(candidates, cin, cout);
    sortCandidates(candidates);
    resultsVote(candidates, out, cout);

    return 0;
}