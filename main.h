#include <iostream>
#include <string>
#include <vector>

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