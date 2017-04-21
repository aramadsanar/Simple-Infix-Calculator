#include "Stack.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

StackNode::StackNode(char data, int addressNo)
{
    StackNode::data = data;
    StackNode::addressNo = addressNo;

    nextNode = nullptr;
    prevNode = nullptr;
}

Stack::Stack()
{
    head = nullptr;
    tail = nullptr;
    top = -1;
}

Stack::~Stack()
{
    StackNode* erasePtr;

    while (head != nullptr)
    {
        erasePtr = head;
        head = head->nextNode;

        delete erasePtr;
    }
}

bool Stack::empty()
{
    return (head == nullptr);
}

void Stack::push(char data)
{
    top += 1;
    StackNode* newData = new StackNode(data, top);

    if (empty())
        tail = newData;
    else
        head->prevNode = newData;

    newData->nextNode = head;
    newData->prevNode = nullptr;
    head = newData;
}

char Stack::peekTop()
{
    if (empty())
        return 0;

    StackNode* ptrReturn = head;
    return ptrReturn->data;
}

char Stack::pop()
{
    if (empty())
    {
        cout << "Senarai kosong!" << endl;
        return 0;
    }

    StackNode* ptrHapus = head;
    char buffer = ptrHapus->data;

    if (head->nextNode == nullptr)
        tail = nullptr;
    else
        head->nextNode->prevNode = nullptr;

    head = head->nextNode;

    delete ptrHapus;
    top -= 1;
    return buffer;
}

void Stack::emptyStack()
{
    StackNode* erasePtr;

    while (head != nullptr)
    {
        erasePtr = head;
        head = head->nextNode;

        delete erasePtr;
    }
}
