//#include "pch.h"
#include "gtest/gtest.h"
#include "../1LB_10VAR/main.h"
#include <sstream>

using namespace std;

TEST(ListCandidates, CanWriteListOfCandidates) {
	vector<Candidate> candidates = {
		Candidate("Pupa"),
		Candidate("Lupa")
	};
	stringstream sstream;

	listCandidates(candidates, sstream);

	string res = sstream.str();
	ASSERT_EQ(res, "Election of headman!\nCandidates:\n1. Pupa\n2. Lupa\n");
}

TEST(Vote, CanHandleInvalidChoices) {
	vector<Candidate> candidates = {
		Candidate("Pupa"),
		Candidate("Lupa")
	};
	istringstream in_stream("-1 5 0");
	ostringstream out_stream;

	vote(candidates, in_stream, out_stream);

	ASSERT_EQ(candidates[0].votes, 0);
	ASSERT_EQ(candidates[1].votes, 0);
}

TEST(Vote, CanHandleValidChoices) {
	vector<Candidate> candidates = {
		Candidate("Pupa"),
		Candidate("Lupa")
	};
	istringstream in_stream("1 2 1 0");
	ostringstream out_stream;

	vote(candidates, in_stream, out_stream);

	ASSERT_EQ(candidates[0].votes, 2);
	ASSERT_EQ(candidates[1].votes, 1);
}

TEST(Sort, CanSortListOfCandidates) {
	vector<Candidate> candidates = {
		Candidate("Pupa"),
		Candidate("Lupa")
	};
	candidates[0].votes = 1;
	candidates[1].votes = 5;

	sortCandidates(candidates);

	ASSERT_EQ(candidates[0].name, "Lupa");
}

TEST(ResultsVote, CanWriteResultsInFile) {
	vector<Candidate> candidates = {
		Candidate("Pupa"),
		Candidate("Lupa")
	};
	candidates[0].votes = 4;
	candidates[1].votes = 2;

	stringstream out;
	stringstream sstream;
	resultsVote(candidates, out, sstream);

	string res1 = out.str();
	string res2 = sstream.str();
	ASSERT_EQ(res1, "Results: \n1. Pupa: 4 votes\n2. Lupa: 2 votes\n");
	ASSERT_EQ(res2, "Results have been writen to results.txt\n");
}
int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}