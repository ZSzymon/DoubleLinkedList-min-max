#include <bits/stdc++.h>
#include "linkedlistminmax.h"
#include "myqueue.h"



int main()
{
    bool foundAnyPerson= false;
        long int bestIndex = 0;
        Node *frontB, *frontA;
        std::ios_base::sync_with_stdio(false);
        MyQueue *qA = new MyQueue();
        MyQueue *qB = new MyQueue();
        long int eff;

        std::string firstName,lastName;

        std::cin>>size>>maxDiff;
        for(int i=0;i<size;i++)
        {
            std::cin>>firstName>>lastName>>eff;
            //dziele ich na dwie grupy.
            if(i<size/2)
                qA->push(new Node(firstName,lastName,eff));
            else
                qB->push(new Node(firstName,lastName,eff));
        }

        for(int i=0;i<size/2;i++)
        {
            if(qA->isOkey() && qB->isOkey())
            {
                if(abs(qA->effSum - qB->effSum) < slighestDiff)
                {
                    if(!foundAnyPerson)
                        foundAnyPerson = true;
                    bestIndex = i;
                    slighestDiff = abs(qA->effSum - qB->effSum);
                }
            }

            frontA = qA->pop();
            frontB = qB->pop();
            qA->push(frontB);
            qB->push(frontA);

        }



        if(foundAnyPerson == false)
        {
            std::cout<<"NIE\n";
        }
        else {
            //łącze dwie grupy
            qA->tail->next = qB->head;
            qB->tail->next = qA->head;
            Node *temp = qA->head;
            std::cout<<"\n";

            for(int i=0;i <size/2 +bestIndex;i++)
            {
              temp = temp -> next;
            }
            for(int i=0;i<size;i++)
            {
                std::cout<<temp->first_name<<" "<<temp->last_name<<"\n";
                temp = temp -> next;
            }


        }

        delete qB;
        delete qA;

        return 0;
}

