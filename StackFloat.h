#ifndef STACKFLOAT_H
#define STACKFLOAT_H
#define nullptr 0

class StackFloatNode
{
public:
    StackFloatNode* nextNode;
    StackFloatNode* prevNode;
    float data;
    int addressNo;

    StackFloatNode(float data, int addressNo);
};

class StackFloat
{
private:
    StackFloatNode* head;
    StackFloatNode* tail;

public:
    StackFloat();
    ~StackFloat();
    bool empty();
    int top;
    void push(float data);
    float pop();
    float peekTop();
    void emptyStack();
};

#endif // STACKFLOAT_H
