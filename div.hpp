#ifndef __DIV_HPP__
#define __DVI_HPP__

#include "base.hpp"
#include <string>

using namespace std;

class Div : public Base {
    public:
        double product;
        Base* num1;
        Base* num;
        string str1;
        string str2;
	string out;
        Div(Base* op1, Base* op2) : Base() {
                this->num1 = op1;
                this->num = op2;
                this->str1 = num1->stringify();
                this->str2 = num->stringify();
		
		if(num->evaluate() == 0){
			this->product = -1;
			this->out = "Error";
		}
		else{
                	this->product = ((num1->evaluate()) / (num->evaluate()));
			this->out = this->str1 + " / " + this->str2;
		}
        }
        virtual double evaluate() { return this->product; }
        virtual string stringify() {
                return out;
        }
};

#endif //__DIV_HPP__

