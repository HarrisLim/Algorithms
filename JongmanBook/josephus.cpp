#include <iostream>
#include <list>

using namespace std;

// n: the number of people, k: move count clockwise
int n=6, k=3;

void josephus(int N, int K)
{
    list<int> survivors;
    for(int i=1; i<=n; i++) survivors.push_back(i);
    list<int>::iterator kill = survivors.begin();

    while(N>2)
    {
        kill = survivors.erase(kill);
        if(kill == survivors.end()) kill = survivors.begin();
        N--;

        for(int i=0; i<k-1; i++)
        {
            kill++;
            if(kill == survivors.end()) kill = survivors.begin();
        }
    }
    cout << survivors.front() << " " << survivors.back() << endl;
}
int main()
{
    int cnt=0;
    list<int> L = {1, 2, 3, 4, 5, 6};
    L.pop_front();
    while(L.size() > 2)
    {
        cnt++;
        if(cnt==3)
        {
            L.pop_front();
            cnt=0;
        }
        else
        {
            L.push_back(L.front());
            L.pop_front();
        }
    }
    for(int x : L)
        cout << x << " ";
    cout << endl;

    josephus(6, 3);
    return 0;
}

