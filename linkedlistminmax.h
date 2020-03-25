#ifndef LINKEDLISTMINMAX_H
#define LINKEDLISTMINMAX_H
#include <iostream>
struct El
{
    El(long int eff):eff(eff)
    {
        next = nullptr;
    }
    long int eff;
    El *next,*prev;
    ~El(){}
};

class LinkedListMinMax
{
    El *head, *tail,*tempPosition;
    long int size;
public:

    LinkedListMinMax();
    ~LinkedListMinMax();
    void pushMax(long int eff);
    void pushMin(long int eff);

    inline int getMin()
    {
        return tail->prev->eff;
    }
    inline int getMax()
    {
        return tail->prev->eff;
    }

    void pop();


    void displayTest();

    void prepareMaxList();
    void prepareMinList();
};

#endif // LINKEDLISTMINMAX_H
