#include <gtest/gtest.h>
#include "core.h"

TEST(testCase, test0) {
	char* words[] = {
		"woo", "oom", "moon", "noox"
	};
	int len = 4;
	char head = 'k', tail = 0, ban = 0; 
	bool circ = true;
	int ret = 6; 
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = countChains(words, len, result);
	EXPECT_EQ(ans,ret);
}

TEST(testCase, test1) {
	char* words[] = {
		"algebra",
		"apple",
		"zoo",
		"elephant",
		"under",
		"fox",
		"dog",
		"moon",
		"leaf",
		"trick",
		"pseudopseudohypoparathyroidism"
	};
	int ret = 4, len = 11;
	char head = 0, tail = 0, ban = 0; 
	bool circ = false;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = getLongestWordChain(words, len, result, head, tail, ban, circ);
	EXPECT_EQ(ans,ret);
}

TEST(testCase, test2) {
	char* words[] = {
		"algebra",
		"apple",
		"zoo",
		"elephant",
		"under",
		"fox",
		"dog",
		"moon",
		"leaf",
		"trick",
		"pseudopseudohypoparathyroidism"
	};
	int ret = 2, len = 11;
	char head = 0, tail = 0, ban = 0; 
	bool circ = false;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = getLongestCharChain(words, len, result, head, tail, ban, circ);
	EXPECT_EQ(ans,ret);
}

TEST(testCase, test3) {
	char* words[] = {
		"algebra",
		"apple",
		"zoo",
		"elephant",
		"under",
		"fox",
		"dog",
		"moon",
		"leaf",
		"trick",
		"pseudopseudohypoparathyroidism"
	};
	int ret = 2, len = 11;
	char head = 'e', tail = 0, ban = 0; 
	bool circ = false;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = getLongestWordChain(words, len, result, head, tail, ban, circ);
	EXPECT_EQ(ans,ret);
}

TEST(testCase, test4) {
	char* words[] = {
		"algebra",
		"apple",
		"zoo",
		"elephant",
		"under",
		"fox",
		"dog",
		"moon",
		"leaf",
		"trick",
		"pseudopseudohypoparathyroidism"
	};
	int ret = 3, len = 11;
	char head = 0, tail = 't', ban = 0; 
	bool circ = false;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = getLongestWordChain(words, len, result, head, tail, ban, circ);
	EXPECT_EQ(ans,ret);
}

TEST(testCase, test5) {
	char* words[] = {
		"algebra",
		"apple",
		"zoo",
		"elephant",
		"under",
		"fox",
		"dog",
		"moon",
		"leaf",
		"trick",
		"pseudopseudohypoparathyroidism"
	};
	int ret = 2, len = 11;
	char head = 0, tail = 0, ban = 'a'; 
	bool circ = false;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = getLongestWordChain(words, len, result, head, tail, ban, circ);
	EXPECT_EQ(ans,ret);
}

TEST(testCase, test6) {
	char* words[] = {
		"element",
		"heaven",
		"table",
		"teach",
		"talk" 
	};
	int ret = 4, len = 5;
	char head = 0, tail = 0, ban = 0; 
	bool circ = true;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = getLongestWordChain(words, len, result, head, tail, ban, circ);
	EXPECT_EQ(ans,ret);
}

TEST(testCase, test7) {
	char* words[] = {
		"ab",
		"xyz",
		"ba"
	};
	int ret = 0, len = 3;
	char head = 0, tail = 0, ban = 0; 
	bool circ = false;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = countChains(words, len, result);
	EXPECT_EQ(ans,ret);
}

TEST(testCase, test8) {
	char* words[] = {
		"algebra",
		"apple",
		"zoo",
		"elephant",
		"under",
		"fox",
		"dog",
		"moon",
		"leaf",
		"trick",
		"pseudopseudohypoparathyroidism"
	};
	int ret = 2, len = 11;
	char head = 'l', tail = 0, ban = 0; 
	bool circ = false;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = getLongestWordChain(words, len, result, head, tail, ban, circ);
	EXPECT_EQ(ans,ret);
}

TEST(testCase, test9) {
	char* words[] = {
		"algebra",
		"apple",
		"zoo",
		"elephant",
		"under",
		"fox",
		"dog",
		"moon",
		"leaf",
		"trick",
		"kkd"
	};
	int ret = 6, len = 11;
	char head = 0, tail = 0, ban = 0; 
	bool circ = true;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = getLongestWordChain(words, len, result, head, tail, ban, circ);
	EXPECT_EQ(ans,ret);
}

TEST(testCase, test10) {
	char* words[] = {
		"algebra",
		"apple",
		"zoo",
		"elephant",
		"under",
		"fox",
		"dog",
		"moon",
		"leaf",
		"trick",
		"pseudopseudohypoparathyroidism" 
	};
	int ret = 4, len = 11;
	char head = 'a', tail = 0, ban = 0; 
	bool circ = false;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = getLongestCharChain(words, len, result, head, tail, ban, circ);
	EXPECT_EQ(ans,ret);
}

TEST(testCase, test11) {
	char* words[] = {
		"algebra",
		"apple",
		"zoo",
		"elephant",
		"under",
		"fox",
		"dog",
		"moon",
		"leaf",
		"trick",
		"kseudopseudohypoparathyroidisa" 
	};
	int ret = 5, len = 11;
	char head = 0, tail = 0, ban = 0; 
	bool circ = true;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = getLongestCharChain(words, len, result, head, tail, ban, circ);
	EXPECT_EQ(ans,ret);
}

TEST(testCase, test12) {
	char* words[] = {
		"algebra",
		"apple",
		"zoo",
		"elephant",
		"under",
		"fox",
		"dog",
		"moon",
		"leaf",
		"trick",
		"kseudopseudohypoparathyroidisa"
	};
	int ret = 5, len = 11;
	char head = 'k', tail = 0, ban = 0; 
	bool circ = true;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = getLongestCharChain(words, len, result, head, tail, ban, circ);
	EXPECT_EQ(ans,ret);
}

TEST(testCase, test13) {
	char* words[] = {
		"algebra",
		"apple",
		"zoo",
		"elephant",
		"under",
		"fox",
		"dog",
		"moon",
		"leaf",
		"trick",
		"kkd"
	};
	int ret = 6, len = 11;
	char head = 'a', tail = 0, ban = 0; 
	bool circ = true;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = getLongestWordChain(words, len, result, head, tail, ban, circ);
	EXPECT_EQ(ans,ret);
}






int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc,argv); 
	return RUN_ALL_TESTS(); 
}
