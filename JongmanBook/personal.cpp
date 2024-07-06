#include <iostream>

using namespace std;

int main()
{
    string KindOfMonth[] = {"Jan", "Feb", "Mar", "Apr",
                           "May", "Jun", "Jul", "Aug",
                            "Sep", "Oct", "Nov", "Dec"};
    for(int a=0; a<12; a++)
    {   
        cout << KindOfMonth[a]+"\n";
    }

    return 0;
}