#include <iostream>
#include <string>

using namespace std;
const int INF = 987654321;
string N = "11111222";

// a: starting index, b: ending index
int classify(int a, int b)
{
    // finding the number processing
    string M = N.substr(a, b-a);

    // if the number of group consist of the same number, difficulty 1
    if(M == string(M.size(), M[0])) return 1;

    // examine arithmetic progression
    bool progressive = true;
    for(int i=0; i<M.size()-1; i++)
        if(M[i+1] - M[i] != M[1] - M[0])
            progressive = false;

    // arithmetic progrssion and the gap 1 or 2, then difficulty 2
    if(progressive && abs(M[1] - M[0]) == 1)
        return 2;

    // check it consist of the same two numbers
    bool alternating = true;
    for(int i=0; i<M.size(); i++)
        if(M[i] != M[i%2])
            alternating = false;

    if(alternating) return 4; // check it consist of the same two numbers, then difficulty 4
    if(progressive) return 5; // arithmetic progrssion, difficulty 5

    return 10; // difficulty 10 except for other options
}

int cache[10002];
int memorize(int begin)
{
    // base case
    if(begin == N.size()) return 0;

    // memoization
    int& ret = cache[begin];
    if(ret != -1) return ret;

    ret = INF;
    for(int L=3; L<=5; L++)
        if(begin + L <= N.size())
            ret = min(ret, memorize(begin+L) + classify(begin, begin+L));
    
    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    cout << "ret: " << memorize(0);
    
    return 0;
}