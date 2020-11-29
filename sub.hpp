#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base
{
	public:
		double result;
		Base* arg1;
		Base* arg2;
		std::string str1;
		std::string str2;
		Sub(Base* n1, Base* n2) : Base()
		{
			this->arg1 = n1;
			this->arg2 = n2;
			this->str1 = arg1->stringify();
			this->str2 = arg2->stringify();
			this->result = (arg1->evaluate() - arg2->evaluate());
		}
		virtual double evaluate()
		{
			return this->result;
		}
		virtual std::string stringify()
		{
			return str1 + " - " + str2;
		}
};

#endif //__SUB_HPP__
