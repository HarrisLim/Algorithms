class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string ret="";
        unordered_map<string, int> mp;
        vector<string> vec;

        for(int i=0; i<arr.size(); i++)
            mp[arr[i]]++;
        
        for(auto it = mp.begin(); it != mp.end();)
        {
            if(it->second >= 2)
                it = mp.erase(it);
            else
                 it++;
        }
            
        if(mp.size() < k)
            return "";
            
        for(int i=0; i<arr.size(); i++)
        {
            if(mp.find(arr[i]) != mp.end())
            {
                k--;
                if(k==0)
                    return arr[i];
            }   
        }

        return ret;
    }
};
