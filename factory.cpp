#include "factory.hpp"
using namespace std;

class ConcreteFactory : Factory
{
public:
	virtual Base* parse(char** input, int length)
	{
            string temp;
            int numTemp;
            vector<Base*> ops;
            vector<int> positions;
            int j;
            int count = 0;
            Base* tempPosition = NULL;
            string test;
            test += input[0];

            for (int i = 0; i <= length - 1; i++)
            {
                if (isdigit(test[i]))
                {
                    j = i;
                    while (isdigit(test[j]))
                    {
                        temp += test[j];
                        if (j <= length - 1)
                        {
                            j++;
                        }


                    }
                    numTemp = stoi(temp);
                    Base* op1 = new Op(numTemp);
                    ops.push_back(op1);
                    i = j - 1;
                }
                else if (test[i] == '+')
                {
                    positions.push_back(i);
                }
                else if (test[i] == '-')
                {
                    positions.push_back(i);
                }
                else if (test[i] == '/')
                {
                    positions.push_back(i);
                }
                else if (test[i] == '*')
                {
                    positions.push_back(i);
                }
                temp = "";
            }
            j = 0;
            for (int i = 0; i <= positions.size() - 1; i++)
            {
                if (count == 1)
                {
                    if (test[positions.at(i)] == '+')
                    {
                        Base* Add2 = new Add(tempPosition, ops.at(j + 1));
                        tempPosition = Add2;
                    }
                    if (test[positions.at(i)] == '-')
                    {
                        Base* Sub2 = new Sub(tempPosition, ops.at(j + 1));
                        tempPosition = Sub2;
                    }
                    if (test[positions.at(i)] == '/')
                    {
                        Base* Div2 = new Div(tempPosition, ops.at(j + 1));
                        tempPosition = Div2;
                    }
                    if (test[positions.at(i)] == '*')
                    {
                        if (test[positions.at(i) + 1] == '*')
                        {
                            Base* Pow2 = new Pow(tempPosition, ops.at(j + 1));
                            tempPosition = Pow2;
                            i++;
                        }
                        else
                        {
                            Base* Mult2 = new Mult(tempPosition, ops.at(j + 1));
                            tempPosition = Mult2;
                        }
                    }
                }
                else
                {
                    count++;
                    if (test[positions.at(i)] == '+')
                    {
                        Base* Add1 = new Add(ops.at(j), ops.at(j + 1));
                        tempPosition = Add1;
                    }
                    if (test[positions.at(i)] == '-')
                    {
                        Base* Sub1 = new Sub(ops.at(j), ops.at(j + 1));
                        tempPosition = Sub1;
                    }
                    if (test[positions.at(i)] == '/')
                    {
                        Base* Div1 = new Div(ops.at(j), ops.at(j + 1));
                        tempPosition = Div1;
                    }
                    if (test[positions.at(i)] == '*')
                    {
                        if (test[positions.at(i) + 1] == '*')
                        {
                            Base* Pow1 = new Pow(ops.at(j), ops.at(j + 1));
                            tempPosition = Pow1;
                            i++;
                        }
                        else
                        {
                            Base* Mult1 = new Mult(ops.at(j), ops.at(j + 1));
                            tempPosition = Mult1;
                        }


                    }
                }
                j++;
            }

            return tempPosition;
        
	}
};

