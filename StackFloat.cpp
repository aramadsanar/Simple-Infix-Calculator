#include "StackFloat.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

StackFloatNode::StackFloatNode(float data, int addressNo)
{
    StackFloatNode::data = data;
    StackFloatNode::addressNo = addressNo;

    nextNode = nullptr;
    prevNode = nullptr;
}

StackFloat::StackFloat()
{
    head = nullptr;
    tail = nullptr;
    top = -1;
}

StackFloat::~StackFloat()
{
    StackFloatNode* erasePtr;

    while (head != nullptr)
    {
        erasePtr = head;
        head = head->nextNode;

        delete erasePtr;
    }
}

bool StackFloat::empty()
{
    return (head == nullptr);
}

void StackFloat::push(float data)
{
    top += 1;
    StackFloatNode* newData = new StackFloatNode(data, top);

    if (empty())
        tail = newData;
    else
        head->prevNode = newData;

    newData->nextNode = head;
    newData->prevNode = nullptr;
    head = newData;
}

float StackFloat::pop()
{
    if (empty())
    {
        cout << "Stack is empty!" << endl << "The postfix string format might be corrupted." << endl;;
        exit(1);
        return 0;
    }

    StackFloatNode* ptrHapus = head;
    float buffer = ptrHapus->data;

    if (head->nextNode == nullptr)
        tail = nullptr;
    else
        head->nextNode->prevNode = nullptr;

    head = head->nextNode;

    delete ptrHapus;
    top -= 1;
    return buffer;
}

float StackFloat::peekTop()
{
    if (empty())
        return 0;

    StackFloatNode* ptrReturn = head;
    return ptrReturn->data;
}

void StackFloat::emptyStack()
{
    StackFloatNode* erasePtr;

    while (head != nullptr)
    {
        erasePtr = head;
        head = head->nextNode;

        delete erasePtr;
    }
}
