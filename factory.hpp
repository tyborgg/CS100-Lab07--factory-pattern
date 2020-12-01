#ifndef FACTORY_HPP
#define FACTORY_HPP
#include "base.hpp"
#include <string>
#include <vector>
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
class Factory{
public:
	virtual Base* parse(char** input, int length) = 0;
};
#endif
