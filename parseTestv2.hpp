#ifndef PARSETESTV2_HPP
#define PARSETESTV2_HPP

#include "factory.hpp"
#include "factory.cpp"
#include "gtest/gtest.h"
#include <string>
#include "base.hpp"

using namespace std;

TEST(ParseTestV2, NormalConditions){
	ConcreteFactory fac1;
	string test = "5*5*5";
	char* args[] = {
	(char*)&test.at(0),
	NULL
	};

	Base* tree = fac1.parse(args, test.length());
	EXPECT_EQ("5.000000 * 5.000000 * 5.000000", tree->stringify());
	EXPECT_EQ(125, tree->evaluate());
}

TEST(ParseTestV2, ManyTypes){
        ConcreteFactory fac1;
        string test = "5*4-3+3/4";
        char* args[] = {
        (char*)&test.at(0),
        NULL
        };

        Base* tree = fac1.parse(args, test.length());
        EXPECT_EQ("5.000000 * 4.000000 - 3.000000 + 3.000000 / 4.000000", tree->stringify());
        EXPECT_EQ(5, tree->evaluate());
}

TEST(ParseTestV2, LongInput){
        ConcreteFactory fac1;
        string test = "9*9/9*9/9*9/9*9/9+1+1-1+1-1+1+1+2";
        char* args[] = {
        (char*)&test.at(0),
        NULL
        };

        Base* tree = fac1.parse(args, test.length());
        EXPECT_EQ("9.000000 * 9.000000 / 9.000000 * 9.000000 / 9.000000 * 9.000000 / 9.000000 * 9.000000 / 9.000000 + 1.000000 + 1.000000 - 1.000000 + 1.000000 - 1.000000 + 1.000000 + 1.000000 + 2.000000", tree->stringify());
        EXPECT_EQ(14, tree->evaluate());
}

TEST(ParseTestV2, RandomInput){
        ConcreteFactory fac1;
        string test = "3 * 0 + 2 ** 2";
        char* args[] = {
        (char*)&test.at(0),
        NULL
        };

        Base* tree = fac1.parse(args, test.length());
        EXPECT_EQ("3.000000 * 0.000000 + 2.000000 ** 2.000000", tree->stringify());
        EXPECT_EQ(4, tree->evaluate());
}


#endif
