#include "factory.hpp"
#include "factory.cpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ConcreteFactory fac1;
	string test;

	cout << "Input an expression: ";
	cin >> test;

	char* args[] = {
		(char*)&test.at(0),
		NULL
	};

	Base* tree = fac1.parse(args,test.length());
	cout << tree->stringify() << endl;
	cout << tree->evaluate() << endl;

}

