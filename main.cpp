#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


// Структура для хранения информации о кандидате
struct Candidate {
    std::string name;
    int votes;

    Candidate(std::string n) {
        name = n;
        votes = 0;
    }
};

// Функция для проведения голосования
void conductElection(std::vector<Candidate>& candidates) {
    std::cout << "Голосование за выбор старосты!" << std::endl;

    // Вывод списка кандидатов
    std::cout << "Кандидаты:" << std::endl;
    for (int i = 0; i < candidates.size(); i++) {
        std::cout << i + 1 << ". " << candidates[i].name << std::endl;
    }

    // Цикл голосования
    while (true) {
        std::cout << "Введите номер кандидата, за которого хотите проголосовать (0 - закончить голосование): ";
        int choice;
        std::cin >> choice;

        if (choice < 0 || choice > candidates.size()) {
            std::cout << "Недопустимый выбор!" << std::endl;
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
    std::cout << "Результаты голосования:" << std::endl;
    for (int i = 0; i < candidates.size(); i++) {
        std::cout << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " голосов" << std::endl;
    }
}

int main() {
    // Ввод количества кандидатов
    int numCandidates;
    std::cout << "Введите количество кандидатов: ";
    std::cin >> numCandidates;

    // Ввод имён кандидатов
    std::vector<Candidate> candidates;
    for (int i = 0; i < numCandidates; i++) {
        std::string name;
        std::cout << "Введите имя кандидата #" << i + 1 << ": ";
        std::cin >> name;
        candidates.push_back(Candidate(name));
    }

    // Проведение голосования
    conductElection(candidates);

    return 0;
}
