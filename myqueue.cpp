#include "myqueue.h"
MyQueue::MyQueue()
{
     effSum =0 ;
     min = new LinkedListMinMax();
     min->prepareMinList();
     max = new LinkedListMinMax();
     max->prepareMaxList();

     head = tail = nullptr;
}


MyQueue::~MyQueue()
{
    delete min;
    delete max;
}


void MyQueue::push(Node *newNode)
{

    min->pushMin(newNode->eff);
    max->pushMax(newNode->eff);
    effSum+=newNode->eff;

    if(head == nullptr)
    {
        newNode->next = newNode->prev = newNode;
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = tail;
        tail = newNode;
    }
}


void MyQueue::displayTest()
{
    Node *temp = head;
    for(int i=0;i<size/2;i++)
    {
        std::cout<<temp->first_name<<" "<<temp->last_name<<std::endl;
        temp = temp->next;
    }
    std::cout<<"\n";
}


Node *MyQueue::pop()
{

    Node *temp= head;
    effSum-=temp->eff;

    head = head->next;
    tail->next = head;

    if(temp->eff == min->getMin())
        min->pop();
    if(temp->eff == max->getMax())
        max->pop();

    return temp;
}


 Node *MyQueue::getHead()
{
    return head;
}

bool MyQueue::isOkey()
{
    return max->getMax() - min->getMin() <= maxDiff;
}
