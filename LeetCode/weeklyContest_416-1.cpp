class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> S(bannedWords.begin(), bannedWords.end());

        int cnt=0;
        for(int i=0; i<message.size(); i++)
            if(S.find(message[i]) != S.end())
                if(++cnt >= 2)
                    return true;
                    
        return false;
    }
};
