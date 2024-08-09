#include <iostream>
#include <string>

using namespace std;
int k=0;

int findS(const string& str)
{
    int temp=0;
    int n=str.size();
    int compareN=1;
    int len=0;
    for(int i=0; i<n; i++)
    {
        temp=0;
        string suffix = str.substr(i, compareN);
        for(int j=i+1; j<n; j++)
        {
            string compareS = str.substr(j, compareN);
            // cout << "suffix: " << suffix << ", compareS: " << compareS << endl;
            if(suffix == compareS)
                temp++;
        }
        // cout << "temp: " << temp << endl;
        if(temp >= k-1) 
        {
            i--;
            len = suffix.size();
            compareN++;
        }
    }

    return len;
}

int main()
{
    k=2;
    string str = "uhmhellouhmmnameislibe";
    // k=3;
    // string str = "banana";
    // k=3;
    // string str = "hello";
    cout << "ret: " << findS(str);    
    return 0;
}