#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include <string>

using namespace std;

class Mult : public Base {
    public:
	double product;
	Base* num1;
	Base* num2;
	string str1;
        string str2;
        Mult(Base* op1, Base* op2) : Base() { 
		this->num1 = op1;
		this->num2 = op2;
		this->str1 = num1->stringify();
		this->str2 = num2->stringify();
		this->product = ((num1->evaluate()) * (num2->evaluate()));
	}
        virtual double evaluate() { return this->product; }
        virtual string stringify() {
		return this->str1 + " * " + this->str2;
	}
};

#endif //__MULT_HPP__
