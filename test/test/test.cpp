//#include "pch.h"
#include "main.h" 
#include <sstream>
#include "gtest/gtest.h"

TEST(inputcandidates, FullListOfCandidates) {
	vector<Candidate> candidates = {
		Candidate("Elya"),
		Candidate("Mora")
	};

	stringstream sstream;
	inputcandidates(candidates, sstream);

	string result = sstream.str();
	ASSERT_EQ(result, "Voting for the choice of the headman!\nCandidates:\n1. Elya\n2. Mora\n");
	
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}