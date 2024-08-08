#include <iostream>
#include <vector>

using namespace std;

int turnSafe(vector<string>& strList)
{
    int n=strList.size();
    int ret=0;
    for(int i=0; i+1<n; i++)
    {
        do
        {
            if(strList[i] == strList[i+1])
            {
                break;
            }
            else
            {
                ret++;
                strList[i].push_back(strList[i][0]);
                strList[i].erase(0,1);
            }
        } while(strList[i] != strList[i+1]);
    }
    return ret;
}

int main()
{
    vector<string> strList = {"abbab", "babab", "ababb", "bbaba"};

    cout << "ret: " << turnSafe(strList);

    return 0;
}