#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


// Структура для хранения информации о кандидате
struct Candidate {
    std::string name;
    std::string surname;
    int votes;

    Candidate(std::string n, std::string s) {
        name = n;
        surname = s;
        votes = 0;
    }
};

// Функция для проведения голосования
void conductElection(std::vector<Candidate>& candidates) {
    std::cout << "Elections of captain!" << std::endl;

    // Вывод списка кандидатов
    std::cout << "Candidates:" << std::endl;
    for (int i = 0; i < candidates.size(); i++) {
        std::cout << i + 1 << ". " << candidates[i].surname << " "<< candidates[i].name << std::endl;
    }

    // Цикл голосования
    while (true) {
        std::cout << "Enter number of candidate, you want to vote for (0 - end elections): ";
        int choice;
        std::cin >> choice;

        if (choice < 0 || choice > candidates.size()) {
            std::cout << "Unavailable choice!" << std::endl;
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
    std::cout << "Election results:" << std::endl;
    for (int i = 0; i < candidates.size(); i++) {
        std::cout << i + 1 << ". " << candidates[i].surname << " "<< candidates[i].name << ": " << candidates[i].votes << " votes" << std::endl;
    }
}

int main() {
    // Ввод количества кандидатов
    int numCandidates;
    std::cout << "Enter candidates amount: ";
    std::cin >> numCandidates;

    // Ввод имён и фамилий кандидатов
    std::vector<Candidate> candidates;
    for (int i = 0; i < numCandidates; i++) {
        std::string name, surname;
        std::cout << "Enter candidate #" << i + 1 << " name: ";
        std::cin >> name;
        std::cout << "Enter candidate #" << i + 1 << " surname: ";
        std::cin >> surname;
        candidates.push_back(Candidate(name, surname));
    }

    // Проведение голосования
    conductElection(candidates);

    return 0;
}
