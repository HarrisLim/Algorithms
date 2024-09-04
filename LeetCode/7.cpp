class Solution {
public:
    int reverse(int x) {

        int ret=0;
        do{
            int digit = x % 10;

            if((ret > INT_MAX/10) || (ret < INT_MIN / 10))
                return 0;
            
            ret = ret * 10 + digit;
        } while(x/=10);

        return ret;
    }

    // The first approach
    int reverse_first(int x) {
        int ret=0;
        do{
            string str = to_string(abs(x));
            int len = str.size();
            string zero="1";
            for(int i=0; i<len-1; i++)
                zero.append("0");

            int z = stoi(zero);
            ret += (x % 10) * z;
            
        } while(x/=10);

        return ret;
    }
};
