#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <math.h>
#include <string>

class Pow : public Base
{
	public:
		double result;
		Base* arg1;
		Base* arg2;
		std::string str1;
		std::string str2;
		Pow(Base* n1, Base* n2) : Base()
		{
			this->arg1 = n1;
			this->arg2 = n2;
			this->str1 = arg1->stringify();
			this->str2 = arg2->stringify();
			this->result = pow(arg1->evaluate(),arg2->evaluate());
		}
		virtual double evaluate()
		{
			return this->result;
		}
		virtual std::string stringify()
		{
			return str1 + " ** " + str2;
		}
};

#endif //__POW_HPP__
