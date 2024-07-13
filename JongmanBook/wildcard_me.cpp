#include <iostream>
#include <string>
#include <vector>

using namespace std;

string w = "*p*";
vector<string> wArr = {"help", "papa", "hello"};

bool match(const string& w, const string& s)
{
    int pos=0;

    while(pos<w.size() && pos <s.size() && (w[pos] == '?' || w[pos]==s[pos]))
        pos++;
    
    if(pos == w.size())
        return pos == s.size();
    
    if(w[pos]=='*')
        for(int skip=0; skip+pos<=s.size(); skip++)
            if(match(w.substr(pos+1), s.substr(pos+skip)))
                return true;
    
    return false;
}

int main()
{
    cout << "ret: " << endl;
    for(int i=0; i<wArr.size(); i++)
        if(match(w, wArr[i]) == true)
            cout << wArr[i] << ' ';
    
    return 0;
}