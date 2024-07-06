#include <iostream>

using namespace std;
int retMax = -1;

int calcMaxRect(int height[], int idx)
{
    cout << "idx: " << idx << "height: " << height[idx] << endl;
    if(idx == 0) return retMax = height[idx];

    int ret = 0;
    if(height[idx-1] < height[idx])
        ret = max(retMax, calcMaxRect(height, idx+1));
    else
        ret = max(retMax, calcMaxRect(height, idx-1));

    return ret;
}

int main()
{
    int height[7] = {7, 1, 5, 9, 6, 7, 3};
    
    cout << "ret: " << calcMaxRect(height, 1) << endl;
    return 0;
}