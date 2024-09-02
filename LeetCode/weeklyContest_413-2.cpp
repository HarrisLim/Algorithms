class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> ret;
        priority_queue<int> pq;

        for(auto v : queries)
        {   
            int temp = abs(v[0])+abs(v[1]);
            if(pq.size() < k)
            {
                pq.push(temp);
                ret.push_back(pq.size()<k?-1:pq.top());
                continue;
            }
            
            if(temp < pq.top())
            {
                pq.pop();
                pq.push(temp);
            }

            ret.push_back(pq.top());
        }
        return ret;
    }
};

