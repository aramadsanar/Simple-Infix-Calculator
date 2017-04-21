#ifndef POSTFIXGENERATOR_H
#define POSTFIXGENERATOR_H

#include <iostream>
#include <string>

#include "Stack.h"
#include "StackInt.h"
#include "StackFloat.h"

#define nullptr 0
using namespace std;

class PostfixGenerator
{
private:
    Stack stackOperator;
    StackInt stackOperand;
    StackFloat floatStackOperand;

    int priority(char simbol);
    bool ValidateInput(string inputString);
    void truncateFrontString(string &stringInput);

    int calculate(char oper, int operator1, int operator2);
    float floatCalculate(char oper, float operand1, float operand2);
public:
    PostfixGenerator();

    string getResult(string stringInfix);

    int obsoleteEvalPostfix(string stringPostfix);
    int evalPostfix(string stringPostfix);
    float floatEvalPostfix(string stringPostfix);

    int evalInfix(string stringInfix);
    float floatEvalInfix(string stringInfix);

    int showMenu();
};
#endif // POSTFIXGENERATOR_H
