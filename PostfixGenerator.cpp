#include "PostfixGenerator.h"
#include "Stack.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

PostfixGenerator::PostfixGenerator()
{

}

/**String Builders Component*/
bool PostfixGenerator::ValidateInput(string validator)
{
    Stack inputValidationStack;
    inputValidationStack.emptyStack();

    for (unsigned int i = 0; i < validator.length(); i++)
    {
        if (validator[i] == '(')
                inputValidationStack.push(validator[i]);
        else if (validator[i] == ')')
        {
            char buffer = inputValidationStack.pop();
            if ((buffer == 0) || (buffer != '('))
                return false;
        }
    }

    return inputValidationStack.empty() ? true:false;
}

int PostfixGenerator::priority(char simbol)
{
    int nilai = 0;

    switch(simbol)
    {
        case '(': nilai=1; break;
        case ')': nilai= 2; break;
        case '+': case '-': nilai= 3; break;
        case '*': case '/': case '%': nilai=4; break;
        case '^': nilai=5; break;
        case ' ': nilai = 6; break;
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': nilai = 0; break;
        case '.': return 0;
        default: nilai=7; break;
    }
    return nilai;
}

string PostfixGenerator::getResult(string stringInfix)
{
    bool isInputValid = ValidateInput(stringInfix);

    if (!isInputValid)
    {
        cout << "Input invalid." << endl;
        return "";
    }

    while (!stackOperator.empty())
        stackOperator.pop();
    string stringPostfix = "";
    stringInfix = stringInfix + ")";

    stackOperator.push('(');

    char karakter, simbol;
    char numBuffer;
    unsigned int i = 0;
    for (i = 0; i < stringInfix.length(); i++)
    {
        simbol = stringInfix[i];
        int prioritas = priority(simbol);

        switch(prioritas)
        {
        case 1:
            stackOperator.push('(');
            break;
        case 2:
            karakter = stackOperator.pop();
            while (karakter != '(')
            {
                stringPostfix = stringPostfix + karakter;
                karakter = stackOperator.pop();
            };
            break;
        case 3:
        case 4:
        case 5:
            karakter = stackOperator.pop();
            while (priority(karakter) >= prioritas)
            {
                stringPostfix = stringPostfix + karakter + " ";
                karakter = stackOperator.pop();
            };
            stackOperator.push(karakter);
            stackOperator.push(simbol);
            break;
        case 0:
            if (priority(stringPostfix[stringPostfix.length() -1]) >=1 && priority(stringPostfix[stringPostfix.length() -1]) <=5)
                stringPostfix = stringPostfix + " ";
            numBuffer = stringInfix[i];
            while(priority(numBuffer) == 0)
            {
                stringPostfix = stringPostfix + numBuffer;
                i += 1;
                numBuffer = stringInfix[i];
            };
            stringPostfix = stringPostfix + " ";
            i -= 1;
            //stringPostfix = stringPostfix + simbol;
            break;
        default:
            stringPostfix = stringPostfix + simbol;
        }
    }

    return stringPostfix;
}

/**Calculation Engine*/
int PostfixGenerator::calculate(char oper, int operand1, int operand2)
{
    int hasil = 0;

    switch(oper)
    {
    case '^':
        hasil = 1;
        for (int i = 1; i <= operand2; i++)
            hasil *= operand1;
        break;
    case '+':
        hasil = operand1 + operand2; break;
    case '*':
        hasil = operand1 * operand2; break;
    case '/':
        hasil = operand1 / operand2; break;
    case '-':
        hasil = operand1 - operand2; break;
    case '%':
        hasil = operand1 % operand2; break;
    }

    return hasil;
}

float PostfixGenerator::floatCalculate(char oper, float operand1, float operand2)
{
    float hasil = 0;

    switch(oper)
    {
    case '^':
        hasil = 1;
        for (int i = 1; i <= operand2; i++)
            hasil *= operand1;
        break;
    case '+':
        hasil = operand1 + operand2; break;
    case '*':
        hasil = operand1 * operand2; break;
    case '/':
        hasil = operand1 / operand2; break;
    case '-':
        hasil = operand1 - operand2; break;
    case '%':
        hasil = fmod(operand1, operand2); break;
    }

    return hasil;
}

/**Postfix String Evaluator and Calculator*/
void PostfixGenerator::truncateFrontString(string &stringInput)
{
    string truncateFront;
    truncateFront = "";
    for (unsigned int i = 0; i < stringInput.length(); i++)
    {
        if (i == 0)
            continue;
        truncateFront = truncateFront + stringInput[i];
    }

    stringInput = truncateFront;
}

