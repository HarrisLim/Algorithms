/*3216. Lexicographically Smallest String After a Swap*/

#include <iostream>
#include <string>

using namespace std;

string getSmallestString(string s) 
{
    for(int i=0; i<s.size()-1; i++)
    {
        if( ((s[i] % 2 == 0 && s[i+1] % 2 == 0) || 
             (s[i] % 2 != 0 && s[i+1] % 2 != 0)) &&
            (s[i] > s[i+1]) )
        {
            // if(s.size() < 3 && s[i] < s[i+1]) return s; 
            char temp;
            temp = s[i];
            s[i] = s[i+1];
            s[i+1] = temp;
            break;
        }
    }
    return s;
}
int main()
{
    cout << getSmallestString("131");

    return 0;
}