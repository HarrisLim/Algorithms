#include <iostream>
#include <string>

using namespace std;

string member = "MFMFMFFFMMMFMF";
string fan = "MMFFFFFMFFFMFFFFFFMFFFMFFFFMFMMFFFFFFF";

int cnt = 0;

void solve(int idx)
{
    int memSize = member.size();
    bool isCount = false;
    
    for(int i=0; i<memSize; i++)
    {
        if((member[i] == 'M' && fan[idx+i] == 'M') || fan[idx+i] == '\0')
            return;
        else
            isCount = true;
    }
    if(isCount) cnt++;
}

int main()
{
    for(int i=0; i<(fan.size()-member.size())+1; i++)
        solve(i);

    cout << "cnt: " << cnt << endl;

    return 0;
}

