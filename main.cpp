#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>


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
std::string conductElection(std::vector<Candidate>& candidates, std::vector<int>& votes) {
    std::cout << "Elections of captain!" << std::endl;

    // Вывод списка кандидатов
    std::cout << "Candidates:" << std::endl;
    for (int i = 0; i < candidates.size(); i++) {
        std::cout << i + 1 << ". " << candidates[i].surname << " "<< candidates[i].name << std::endl;
    }

    // Цикл голосования
    for (int i = 0; i < votes.size(); i++) {
        int choice = votes[i];

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

    // Возвращаем фамилию и имя кандидата победителя
    return candidates[0].surname + " " + candidates[0].name;
}

int main() {
    srand(time(0));

    // Ввод количества кандидатов
    int numCandidates;
    std::vector<std::string> names = {"Nikita", "Mikhail", "Alexei", "Ivan", "Mars", "Ryan"};
    std::vector<std::string> surnames = {"Sidorenko", "Babkin", "Lobanov", "Sergayev", "Gaifullin", "Gosling"};
    std::cout << "Enter candidates amount: ";
    std::cin >> numCandidates;

    // Случайная генерация имён и фамилий кандидатов
    std::vector<Candidate> candidates;
    for (int i = 0; i < numCandidates; i++) {
        std::string name = names[rand() % names.size()];
        std::string surname = surnames[rand() % names.size()];
        candidates.push_back(Candidate(name, surname));
    }

    // Случайная генерация голосов
    int votes_amount = rand() % 100 + 1;
    std::vector<int> votes;
    for (int i = 0; i < votes_amount; i++) {
        votes.push_back(rand() % numCandidates + 1);
    }

    // Проведение голосования
    std::string winner = conductElection(candidates, votes);
    std::cout << "And the winner is.....\n" << winner << std::endl;
    return 0;
}
