#include <iostream>
#include <stack>

using namespace std;

vector<int> h = {1, 5, 6, 6, 7, 8, 5, 3};

int solveStack()
{
    stack<int> remaining;
    h.push_back(0);
    int ret =0;
    for(int i=0; i<h.size(); i++)
    {
        while(!remaining.empty() && h[remaining.top()] >= h[i])
        {
            int j = remaining.top();
            cout << "j: " << j << ", i: " << i << endl;
            remaining.pop();
            int width = -1;
            if(remaining.empty())
                width = i;
            else
                width = (i - remaining.top() - 1);
            
            ret = max(ret, h[j] * width);
            cout << "width: " << width << ", ret: "<< ret << endl; 
        }
        cout << "push: " << i << " ";
        remaining.push(i);
    }
    return ret;
}

int main()
{
    cout << "ret: " << solveStack();

    return 0;
}