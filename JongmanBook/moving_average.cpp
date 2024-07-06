#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> A = {90, 80, 75, 73, 70, 68, 64, 60, 65, 70, 71, 70};
    vector<double> MA;
    double sum =0;

    // Jongman
    for(int i=3-1; i<12; i++)
    {
        double partialSum =0;
        for(int j=0; j<3; j++)
        {
            partialSum += A[i-j];
        }
        MA.push_back(partialSum / 3);
        
    }

    for_each(MA.begin(), MA.end(), [&](double& n)
    {
        cout << "result: "<< n << " ";
    });

    // me
    // for(int i=0; i<10; i++)
    // {
    //     sum = 0;
    //     for(int j=i; j<(i+3); j++)
    //     {
    //         sum+=A.at(j);
    //         cout << "A.at(j): "<< A.at(j);
    //     }
    //     sum = sum/3;

    //     cout << "SUM: " << sum << "\n";
    //     MA.push_back(sum);
    // }
    // for_each(MA.begin(), MA.end(), [&](double& n)
    // {
    //     cout << "result: "<< n << ", ";
    // });
    
    return 0;
    
}