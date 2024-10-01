class Solution {
public:
    int romanToInt(string s) {
        int ret=0;
        
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000} };
        
        for(int i=0; i<s.length(); i++)
        {
            if(roman[s[i]] < roman[s[i+1]])
                ret-=roman[s[i]];
            else
                ret+=roman[s[i]];
        }

        return ret;
    }
};

/*
class Solution {
public:
    int romanToInt(string s) {
        int ret=0;

        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i]=='I')
            {
                if(s[i+1] == 'V' || s[i+1] == 'X')
                    ret-=1;
                else
                    ret+=1;
            }
            else if(s[i]=='V')
                ret+=5;
            else if(s[i]=='X')
            {
                if(s[i+1] == 'L' || s[i+1] == 'C')
                    ret-=10;
                else
                    ret+=10;
            }
            else if(s[i]=='L')
                ret+=50;
            else if(s[i]=='C')
            {
                if(s[i+1] == 'D' || s[i+1] == 'M')
                    ret-=100;
                else
                    ret+=100;
            }
            else if(s[i]=='D')
                ret+=500;
            else if(s[i]=='M')
                ret+=1000;
        }
        return ret;
    }
};
*/
