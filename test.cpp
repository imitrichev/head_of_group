#include "pch.h"
#include "main.h"
#include <vector>
#include <iostream>
#include <sstream>

TEST(PrintCandidates, IsFormatCorrect) {
	// prepare
	std::vector<Candidate> candidates = {
		Candidate("Aaa"),
		Candidate("Bbb"),
		Candidate("Ccc")
	};
	std::stringstream test_s;
	// perform
	printCandidates(candidates, test_s);
	std::string str1, str2, str3;
	std::getline(test_s, str1);
	std::getline(test_s, str2);
	std::getline(test_s, str3);
	// assert
	ASSERT_EQ(str1, "1. Aaa");
	ASSERT_EQ(str2, "2. Bbb");
	ASSERT_EQ(str3, "3. Ccc");
}

TEST(HasAlreadyVoted, IsResultCorrect) {
	// prepare
	std::vector<std::string> surnames = { "aaa", "bbb", "ccc" };
	// perform
	bool result1 = hasAlreadyVoted(surnames, "bbb");
	bool result2 = hasAlreadyVoted(surnames, "eee");
	// assert
	ASSERT_TRUE(result1);
	ASSERT_FALSE(result2);
}

TEST(CandidatesOrderByVotesDesc, IsSortingCorrect) {
	// prepare
	std::vector<Candidate> candidates = {
		Candidate("aaa"), Candidate("bbb"), Candidate("ccc")
	};
	candidates[0].votes = 5;
	candidates[1].votes = 10;
	candidates[2].votes = 3;
	// perform
	candidatesOrderByVotesDesc(candidates);
	// assert
	ASSERT_EQ(candidates[0].name, "bbb");
	ASSERT_EQ(candidates[1].name, "aaa");
	ASSERT_EQ(candidates[2].name, "ccc");
}

TEST(PrintVotingResults, IsFormatCorrect) {
	// prepare
	std::vector<Candidate> candidates = {
		Candidate("Aaa"),
		Candidate("Bbb"),
		Candidate("Ccc")
	};
	candidates[0].votes = 10;
	candidates[1].votes = 5;
	candidates[2].votes = 3;
	std::stringstream test_s;
	// perform
	printVotingResults(candidates, test_s);
	std::string str1, str2, str3;
	std::getline(test_s, str1);
	std::getline(test_s, str2);
	std::getline(test_s, str3);
	// assert
	ASSERT_EQ(str1, "1. Aaa: 10 votes");
	ASSERT_EQ(str2, "2. Bbb: 5 votes");
	ASSERT_EQ(str3, "3. Ccc: 3 votes");
}

TEST(PerformVote, CanHandleInvalidChoice) {
	// prepare
	std::vector<Candidate> candidates = {
		Candidate("Aaa"),
		Candidate("Bbb"),
		Candidate("Ccc")
	};
	std::vector<std::string> electors = { "el_1", "el_2", "el_3" };
	std::string elector = "el_4";
	// perform
	bool res1 = performVote(elector, 0, candidates, electors);
	bool res2 = performVote(elector, -5, candidates, electors);
	bool res3 = performVote(elector, 4, candidates, electors);
	bool res4 = performVote(elector, 3, candidates, electors);
	// assert
	ASSERT_FALSE(res1);
	ASSERT_FALSE(res2);
	ASSERT_FALSE(res3);
	ASSERT_TRUE(res4);
}

TEST(PerformVote, IncreaseVotesForCandidate) {
	// prepare
	std::vector<Candidate> candidates = {
		Candidate("aaa"), Candidate("bbb")
	};
	std::vector<std::string> electors = { "el_1", "el_2", "el_3" };
	std::string elector = "el_4";
	// perform
	performVote(elector, 2, candidates, electors);
	// assert
	ASSERT_EQ(candidates[1].votes, 1);
}

TEST(PerformVote, AddElectorToList) {
	// prepare
	std::vector<Candidate> candidates = {
		Candidate("aaa"), Candidate("bbb")
	};
	std::vector<std::string> electors = { "el_1", "el_2", "el_3" };
	std::string elector = "el_4";
	// perform
	performVote(elector, 2, candidates, electors);
	// assert
	ASSERT_EQ(electors.size(), 4);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}