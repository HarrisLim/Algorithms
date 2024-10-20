class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ret;
        string temp="";
        string toStr = "";
        string lastPrefix="";
        for(int i=0; i<target.length(); i++)
        {
            char ch = 96; // a:97
            while(target[i] > ch)
            {
                ch++;
                toStr = string(1, ch);
                lastPrefix = temp+toStr;
                ret.push_back(lastPrefix);
            }
            temp = lastPrefix;
        }
        return ret;
    }
};
