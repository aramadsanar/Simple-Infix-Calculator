/**
    INFIX TO POSTFIX GENERATOR
         AND EVALUATOR

    Source: Teori dan Aplikasi Struktur Data dengan C++ by Abdul Kadir
    Changes Made:
    - Replaced the whole stack/queue library with linked lists to remove limitation
    - Replaced the string format so this app supports multi-digit postfix
    - Added input validator to check whether the parentheses are already balanced or not
    - Rewrote the evaluator engine to support both negative number and float/decimal numbers
    LastEdit: 4/21/2017 (Happy weed day!)
*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "../PostfixGenerator.h"

#define nullptr 0

using namespace std;
extern int getMax(int a, int b);
bool isFloatString(string stringInfix)
{
    for (unsigned int i = 0; i < stringInfix.length(); i++)
    {
        //indeed, this is very stupid and naive way to check whether the string contains float number or not
        if (stringInfix[i] == '.')
            return true;
    }
    return false;
}

int main(int argc, char** argv)
{
    //the whole infix processor is self-contained in this class so all these codes in main() are just test codes and user interface.
    PostfixGenerator postfix;

    int userChoice = 0;
    string userInput = "";
//    char inputFeed;
    bool isFloat;
    string postfixString;
    do
    {
        userChoice = postfix.showMenu();
        switch (userChoice)
        {
        case '1':
            system("cls");
            cout << endl << "Please input your expression: ";
            getchar();
            std::getline(std::cin, userInput);
            //cin >>inputFeed;
            postfixString = postfix.getResult(userInput);
            cout << endl << "This expression in Postfix: " << postfixString << endl;;
            cout << "Result: ";

            isFloat = isFloatString(userInput);
            if (isFloat)
                cout << postfix.floatEvalInfix(postfixString);
            else
                cout << postfix.evalInfix(postfixString);

            cout << endl;
            break;
        case '2':
            system("cls");
            cout << endl << "Please input your expression: ";
            cin >> userInput;
            cout << endl << "This expression in Postfix: " << postfix.getResult(userInput) << endl;
            break;
        }
    } while (userChoice != '3');
    return 0;
}
