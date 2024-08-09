#include <iostream>
#include <string>
#include <vector>

using namespace std;

// find which suffix stand on first position
struct SuffixComparator
{
    const string& s;
    SuffixComparator(const string& s) : s(s) {}
    bool operator () (int i, int j)
    {
        return strcmp(s.c_str() + i, s.c_str() + j) < 0;
    }
};

// calculate suffix of s
vector<int> getSuffixArrayNaive(const string& s)
{
    // make an array containing start position of suffix
    vector<int> perm;
    for(int i=0; i<s.size(); i++)
        perm.push_back(i);
    // sort with SuffixCompartor
    sort(perm.begin(), perm.end(), SuffixComparator(s));
    return perm;
}

// when the group numbers give you by based on first t word of each suffix,
// compare given two suffix based on first 2t word
// group[] include suffix that length 0
struct Comparator 
{
    const vector<int>& group;
    int t;
    Comparator(const vector<int>& _group, int _t): group(_group), t(_t)
    {
        group = _group; t = _t;
    }

    bool operator () (int a, int b)
    {
        // if the first t word is different, compare with using group
        if(group[a] != group[b]) return group[a] < group[b];
        // otherwise, compare S[a+t..] with S[b+t..]
        return group[a+t] < group[b+t];
    }   
};

vector<int> getSuffixArray(const string& s)
{
    int n = s.size();
    int t=1;
    vector<int> group(n+1);
    for(int i=0; i<n; i++) group[i] = s[i];
    group[n] = -1;

    vector<int> perm(n);
    for(int i=0; i<n; i++) perm[i] = i;
    while(t<n)
    {
        Comparator compareUsing2T(group, t);
        sort(perm.begin(), perm.end(), compareUsing2T);

        t*=2;
        if(t>=n) break;

        vector<int> newGroup(n+1);
        newGroup[n] = -1;
        newGroup[perm[0]] = 0;
        for(int i=1; i<n; i++)
            if(compareUsing2T(perm[i-1], perm[i]))
                newGroup[perm[i]] = newGroup[perm[i-1]]+1;
            else
                newGroup[perm[i]] = newGroup[perm[i-1]];
        group = newGroup;
    }
    return perm;
}

int main()
{

    return 0;
}