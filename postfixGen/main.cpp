/**
    INFIX TO POSTFIX GENERATOR
         AND EVALUATOR

    Source: Teori dan Aplikasi Struktur Data dengan C++ by Abdul Kadir
    Changes Made:
    - Replaced the whole stack/queue library with linked lists to remove limitation
    - Replaced the string format so this app supports multi-digit postfix
    - Added input validator to check whether the parentheses are already balanced or not
    - Rewrote the evaluator engine to support both negative number and float/decimal numbers
    LastEdit: 4/21/2017
*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "../PostfixGenerator.h"

#define nullptr 0

using namespace std;

bool isFloatString(string stringInfix)
{
    for (unsigned int i = 0; i < stringInfix.length(); i++)
    {
        if (stringInfix[i] == '.')
            return true;
    }
    return false;
}

int main()
{
    PostfixGenerator postfix;

    int userChoice = 0;
    string userInput = "";
    char inputFeed;
    bool isFloat;

    do
    {
        userChoice = postfix.showMenu();
        switch (userChoice)
        {
        case '1':
            cout << endl << "Please input your expression: ";
            cin >> userInput;
            cin >>inputFeed;

            cout << endl << "This expression in Postfix: " << postfix.getResult(userInput) << endl;;
            cout << "Result: ";

            isFloat = isFloatString(userInput);
            if (isFloat)
                cout << postfix.floatEvalInfix(userInput);
            else
                cout << postfix.evalInfix(userInput);

            cout << endl;
            break;
        case '2':
            cout << endl << "Please input your expression: ";
            cin >> userInput;
            cout << endl << "This expression in Postfix: " << postfix.getResult(userInput) << endl;
            break;
        }
    }
    while (userChoice != '3');
    return 0;
}
