#include <iostream>
#include "../linkedlist/linkedlist.h"

using namespace std;

class Queue {
    private:
        LinkedList *ll;

    public:
        Queue() {
            ll = new(LinkedList);
        };

        int enqueue(int element) {
            return ll->insert_head(element);
        }

        int dequeue() {
            return ll->remove_tail();
        }

        void disp() {
            ll->disp();
        }
};

int main(int argc, char const *argv[])
{
    Queue *q = new Queue();

    cout << "enqueue test..." << endl;
    q->enqueue(1);
    q->disp();
    q->enqueue(21);
    q->disp();
    q->enqueue(13);
    q->disp();
    q->enqueue(54);
    q->disp();

    cout << "dequeue test..." << endl;
    q->dequeue();
    q->disp();
    q->dequeue();
    q->disp();
    q->dequeue();
    q->disp();

    return 0;
}