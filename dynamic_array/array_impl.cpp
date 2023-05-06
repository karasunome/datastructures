#include <iostream>

#define ERROR       (-1)
#define OK          (0)

using namespace std;

class ArrayInt {
    private:
        int *head = nullptr;
        int size = 0;

    public:
        void add(int element) {
            int i;
            int *head_tmp = new int[size+1];
            for (i=0; i<size; i++)
                (head_tmp)[i] = (head)[i];
            size++;
            (head_tmp)[i] = element;
            if (!head)
                delete head;
            head = head_tmp;
        }

        int search(int element) {
            int i, idx = -1;
            for (int i = 0; i < size; i++) {
                if (element == this->head[i]) {
                    idx = i;
                    break;
                } 
            }
            return idx;       
        }

        void remove(int element) {
            int *head_tmp;
            int i, j=0, idx = this->search(element);
            if (0 > idx)
                return;
            head_tmp = new int[size-1];
            for (i=0; i<size; i++) {
                if (i != idx) {
                    (head_tmp)[j] = this->head[i];
                    j++;
                }
            }
            size--;
            delete head;
            head = head_tmp;
        }

        void remove_at(int idx) {
            int *head_tmp;
            int i,j=0;
            if (size <= idx)
                return;
            head_tmp = new int[size-1];
            for (i=0; i<size; i++) {
                if (i != idx) {
                    (head_tmp)[j] = this->head[i];
                    j++;
                }
            }
            size--;
            delete head;
            head = head_tmp;
        }
    
        void disp(void) {
            cout << "array[" << size << "] = ";
            for (int i = 0; i < size; i++)
                cout << this->head[i] << " ";
            cout << endl;
        }
};

int main(int argc, char const *argv[])
{
    ArrayInt *a = new ArrayInt();

    cout << "adding test..." << endl;
    a->add(1);
    a->disp();
    a->add(21);
    a->disp();
    a->add(13);
    a->disp();
    a->add(54);
    a->disp();
    a->add(-12);
    a->disp();
    a->add(-12);
    a->disp();

    cout << "search test..." << endl;
    cout << "search[890]" << " = " << a->search(890) << endl;
    cout << "search[-12]" << " = " << a->search(-12) << endl;
    cout << "search[54]" << " = " << a->search(54) << endl;

    cout << "remove test..." << endl;
    a->remove(21);
    a->disp();
    a->remove(890);
    a->disp();
    a->remove(-12);
    a->disp();
    a->remove(-12);
    a->disp();

    cout << "remove at test..." << endl;
    a->remove_at(0);
    a->disp();
    a->remove_at(1);
    a->disp();

    return 0;
}
