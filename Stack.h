#ifndef STACK_H
#define STACK_H
#define nullptr 0
class StackNode
{
public:
    StackNode* nextNode;
    StackNode* prevNode;
    char data;
    int addressNo;

    StackNode(char data, int addressNo);
};

class Stack
{
private:
    StackNode* head;
    StackNode* tail;

public:
    Stack();
    ~Stack();
    bool empty();
    int top;
    void push(char data);
    char pop();
    void emptyStack();
    char peekTop();
};
#endif // STACK_H