int PostfixGenerator::evalPostfix(string stringPostfix)
{
    int hasil = 0;
    int prio = 0;
    char karakter;
    char* nextBuf;
    int operand1, operand2, numBuffer;

    cout << "Postfix = " << stringPostfix << endl;

    while (!stringPostfix.empty())
    {
        karakter = stringPostfix[0];
        prio = priority(karakter);
        /**
            Priority is re-used to categorize the characters.
        */
        if (prio == 3 || prio == 4 || prio == 5)
        {
            operand2 = stackOperand.pop();
            operand1 = stackOperand.pop();
            hasil = calculate(karakter, operand1, operand2);
            stackOperand.push(hasil);

            truncateFrontString(stringPostfix);
        }
        else if (prio == 0)
        {
            numBuffer = strtol(stringPostfix.c_str(), &nextBuf, 10);
            stringPostfix = nextBuf;
            stackOperand.push(numBuffer);
        }
        else if (prio == 6)
        {
            truncateFrontString(stringPostfix);
        }
        else
        {
            /**
                WTH is this? just crash for safety.
            */
            cout << "Illegal operation/symbol!";
            exit(10);
        }
    }
    free(nextBuf);
    return stackOperand.pop();
}

float PostfixGenerator::floatEvalPostfix(string stringPostfix)
{
    float hasil = 0;
    int prio = 0;
    char karakter;
    char* nextBuf;
    float operand1, operand2;
    float numBuffer;

    cout << "Postfix = " << stringPostfix << endl;

    while (!stringPostfix.empty())
    {
        karakter = stringPostfix[0];
        prio = priority(karakter);
        /**
            Priority is re-used to categorize the characters.
        */
        if (prio == 3 || prio == 4 || prio == 5)
        {
            operand2 = floatStackOperand.pop();
            operand1 = floatStackOperand.pop();
            hasil = floatCalculate(karakter, operand1, operand2);
            floatStackOperand.push(hasil);

            truncateFrontString(stringPostfix);
        }
        else if (prio == 0)
        {
            numBuffer = strtof(stringPostfix.c_str(), &nextBuf);
            stringPostfix = nextBuf;
            floatStackOperand.push(numBuffer);
        }
        else if (prio == 6)
        {
            truncateFrontString(stringPostfix);
        }
        else
        {
            /**
                WTH is this? just crash for safety.
            */
            cout << "Illegal operation/symbol!";
            exit(10);
        }
    }
    free(nextBuf);
    return floatStackOperand.pop();
}

int PostfixGenerator::obsoleteEvalPostfix(string stringPostfix)
{
    int hasil = 0;
    char karakter, charBuf;
    int operand1, operand2, numBuffer;
    cout << "Postfix = " << stringPostfix << endl;
    string floatBuf = stringPostfix; char* nextBuf;
    for (unsigned int i = 0; i < stringPostfix.length(); i++)
    {
        karakter = stringPostfix[i];
        /**
            Priority is re-used to categorize the characters.
        */
        switch(priority(karakter))
        {
        case 3: case 4: case 5:
            operand2 = stackOperand.pop();
            operand1 = stackOperand.pop();
            hasil = calculate(karakter, operand1, operand2);
            stackOperand.push(hasil);
            break;
        case 0:
            strtol(floatBuf.c_str(), &nextBuf, 10);
            charBuf = karakter;
            numBuffer = 0;
            while (priority(charBuf) == 0)
            {
                numBuffer = (numBuffer * 10) + (charBuf - '0');
                i += 1;
                charBuf = stringPostfix[i];
            }
            /**
                Set back -1 to read the next sign because the charBuf now contains the sign,
                missing it is a very bad idea since it turns the program useless.
            */
            i -= 1;
            stackOperand.push(numBuffer);
            break;
        case 6:
            /**
                just skip the spaces, they serve nothing but as spacers in the new format
            */
            continue;
            break;
        default:
            /**
                WTH is this? just crash for safety.
            */
            cout << "Illegal operation/symbol!";
            exit(10);
            break;
        }
    }
    return stackOperand.pop();
}

/**Stub Function*/
int PostfixGenerator::evalInfix(string stringInfix)
{
    string stringPostfix = getResult(stringInfix);
    return evalPostfix(stringPostfix);
}

float PostfixGenerator::floatEvalInfix(string stringInfix)
{
    string stringPostfix = getResult(stringInfix);
    return floatEvalPostfix(stringPostfix);
}

int PostfixGenerator::showMenu()
{
    char pilihan;

    do
    {
        cout << "Welcome to Simple Calculator App" << endl << endl;
        cout << "Please select one of the options:"
            << endl
            << "1. Calculate Expression." << endl
            << "2. Convert an Infix Expression to Postfix Expression." << endl
            << "3. Exit this App" << endl
            << "Selection: ";
        cin >> pilihan;
    }
    while (pilihan < '1' || pilihan > '4');

    return pilihan;
}
