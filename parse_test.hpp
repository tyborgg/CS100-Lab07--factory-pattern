#ifndef __PARSE_TEST_HPP__
#define __PARSE_TEST_HPP__

#include "factory.hpp"
#include "factory.cpp"
#include "gtest/gtest.h"
#include <string>
#include "base.hpp"
//test comment
using namespace std;

TEST(ParseTest, NormalConditions)
{
	ConcreteFactory fac1;
	string test = "3-7*5";
	char* args[] = {
	(char*)&test.at(0),
	NULL
	};

	Base* tree = fac1.parse(args,test.length());
	EXPECT_EQ("3.000000 - 7.000000 * 5.000000",tree->stringify());
	EXPECT_EQ(-20,tree->evaluate());
}

TEST(ParseTest, EveryOperatorType)
{
        ConcreteFactory fac1;
        string test = "1+1-1*2/2**5";
        char* args[] = {
        (char*)&test.at(0),
        NULL
        };

        Base* tree = fac1.parse(args,test.length());
        EXPECT_EQ("1.000000 + 1.000000 - 1.000000 * 2.000000 / 2.000000 ** 5.000000",tree->stringify());
        EXPECT_EQ(1,tree->evaluate());
}

TEST(ParseTest, ReallyLongInput)
{
        ConcreteFactory fac1;
        string test = "1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1";
        char* args[] = {
        (char*)&test.at(0),
        NULL
        };

        Base* tree = fac1.parse(args,test.length());
        EXPECT_EQ("1.000000 - 1.000000 + 1.000000 - 1.000000 + 1.000000 - 1.000000 + 1.000000 - 1.000000 + 1.000000 - 1.000000 + 1.000000 - 1.000000 + 1.000000 - 1.000000 + 1.000000 - 1.000000 + 1.000000 - 1.000000 + 1.000000 - 1.000000 + 1.000000 - 1.000000 + 1.000000 - 1.000000 + 1.000000 - 1.000000 + 1.000000 - 1.000000 + 1.000000",tree->stringify());
        EXPECT_EQ(1,tree->evaluate());
}

TEST(ParseTest, InvalidInput)
{
        ConcreteFactory fac1;
        string test = "r-7*5";
        char* args[] = {
        (char*)&test.at(0),
        NULL
        };

        Base* tree = fac1.parse(args,test.length());
        EXPECT_EQ(NULL,tree);
}

#endif


