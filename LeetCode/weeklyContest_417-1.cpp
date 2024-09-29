class Solution {
public:
    char kthCharacter(int k) {
        vector<char> word(1, 'a');
        
        while(word.size()<=k)
        {
            int n = word.size();
            for(int i=0; i<n; i++)
                word.push_back(word[i]+1);
        }
        return word[k-1];
    }
};
