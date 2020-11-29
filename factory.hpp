#ifndef FACTORY_HPP
#define FACTORY_HPP
#include "base.hpp"

class Factory{
public:
	virtual Base* parse(char** input, int length) = 0;
};
#endif
