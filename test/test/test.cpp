//#include "pch.h"
#include "../laba1/main.h" 
#include <sstream>
#include "gtest/gtest.h"

TEST(inputcandidates, FullListOfCandidates) { //�������� ������ ���� �������
	vector<Candidate> candidates = {
		Candidate("Elya"),
		Candidate("Mora"),
		Candidate("Mura")
	};

	stringstream sstream;
	inputcandidates(candidates, sstream);

	string result = sstream.str();
	ASSERT_EQ(result, "Voting for the choice of the headman!\nCandidates:\n1. Elya\n2. Mora\n3. Mura\n");

}

TEST(circle, HaveInvalidChoices) { //�������� ������ ������� �� �������
	vector<Candidate> candidates = {
		Candidate("Elya"),
		Candidate("Mora"),
		Candidate("Mura")
	};

	istringstream in_stream("-1 6 5 0");
	ostringstream out_stream;

	circle(candidates, out_stream, in_stream);


	ASSERT_EQ(candidates[0].votes, 0);
	ASSERT_EQ(candidates[1].votes, 0);
	ASSERT_EQ(candidates[2].votes, 0);
}

TEST(outputcandidates, HaveCorrectChoices) { //�������� ������ �����������
	vector<Candidate> candidates = {
		Candidate("Elya"),
		Candidate("Mora")
	};

	
    candidates[0].votes = 1;
	candidates[1].votes = 3;
	
	stringstream sstream;
	outputcandidates(candidates, sstream);
	string result = sstream.str();
	
	ASSERT_EQ(result, "Voting results:\n1. Elya: 1 voices\n2. Mora: 3 voices\n");
}

TEST(circle, Have1InvalidChoices) { //�������� �������, ��� ����� ������� �������� ��������
	vector<Candidate> candidates = {
		Candidate("Elya"),
		Candidate("Mora")
	};

	istringstream in_stream("-1 1 Y 0");
	ostringstream out_stream;

	circle(candidates, out_stream, in_stream);


	ASSERT_EQ(candidates[0].votes, 1);
	ASSERT_EQ(candidates[1].votes, 0);
}

TEST(circle, HaveInvalidSures) { //�������� ������� ��� ����� ������������ ����� ��� ������� (������� �� ��?)
	vector<Candidate> candidates = {
		Candidate("Elya"),
		Candidate("Mora")
	};

	istringstream in_stream("-1 1 R 0");
	ostringstream out_stream;

	circle(candidates, out_stream, in_stream);


	ASSERT_EQ(candidates[0].votes, 0);
	ASSERT_EQ(candidates[1].votes, 0);
}



int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}