#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <linkedlistminmax.h>
struct Node
{
    Node(std::string first_word,std::string last_name, int eff)
        :first_name(first_word),last_name(last_name),eff(eff)
    {next = prev = nullptr;}
    Node *next;
    Node *prev;
    std::string first_name,last_name;
    long int eff;
};

class MyQueue
{
public:
    LinkedListMinMax *min,*max;
    Node *head, *tail;
    MyQueue();
    ~MyQueue();
    long int effSum;

    void push(Node *newNode);
    void displayTest();

    Node *pop();
    Node *getHead();
    bool isOkey();
};
    static int slighestDiff = 20000000;
    static int maxDiff;
    static int size;
    static std::string *answers;

#endif // QUEUE_H
