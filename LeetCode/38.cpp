class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        
        for(int i=0; i<n-1; i++)
        {
            string str = "";
            char prevChar = ret[0];
            int count=1;

            for(int j=1; j<ret.length(); j++)
            {
                if(ret[j] == prevChar)
                {
                    count++;
                }
                else
                {
                    str += to_string(count) + prevChar;
                    prevChar = ret[j];
                    count=1;
                }
            }
            str += to_string(count) + prevChar;
            ret = str;

        }

        return ret;
    }
};
