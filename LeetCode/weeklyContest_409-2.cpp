/*3243. Shortest Distance After Road Addition Queries I*/
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ret;
        list<int> L(n);
        int maxPath = n-1;
        for(int i=0; i<queries.size(); i++)
        {
            // if the path that from 0 to n-1 linked, continuously return 1
            if(queries[i][0] == 0 && queries[i][1] == n-1)
            {
                for(int a=i;a<queries.size(); a++)
                    ret.push_back(1);
                break;
            }
            else
            {
                maxPath -= ((queries[i][1]+1) - (queries[i][0]+1) - 1);
                ret.push_back(maxPath);
            }
        }


        return ret;
    }
};

=============================================================================
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> to(n);

        // calculate each path
        for(auto& q: queries)
        {
            // store from point to point
            to[q[0]].push_back(q[1]);
            vector<int> dp(n, n);
            // start is 0
            dp[0]=0;

            for(int i=0; i+1<n; i++)
            {
                // find minimun value of current value
                dp[i+1] = min(dp[i+1], dp[i]+1);
                // if loop meet jump path, find minimun value again.
                for(int j : to[i])
                    dp[j] = min(dp[j], dp[i]+1);
            }
            ans.push_back(dp.back());
        }
        
        return ans;
    }
};