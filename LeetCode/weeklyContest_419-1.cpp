class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        map<int, int> mp;
        vector<int> ret;

        for(int i=0; i<=nums.size()-k; i++)
        {
            int sum=0;
            int cnt=0;
            mp.clear();
            
            for(int j=i; j<k+i; j++)
                mp[nums[j]]++;

            vector<pair<int, int>> temp;
            for(auto m : mp)
                temp.push_back({m.second, m.first});
                
            sort(temp.begin(), temp.end());

            for(int i=temp.size()-1; i>=0; i--)
            {
                if(cnt >= x) 
                    break;
                
                sum += temp[i].first * temp[i].second;
                cnt++;
            }

            ret.push_back(sum);
        }
        return ret;
    }
};
