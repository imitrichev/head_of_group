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

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}