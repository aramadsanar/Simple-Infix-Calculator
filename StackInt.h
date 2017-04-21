#ifndef STACKINT_H
#define STACKINT_H
#define nullptr 0

class StackIntNode
{
public:
    StackIntNode* nextNode;
    StackIntNode* prevNode;
    int data;
    int addressNo;

    StackIntNode(int data, int addressNo);
};

class StackInt
{
private:
    StackIntNode* head;
    StackIntNode* tail;

public:
    StackInt();
    ~StackInt();
    bool empty();
    int top;
    void push(int data);
    int pop();
    int peekTop();
};

#endif // STACKINT_H
