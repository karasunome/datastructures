#include <iostream>

using namespace std;

static void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

static bool min_compare(int a, int b)
{
    return (a > b);
}

static bool max_compare(int a, int b)
{
    return (a < b);
}

class Heap 
{
    private:
        int *heap_array;
        int capacity;
        int size;
        bool (* compare)(int, int);

        void heapify(int idx) 
        {
            int p_idx = (idx-1)/2;
            int left = (2*idx)+1;
            int right = (2*idx)+2;
            if (compare(heap_array[p_idx], heap_array[idx])) {
                swap(heap_array[p_idx], heap_array[idx]);
                heapify(p_idx);
            } else if (left < size && compare(heap_array[idx], heap_array[left])) {
                swap(heap_array[left], heap_array[idx]);
                heapify(left);
            } else if (right < size && compare(heap_array[idx], heap_array[right])) {
                swap(heap_array[right], heap_array[idx]);
                heapify(right);
            } else {
                /* do nothing */
            }
        }

    public:
        bool is_empty(void) 
        {
            return (0 == size);
        }

        int get_size(void) 
        {
            return size;
        }

        void clear(void) {
            size = 0;
        }

        int contains(int val) 
        {
            int idx = -1;
            for (int i=0; i<size; i++)
            {
                if (val == heap_array[i]) 
                {
                    idx = i;
                    break;
                }
            }
            return idx; 
        }

        void disp(void) 
        {
            cout << "heap => ";
            for (int i=0; i<size; i++)
                cout << heap_array[i] << " ";
            cout << endl;
        }

        int add(int val) 
        {
            if (size == capacity)
                return -1;

            heap_array[size] = val;
            size++;
            
            heapify(size-1);
            return 0;
        }

        int remove_val(int val)
        {
            int idx;
            if (-1 == (idx = contains(val)))
                return -1;

            swap(&heap_array[idx], &heap_array[size-1]);
            cout << val << " "; disp();
            size--;
            
            heapify(idx);
            return 0;
        }

        Heap(int cap, int type) 
        {
            this->capacity = cap;
            heap_array = new int[cap];
            this->size = 0;

            if(type) compare = min_compare;
            else compare = max_compare;
        }
        ~Heap() 
        {
            this->capacity = capacity;
            delete [] heap_array;
        }

};

int main(int argc, char const *argv[])
{
    const int capacity = 10;
    const bool min_heap = true;
    const bool max_heap = false;

    Heap h(capacity, max_heap);

    cout << "adding test..." << endl;
    h.add(8);
    h.disp();
    h.add(5);
    h.disp();
    h.add(-9);
    h.disp();
    h.add(-15);
    h.disp();
    h.add(1);
    h.disp();
    h.add(16);
    h.disp();

    cout << "remove value test..." << endl;
    h.remove_val(-9);
    h.disp();
    h.remove_val(-10);
    h.disp();
    h.remove_val(16);
    h.disp();
    h.remove_val(5);
    h.disp();

    return 0;
}


