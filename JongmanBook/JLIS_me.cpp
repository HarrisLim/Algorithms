#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// test case 1
// vector<int> n = {1, 2, 4};
// vector<int> m = {3, 4, 7};
// test case 2
// vector<int> n = {1, 2, 3};
// vector<int> m = {4, 5, 6};
// test case 3
vector<int> n = {10, 20, 30, 1, 2};
vector<int> m = {10, 20, 30};

int count(const unordered_set<int>& set)
{
    int ret =0;
    for (const auto& elem: set)
    {
        cout << elem << ' ';
        ret++;
    }
    cout << '\n';
    return ret;
}
int main()
{
    for(int i=0; i<m.size(); i++)
        n.push_back(m[i]);

    unordered_set<int> numSet(n.begin(), n.end());

    cout << "ret: " << count(numSet);

    return 0;
}