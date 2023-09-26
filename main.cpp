#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <main.h>

using namespace std;

int main() {
    //setlocale(LC_ALL, "Russian");
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
    inputcandidates(candidates, cout);
    circle(candidates, cout, cin);
    sortcandidates(candidates);
    outputcandidates(candidates, cout);
    system("pause");
    return 0;
}