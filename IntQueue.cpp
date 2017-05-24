#include "IntQueue.h"
#include <iostream>
#include <string>

using namespace std;

QueueNode::QueueNode(int data)
{
    QueueNode::data = data;
    berikut = nullptr;
    sebelum = nullptr;
}

IntQueue::IntQueue()
{
    pertama = nullptr;
    terakhir = nullptr;
}

IntQueue::~IntQueue()
{
    QueueNode* ptrHapus;
    while (pertama != nullptr)
    {
        ptrHapus = pertama;
        pertama = pertama->berikut;

        delete ptrHapus;
    }
}

bool IntQueue::empty()
{
    return (pertama == nullptr);
}

void IntQueue::enqueue(int data)
{
    QueueNode* ptrBaru = new QueueNode(data);

    if (empty())
        pertama = ptrBaru;
    else
    {
        ptrBaru->sebelum = terakhir;
        terakhir->berikut = ptrBaru;
    }

    ptrBaru->berikut = nullptr;
    terakhir = ptrBaru;
}

int IntQueue::dequeue()
{
    if (empty())
    {
        cout << "Senarai kosong!" << endl;
        return 0;
    }

    QueueNode* ptrHapus = pertama;
    int buffer = ptrHapus->data;

    if (pertama->berikut == nullptr)
        terakhir = nullptr;
    else
        pertama->berikut->sebelum = nullptr;

    pertama = pertama->berikut;

    delete ptrHapus;
    return buffer;
}
