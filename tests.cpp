#include <gtest/gtest.h>
#include "functions.h"
#include <iostream>

using namespace std;

std::istringstream autoUserInput(const std::string& input){
    return std::istringstream(input);
}
// Проверка оздания кандидата в старосты
TEST(CandidateTest, Creation){
    Candidate candidate("Kevin Costner");

    // Проверка данных кандидата
    EXPECT_EQ(candidate.name, "Kevin Costner");
    EXPECT_EQ(candidate.votes, 0);
}
// Проверка правильности проведения выборов
TEST(ElectionTest, ConductElection){
    vector<Candidate> candidates;
    candidates.push_back(Candidate("Candidate1"));
    candidates.push_back(Candidate("Candidate2"));

    // Имитация ввода пользователя и отправка в буфер
    std::istringstream input_stream("1\n2\n0\n");
    std::cin.rdbuf(input_stream.rdbuf());

    conductElection(candidates);

    // Проверка правильности подсчёта голосов
    EXPECT_EQ(candidates[0].votes + candidates[1].votes, 2);
}
// Проверка правильности подсчёта голосов, противодействие фальсификациям
TEST(ElectionTest, VoteForCandidate){
    vector<Candidate> candidates;
    candidates.push_back(Candidate("Candidate1"));
    candidates.push_back(Candidate("Candidate2"));

    std::istringstream input_stream("1\n1\n1\n0\n");

    conductElection(candidates);

    EXPECT_EQ(candidates[0].votes, 3);
}
// Выборы без кандидатов - деньги на ветер
TEST(ElectionTest, ZeroCandidates){
    vector<Candidate> candidates;

    std::istringstream input_stream("0\n");
    std::cin.rdbuf(input_stream.rdbuf());

    conductElection(candidates);

    // Пустой ли список кандидатов 
    EXPECT_TRUE(candidates.empty());
}
TEST(ElectionTest, ZeroVotes){
    vector<Candidate> candidates;
    candidates.push_back(Candidate("Candidate1"));
    candidates.push_back(Candidate("Candidate2"));

    std::istringstream input_stream("0\n");
    std::cin.rdbuf(input_stream.rdbuf());

    conductElection(candidates);

    // Кандидаты есть
    EXPECT_FALSE(candidates.empty());
    // Голосов у кандидатов нет
    EXPECT_EQ(candidates[0].votes + candidates[1].votes, 0);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}