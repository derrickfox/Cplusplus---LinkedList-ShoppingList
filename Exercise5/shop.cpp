// The driver for Shopping example (linked List).
#include <fstream>
#include <iostream>
#include "shopping.h"
using namespace std;

void buildList(ifstream &, Shopping *&);

int main()
{
    ifstream myfile("shoppinglist.txt");
    
    Shopping *head = NULL;
    
    if (myfile.fail())
    {
        cerr << "Cannot open input file\n";
        return 1;
    }
    
    buildList(myfile, head);
    
    if (head) head->show();
    
    if (head) head->clean();
    
    myfile.close();
    return 0;
} // main
/*
 This recursive function stops calling itself when the eof of file condition is reached. Repeated operations:
 Read a record from the input file
 Create a node for the current record
 Ask the new node to add itself to the list
 */
void buildList(ifstream &infile, Shopping *&h)
{
    char s[21];
    int k;
    Shopping *temp;
    
    if (infile.eof())
        return; // stop recursive call
    infile >> k >> s;
    temp = new Shopping(k, s);
    
    temp->addItem(h);
    buildList(infile, h); // recursive call
}// buildList










