#include <gtest/gtest.h>
#include "core.h"
#include "utils.h"

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
	string str = "there is a circle in the chain without -r";
	char** result = (char**)malloc(sizeof(char*) * 100);
	try {
		int ans = countChains(words, len, result);
	} catch(exception& e) {
		EXPECT_EQ(e.what(),str);
	}
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

TEST(testCase, test14) {
	char* words[] = {
		"algebra",
		"apple",
		"exe",
		"elephant"
	};
	int ret = 8, len = 4;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = countChains(words, len, result);
	EXPECT_EQ(ans,ret);
}

TEST(testCase, test15) {
	char* words[] = {
		"aba",
		"abba",
		"abb",
		"bccc"
	};
	int ret = 0, len = 4;
	char head = 'a', tail = 0, ban = 0; 
	bool circ = false;
	char** result = (char**)malloc(sizeof(char*) * 100);
	string str = "there is a circle in the chain without -r";
	try {
		int ans = getLongestWordChain(words, len, result, head, tail, ban, circ);
	} catch(exception& e) {
		string err = e.what();
		EXPECT_EQ(err, str);	
	}
}

TEST(testCase, test16) {
	char* words[] = {
		"aba",
		"css",
		"abb",
		"bccc"
	};
	int ret = 0, len = 4;
	char head = 'a', tail = 0, ban = 'a'; 
	bool circ = false;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = getLongestWordChain(words, len, result, head, tail, ban, circ);
	EXPECT_EQ(ans,ret);
}

TEST(testCase, test17) {
	char* words[] = {
		"algebra",
		"apple",
		"exe",
		"elephant"
	};
	int ret = 4, len = 4;
	char head = 0, tail = 0, ban = 0; 
	bool circ = false;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = getLongestWordChain(words, len, result, head, tail, ban, circ);
	EXPECT_EQ(ans,ret);
}

TEST(testCase, test18) {
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
	int ret = 5, len = 11;
	char head = 0, tail = 'd', ban = 'l'; 
	bool circ = true;
	char** result = (char**)malloc(sizeof(char*) * 100);
	int ans = getLongestCharChain(words, len, result, head, tail, ban, circ);
	EXPECT_EQ(ans,ret);
}

//异常处理
TEST(testCase, test19) {
	int argc = 4; 
	char* argv[] = {
		" ",
		"-n",
		"-n",
		"input.txt"
	};
	string str = "duplicate option: -n";
	try {
		WordList(argc, argv);
	} catch(exception& e) {
		string err = e.what(); 
		EXPECT_EQ(err, str);
	}
}

TEST(testCase, test20) {
	int argc = 4;
	char* argv[] = {
		" ",
		"-n",
		"input.txt",
		"-h"
	};
	string str = "option that should have argument does not have argument: -h";
	try {
		WordList(argc, argv);
	} catch(exception& e) {
		string err = e.what(); 
		EXPECT_EQ(err, str);
	}
}

TEST(testCase, test21) {
	int argc = 5;
	char* argv[] = {
		" ",
		"-h",
		"an",
		"-n",
		"input.txt"
	};
	string str = "option has illegal argument: -h has an";
	try {
		WordList(argc, argv);
	} catch(exception& e) {
		string err = e.what(); 
		EXPECT_EQ(err, str);
	}
}

TEST(testCase, test22) {
	int argc = 5;
	char* argv[] = {
		" ",
		"-b",
		"a",
		"-n",
		"input.txt"
	};
	string str = "illegal option: -b";
	try {
		WordList(argc, argv);
	} catch(exception& e) {
		string err = e.what(); 
		EXPECT_EQ(err, str);
	}
}

TEST(testCase, test23) {
	int argc = 4;
	char* argv[] = {
		" ",
		"-n",
		"input.txt",
		"input2.txt"
	};
	string str = "duplicate fileName: input2.txt";
	try {
		WordList(argc, argv);
	} catch(exception& e) {
		string err = e.what(); 
		EXPECT_EQ(err, str);
	}
}

TEST(testCase, test24) {
	int argc = 3;
	char* argv[] = {
		" ",
		"-r",
		"input.txt",
	};
	string str = "missing functional parameters (-n -w -c)";
	try {
		WordList(argc, argv);
	} catch(exception& e) {
		string err = e.what(); 
		EXPECT_EQ(err, str);
	}
}

TEST(testCase, test25) {
	int argc = 4;
	char* argv[] = {
		" ",
		"-n",
		"-w",
		"input.txt",
	};
	string str = "functional parameters are not compatible";
	try {
		WordList(argc, argv);
	} catch(exception& e) {
		string err = e.what(); 
		EXPECT_EQ(err, str);
	}
}

TEST(testCase, test26) {
	int argc = 3;
	char* argv[] = {
		" ",
		"-n",
		"input2.txt",
	};
	string str = "file does not exist";
	try {
		WordList(argc, argv);
	} catch(exception& e) {
		string err = e.what(); 
		EXPECT_EQ(err, str);
	}
}

TEST(testCase, test27) {
	char* words[] = {

	};
	int len = 0;
	char** result = (char**)malloc(sizeof(char*) * 100);
	string str = "the file content is empty";
	try {
		int ans = countChains(words, len, result);
	} catch(exception& e) {
		string err = e.what(); 
		EXPECT_EQ(err, str);
	} 
}

TEST(testCase, test28) {
	int argc = 4;
	char* argv[] = {
		" ",
		"-n",
		"-r",
		"input.txt",
	};
	string str = "-n can only be used alone";
	try {
		WordList(argc, argv);
	} catch(exception& e) {
		string err = e.what(); 
		EXPECT_EQ(err, str);
	}
}

TEST(testCase, test29) {
	char* words[] = {
		"word",
		"draw"	
	};
	int len = 2;
	char** result = (char**)malloc(sizeof(char*) * 100);
	string str = "there is a circle in the chain without -r"; 
	try {
		int ans = countChains(words, len, result);
	} catch(exception& e) {
		string err = e.what(); 
		EXPECT_EQ(err, str);
	} 
}

TEST(testCase, test30) {
	char* words[] = {
		"ab",
		"ss"	
	};
	int len = 2;
	char** result = (char**)malloc(sizeof(char*) * 100);
	string str = "there is no matching result"; 
	try {
		int ans = countChains(words, len, result);
	} catch(exception& e) {
		string err = e.what(); 
		EXPECT_EQ(err, str);
	} 
}

TEST(testCase, test31) {
	int argc = 8;
	char* argv[] = {
		" ",
		"-w",
		"-h",
		"a",
		"-j",
		"a",
		"-r",
		"input.txt"
	};
	string str = "-h and -j cannot have the same value";
	try {
		WordList(argc, argv);
	} catch(exception& e) {
		string err = e.what(); 
		EXPECT_EQ(err, str);
	}
}


int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc,argv); 
	return RUN_ALL_TESTS(); 
}