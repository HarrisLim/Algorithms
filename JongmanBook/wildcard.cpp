#include <iostream>
#include <string>
#include <vector>

using namespace std;

// string w = "he?p";
string w = "*p*";
// the number of words
// vector<string> wArr = {"help", "heap", "helpp"};
vector<string> wArr = {"help", "papa", "hello"};

bool match(const string& w, const string& s)
{
    int pos = 0;
    while(pos < s.size() && pos < w.size() && 
            (w[pos] == '?' || w[pos] == s[pos]))
        pos++;

    if(pos == w.size())
        return pos == s.size();
    
    if(w[pos] == '*')
        for(int skip=0; pos+skip<=s.size(); skip++)
            if(match(w.substr(pos+1), s.substr(pos+skip)))
                return true;
    
    return false;
}

// using memoization
int cache[101][101];
string W, S;
bool matchMemoized(int w, int s)
{
    int& ret = cache[w][s];
    if(ret != -1) return ret;

    while(s<S.size() && w<W.size() && 
            (W[w] == '?' || W[w] == S[s]))
    {
        w++; s++;
    }
    
    if(w == W.size()) return ret = (s == S.size());

    if(W[w] == '*')
        for(int skip=0; skip+s<=S.size(); skip++)
            if(matchMemoized(w+1, s+skip))
                return ret =1;

    return ret=0;
}

int main()
{
    cout << "ret_1: ";
    for(int i=0; i<wArr.size(); i++)
    {
        if(match(w, wArr[i]))
             cout << wArr[i] << ' ';
    }
    cout << "\nret_2: ";
    // using memoization
    memset(cache, -1, sizeof(cache));
    W = w;
    for(int i=0; i<wArr.size(); i++)
    {
        S = wArr[i];
        if(matchMemoized(0, 0))
             cout << S << ' ';
    }
    
    return 0;
}