class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int ret=0;
        for(int x=0; x<word.size(); x++)
        {
            int a=0, e=0, i=0, o=0, u=0, c=0;
            for(int j=x; j<word.size(); j++)
            {
                if(word[j] == 'a') a++;
                else if(word[j] == 'e') e++;
                else if(word[j] == 'i') i++;
                else if(word[j] == 'o') o++;
                else if(word[j] == 'u') u++;
                else c++;

                if(a && e && i && o && u && c==k) ret++;
            }
        }
        return ret;
    }
};
