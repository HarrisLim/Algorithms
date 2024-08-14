#include <iostream>
#include <vector>

using namespace std;

// insert new value to maximum heap that stores integers 
void push_heap(vector<int>& heap, int newValue)
{
    // insert newValue at the farthest of heap
    heap.push_back(newValue);
    // currunt newValue's position
    int idx = heap.size() - 1;
    // till meet root or meet ancestor has element larger than newValue
    while(idx > 0 && heap[(idx-1) / 2] < heap[idx])
    {
        swap(heap[idx], heap[(idx-1) / 2]);
        idx = (idx -1) /2;
    }
}

// remove max heap 
void pop_heap(vector<int>& heap)
{
    // bring the farthest value of heap and replace to root
    heap[0] = heap.back();
    heap.pop_back();
    int here=0;
    while(true)
    {
        int left = here * 2 + 1, right = here * 2 + 2;
        // in case of reach to leaf
        if(left >= heap.size()) break;
        // find the position that heap[here] can go down
        int next = here;
        if(heap[next] < heap[left])
            next = left;
        if(right<heap.size() && heap[next] < heap[right])
            next = right;
        if(next == here) break;
        swap(heap[here], heap[next]);
        here = next;
    }
}