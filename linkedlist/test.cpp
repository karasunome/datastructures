#include <iostream>
#include "linkedlist.h"

using namespace std;

int main(int argc, char const *argv[])
{
    LinkedList *ll = new LinkedList();

    cout << "appending test..." << endl;
    ll->append(1);
    ll->disp();
    ll->append(21);
    ll->disp();
    ll->append(13);
    ll->disp();
    ll->append(54);
    ll->disp();

    cout << "inserting head test..." << endl;
    ll->insert_head(12);
    ll->disp();
    ll->insert_head(212);
    ll->disp();
    ll->insert_head(133);
    ll->disp();
    ll->insert_head(154);
    ll->disp();

    cout << "remove test..." << endl;
    ll->remove(21);
    ll->disp();
    ll->remove(133);
    ll->disp();
    ll->remove(54);
    ll->disp();
    
    ll->remove_tail();
    ll->disp();

    return 0;
}