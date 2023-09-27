#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


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
void listCandidates(vector<Candidate>& candidates, ostream& stream) {
    stream << "Election of headman!" << endl;

    // ����� ������ ����������
    stream << "Candidates:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        stream << i + 1 << ". " << candidates[i].name << endl;
    }
}

void vote(vector<Candidate>& candidates, istream& in_stream, ostream& out_stream)
{
    // ���� �����������
    while (true) {
        out_stream << "Enter number of candidate you want to vote for (0 - end voting): ";
        int choice;
        in_stream >> choice;

        if (choice < 0 || choice > candidates.size()) {
            out_stream << "Invalid choice!" << endl;
            continue;
        }
        else if (choice == 0) {
            break;
        }

        // ���������� ���������� ������� ���������
        candidates[choice - 1].votes++;
    }
}
void sortCandidates(vector<Candidate>& candidates)
{
    // ���������� ���������� �� �������� �������
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
        });

}

void resultsVote(vector<Candidate>& candidates, ostream& out, ostream& stream)
{
    // ����� ����������� �����������
    out << "Results: " << endl;
    for (int i = 0; i < candidates.size(); i++) {
        out << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " votes" << endl;
    }
    stream << "Results have been writen to results.txt" << endl;
}