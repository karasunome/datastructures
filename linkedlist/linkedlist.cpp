#include <iostream>

#define ERROR       (-1)
#define OK          (0)

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class LinkedList {
    private:
        Node *head = nullptr;
        int size = 0;

        Node *create_node(int data) {
            Node *node = new Node();
            node->data = data;
            node->next = nullptr;
            return node;
        }

    public:
        int append(int data) {
            Node *node;
            if (!head) {
                head = create_node(data);
                return OK;
            }

            for (node = head; node->next != NULL; node = node->next);

            node->next = create_node(data);
            return OK;
        }

        int insert_head(int data) {
            Node *node;
            if (!head) {
                head = create_node(data);
                return OK;
            }

            node = create_node(data);
            node->next = head;
            head = node;
            return OK;    
        }

        void remove(int data) {
            Node *node;
            Node *next_node;
            for (node = head; node->next != NULL; node = node->next) {
                next_node = node->next;
                if (next_node->data == data) {
                    node->next = next_node->next;
                    delete next_node;
                }
            }
        }
    
        void disp(void) {
            Node *node;
            for (node = head; node != NULL; node = node->next) {
                cout << "[" << node->data << "] ";
            }
            cout << endl;
        }
};

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

    return 0;
}
