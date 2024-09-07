class Solution {
public:
    int myAtoi(string s) {
        long ret=0;
        int sign=1;
        int flag = true;

        for(int i=0; i<s.size(); i++)
        {
            if(flag && s[i] == ' ')
                continue;

            if( isdigit(s[i]) )
            {
                flag = false;
                ret = ret*10+(s[i]-'0');

                if(ret>INT_MAX && sign==-1)
                    return INT_MIN;
                else if(ret>INT_MAX && sign==1)
                    return INT_MAX;
            }
            else if (flag && s[i] == '-')
            {
                flag = false;
                sign = -1;
            }
            else if (flag && s[i] == '+')
            {
                flag = false;
                sign = 1;
            }
            else
                break;
        }

        return ret*sign;
    }
};
