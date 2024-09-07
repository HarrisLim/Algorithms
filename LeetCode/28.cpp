class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size())
            return -1;
        int n = haystack.size() - needle.size();
        int needleSize = needle.size();
        int ret = 0;
        
        for(int i=0; i<n+1; i++)
            
            if( haystack.substr(i, needle.size()) == needle )
                return i;
            else
                ret = -1;
            
        return ret;
    }
};
