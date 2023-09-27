#include <gtest/gtest.h>
#include "functions.h"
#include <iostream>

using namespace std;

std::istringstream autoUserInput(const std::string& input){
    return std::istringstream(input);
}

TEST(CandidateTest, Creation){
    Candidate candidate("Kevin Costner");
    EXPECT_EQ(candidate.name, "Kevin Costner");
    EXPECT_EQ(candidate.votes, 0);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}