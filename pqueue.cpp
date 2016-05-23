#ifndef PQUEUE__H
#define PQUEUE__H
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class pqueue
{
    public:
        int size;
        int numE;
		T* heap;
		pqueue(vector<T> elem)
        {
            heap = new T[elem.size()];
            for(int i=0; i < elem.size(); i++)
            {
                heap[i] = elem[i];
            }
            size = elem.size();
            numE = 0;
        }
		void minheapify(int index)
        {
            int r = index*2 + 2;
            int l = index*2 + 1;
            int b = 0;
            
            //if any child is smaller or not
            if((heap[r] < heap[index] || heap[l] < heap[index]) && !(r > size-1 || l > size-1))
            {
                //right is smaller
                if(heap[r] < heap[l])
                {
                    T temp = heap[r];
                    heap[r] = heap[index];
                    heap[index] = temp;
                    b = 1;
                }
                //left is smaller
                else
                {
                    T temp = heap[l];
                    heap[l] = heap[index];
                    heap[index] = temp;
                }
                
                if(b == 1)
                    minheapify(r);
                else
                    minheapify(l);
            }
        
        }
		T ExtractMin()
        {
            T temp = heap[0];
            heap[0] = heap[size-1];
            T* nheap = new T[size-1];
            size = size-1;
            
            for(int i=0; i < size; i++)
            {
                nheap[i] = heap[i];
            }
            heap = nheap;
            return temp;
        
        }
		
};


#endif
