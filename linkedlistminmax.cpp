#include "linkedlistminmax.h"

void LinkedListMinMax::prepareMaxList(){
    head = new El(INT_MIN);
    tail = new El(INT_MAX);
    head->next = head->prev = tail;
    tail->next = tail->prev = head;
}
void LinkedListMinMax::prepareMinList(){
    head = new El(INT_MAX);
    tail = new El(INT_MIN);
    head->next = head->prev = tail;
    tail->next = tail->prev = head;
}

void LinkedListMinMax::pushMin(long int eff)
{
    El *newNode = new El(eff);
    El *temp = head->next;
   tempPosition = head->next;

    while (tempPosition->eff > eff)
    {
        temp = tempPosition;
        tempPosition = tempPosition->next;
        delete temp;
    }

    head->next = newNode;
    newNode->prev = head;
    newNode->next = tempPosition;
    tempPosition->prev = newNode;

}

void LinkedListMinMax::pushMax(long int eff)
{
    El *newNode = new El(eff);
    El *temp;

    tempPosition = head->next;

    while (tempPosition->eff < eff)
    {
        temp = tempPosition;
        tempPosition = tempPosition->next;
        delete temp;
    }

    head->next = newNode;
    newNode->prev = head;
    newNode->next = tempPosition;
    tempPosition->prev = newNode;
}

void LinkedListMinMax::displayTest()
{
    El *temp = head;
    std::cout<<"\n\n";
    while(temp->next!=tail){
        std::cout<<temp->eff<<"\n";
        temp = temp->next;
    }
    std::cout<<temp->eff<<std::endl;

}
void LinkedListMinMax::pop()
{
    El *temp = tail->prev;
    tail->prev = temp->prev;
    temp->prev->next = tail;
    delete temp;
}

LinkedListMinMax::LinkedListMinMax()
{
    head  = tail = tempPosition = nullptr;
    size = 0;
}
LinkedListMinMax::~LinkedListMinMax()
{

}
