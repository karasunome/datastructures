#include <iostream>

#define ERROR       (-1)
#define OK          (0)

using namespace std;

class Stack {
    private:
        int top = -1;
        int *mem = nullptr;
        int size;

    public:
        Stack(const int size) {
            this->size = size;
            this->mem = new int[this->size];
        }
        ~Stack() {
            delete this->mem;
        }

        int is_full(void) {
            return (top == (size-1));
        }

        int is_empty(void) {
            return (top < 0);
        }

        void push(int data) {
            if (is_full())
                return;
            mem[++top] = data;
        }

        int pop(void) {
            if (is_empty())
                return -1;
            return (mem[top--]);
        }

        int peek(void) {
            if (is_empty())
                return -1;
            return (mem[top]);
        }
    
        void disp(void) {
            int i;
            if (is_empty())
                return;

            for (i=0; i<=top; i++) {
                cout << "[" << mem[i] << "] ";
            }
            cout << endl;
        }
};

int main(int argc, char const *argv[])
{
    Stack *s = new Stack(100);

    cout << "pushing test..." << endl;
    s->push(1);
    s->push(21);
    s->push(13);
    s->push(54);
    s->disp();

    cout << "peek test..." << endl;
    cout << "top=" << s->peek() << endl;

    cout << "top=" << s->pop() << endl;
    s->disp();
    cout << "top=" << s->pop() << endl;
    s->disp();
    cout << "top=" << s->pop() << endl;
    s->disp();
    cout << "top=" << s->pop() << endl;
    s->disp();
    cout << "top=" << s->pop() << endl;
    s->disp();

    return 0;
}
