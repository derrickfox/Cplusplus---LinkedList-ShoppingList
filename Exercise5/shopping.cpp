//shopping.cpp Implementation file for the Shopping class
#include "shopping.h"
#include <iostream>
#include <string>
using namespace std;

Shopping * Shopping::tail=NULL;
 
Shopping::Shopping(int v, char *s)
{
    QTY = v;
    strcpy(item, s);
    next = NULL;
} // constructor

void Shopping::addItem(Shopping *& h)
{
    if (h == NULL) // the list is empty
    {
        h = this;
        tail = this;
        cout << "h = " << h << endl;
        cout << "tail = " << tail << endl;
    }
    else
    {
        ///////////////////////////
        if (this->item >= h->item) {
            tail->next = this;
            tail = this;
        }
        ///////////////////////////
        /*
        tail->next = this;
        tail = this;
         */
    }
    size++;
} // addItem

void Shopping::show()
{
    cout<<QTY<<" "<<item<<endl;
    if (next)
        next->show(); // recursive call to the neighbor
} // show

void Shopping::clean()
{
    Shopping *t = next;
    delete this;
    if (t)
        t->clean();
} // clean

void Shopping::sortByItemName(Shopping* head)
{
    Shopping *curr = NULL;
    Shopping *trail = NULL;
    Shopping *temp = NULL;
    
    for(int i = 0; i<size; ++i)
    {
        curr = trail = head;
        while (curr->next != NULL)
        {
            if (curr->item > curr->next->item)
            {
                temp = curr->next;
                curr->next = curr->next->next;
                temp->next = curr;
                
                if(curr == head)
                    head = trail = temp;
                else
                    trail->next = temp;
                curr = temp;
            }
            trail = curr;
            curr = curr->next;
        }
    }
}