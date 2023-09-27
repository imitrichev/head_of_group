#include <iostream>
#include "main.h"

using namespace std;

ofstream out("results.txt");
int main() {
    setlocale(LC_ALL, "");
    // ���� ���������� ����������
    int numCandidates;
    cout << "������� ���������� ����������: ";
    cin >> numCandidates;

    // ���� ��� ����������
    vector<Candidate> candidates;
    for (int i = 0; i < numCandidates; i++) {
        string name;
        cout << "������� ��� ��������� #" << i + 1 << ": ";
        cin >> name;
        candidates.push_back(Candidate(name));
    }

    // ���������� �����������
    listCandidates(candidates, cout); 
    vote(candidates, cin, cout);
    sortCandidates(candidates);
    resultsVote(candidates, out, cout);

    return 0;
}