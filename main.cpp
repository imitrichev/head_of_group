#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ofstream out("results.txt");
// ��������� ��� �������� ���������� � ���������
struct Candidate {
    string name;
    int votes;

    Candidate(string n) {
        name = n;
        votes = 0;
    }
};

// ������� ��� ���������� �����������
void conductElection(vector<Candidate>& candidates, ofstream& out) {
    cout << "����������� �� ����� ��������!" << endl;

    // ����� ������ ����������
    cout << "���������:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << endl;
    }

    // ���� �����������
    while (true) {
        cout << "������� ����� ���������, �� �������� ������ ������������� (0 - ��������� �����������): ";
        int choice;
        cin >> choice;

        if (choice < 0 || choice > candidates.size()) {
            cout << "������������ �����!" << endl;
            continue;
        }
        else if (choice == 0) {
            break;
        }

        // ���������� ���������� ������� ���������
        candidates[choice - 1].votes++;
    }

    // ���������� ���������� �� �������� �������
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
        });

    // ����� ����������� �����������
    out << "���������� �����������: " << endl;
    for (int i = 0; i < candidates.size(); i++) {
        out << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " �������" << endl;
    }
}

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
    conductElection(candidates, out);   

    return 0;
}