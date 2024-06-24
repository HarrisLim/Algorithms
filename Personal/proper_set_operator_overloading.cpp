#include <iostream>
#include <set>
#include <iterator>

using namespace std;

class MySet {
    private:
        set<int> elements;
    public:
        // constructor
        MySet(initializer_list<int> init): elements(init) {}

        // add elements 
        void add(int elem)
        {
            elements.insert(elem);
        }

        // operator overloading (compare proper set)
        bool operator<(const MySet& other) const 
        {
            if(this->elements.size() >= other.elements.size())
            {
                return false;
            }
            for(const int& elem : this->elements)
            {
                cout << elem << " ";
                // elem is kind of set1, and then find numbers in set2
                // if 3 is the last number of set1, it must be proper set.
                if(other.elements.find(elem) == other.elements.end())
                {
                    return false;
                }
            }
            return true;
        }
        // print set function
        void print() const 
        {
            cout << "{";
            for(const int& elem: elements)
                cout << elem << " ";
            cout << "}" << endl;
        }
};

int main()
{
    MySet set1 = {1, 2, 3};
    MySet set2 = {1, 2, 3, 4, 5};

    set1.print();
    set2.print();

    if(set1 < set2)
        cout << "set1 is proper set of set2" << endl;
    else
        cout << "set1 isnt proper set of set2" << endl;

    return 0;
}
