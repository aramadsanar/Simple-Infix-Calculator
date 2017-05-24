#ifndef INTQUEUE_H
#define INTQUEUE_H
#define nullptr 0

class QueueNode
{
public:
    QueueNode* berikut;
    QueueNode* sebelum;
    int data;

    QueueNode(int data);
};

class IntQueue
{
private:
    QueueNode* pertama;
    QueueNode* terakhir;
public:
    IntQueue();
    ~IntQueue();

    bool empty();

    void enqueue(int data);
    int dequeue();
};

#endif // INTQUEUE_H
