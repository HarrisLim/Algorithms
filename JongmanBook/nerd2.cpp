#include <iostream>
#include <vector>
#include <map>

using namespace std;

// stores the points that's not dominated.
map<int, int> coords;
// new point(x, y) check if other points are dominated or not.
bool isDominated(int x, int y)
{
    // find the far left point between the point is situated further to the right than x
    map<int, int>::iterator it = coords.lower_bound(x);
    // if that would have no points between of them, not dominated.
    if(it == coords.end()) return false;
    // it->second is the value of map.
    // this value is situated the highest point of right side point than x
    // if (x, y) is dominated by some point, it should be dominated by it->second
    return y < it->second;
}

// remove point on tree dominated by new point(x, y)
void removeDominated(int x, int y)
{
    cout << " x:" << x << " y:"<<y << " " << endl;
    map<int, int>::iterator it = coords.lower_bound(x);
    // there is no point further to the left than (x, y)
    cout << " here_0:" <<it->second; 
    if(it == coords.begin()) return;
    it--;
    while(true)
    {
        cout << " here_1:" <<it->second; 
        // find the point adjacent to (x, y)
        // if the point that it indicate is not dominated, break.
        if(it->second > y) break;
        // remove it and break because of no point previously
        if(it == coords.begin())
        {
            cout << " first" << endl;
            coords.erase(it);
            break;
        }
        // move it to the previous point and remove it
        else
        {
            cout << " second" << endl;
            map<int, int>::iterator jt = it;
            --jt;
            coords.erase(it);
            it = jt;
        }
    }
}

// when new point(x, y) added, update coords and calculate the number of points are not dominated
int registered(int x, int y)
{
    // in case of (x, y) is already dominated, throw away
    if(isDominated(x, y)) return coords.size();
    // remove the points is dominated by (x, y) among the existing points.
    removeDominated(x, y);
    coords[x] = y;
    return coords.size();
}

int main()
{
    vector<vector<int>> arr = { {72, 50},
                                {57, 67},
                                {74, 55},
                                {64, 60} };
    
    
    for(const auto& x : arr)
    {
         registered(x[0], x[1]);
    }

    return 0;
}