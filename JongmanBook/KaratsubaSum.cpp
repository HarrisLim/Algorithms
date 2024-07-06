#include <iostream>
#include <vector>

using namespace std; 

// round up at num[] 
void normalize(vector<int>& num)
{
    num.push_back(0);
    // round up
    for(int i=0; i+1 < num.size(); i++)
    {
        if(num[i] < 0)
        {
            // - value processing
            int borrow = (abs(num[i])+9) / 10;
            num[i+1] -= borrow;
            num[i] += borrow * 10;
        }
        else
        {
            num[i+1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while(num.size() > 1 && num.back() == 0) num.pop_back();
}

// insert into array in the order of units
// ex) multiply[3,2,1][6,5,4] = 123*456 = 56088 = [8,8,0,6,5]
vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
    //init as 0
    vector<int> c(a.size() + b.size() + 1, 0);
    for(int i=0; i<a.size(); i++)
        for(int j=0; j<b.size(); j++)
            c[i+j] += a[i] * b[j];
    normalize(c);
    return c;
}

int main()
{
    vector<int> ret;
    vector<int> a = {3, 2, 1};
    vector<int> b = {6, 5, 4};
    ret = multiply(a, b);
    cout << "ret: ";
    for(int i=0; i<ret.size(); i++)
        cout << ret[i] << ' ';

    return 0;
}