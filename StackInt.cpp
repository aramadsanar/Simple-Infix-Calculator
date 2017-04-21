#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "StackInt.h"
using namespace std;

StackIntNode::StackIntNode(int data, int addressNo)
{
    StackIntNode::data = data;
    StackIntNode::addressNo = addressNo;

    nextNode = nullptr;
    prevNode = nullptr;
}

StackInt::StackInt()
{
    head = nullptr;
    tail = nullptr;
    top = -1;
}

StackInt::~StackInt()
{
    StackIntNode* erasePtr;

    while (head != nullptr)
    {
        erasePtr = head;
        head = head->nextNode;

        delete erasePtr;
    }
}

bool StackInt::empty()
{
    return (head == nullptr);
}

void StackInt::push(int data)
{
    top += 1;
    StackIntNode* newData = new StackIntNode(data, top);

    if (empty())
        tail = newData;
    else
        head->prevNode = newData;

    newData->nextNode = head;
    newData->prevNode = nullptr;
    head = newData;
}

int StackInt::pop()
{
    if (empty())
    {
        cout << "Stack is empty!" << endl << "The postfix string format might be corrupted." << endl;;
        exit(1);
        return 0;
    }

    StackIntNode* ptrHapus = head;
    int buffer = ptrHapus->data;

    if (head->nextNode == nullptr)
        tail = nullptr;
    else
        head->nextNode->prevNode = nullptr;

    head = head->nextNode;

    delete ptrHapus;
    top -= 1;
    return buffer;
}

int StackInt::peekTop()
{
    if (empty())
        return 0;

    StackIntNode* ptrReturn = head;
    return ptrReturn->data;
}
