class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // a = 97. so a - 97 = 0
        int r[26], m[26];
        for(int i=0; i<ransomNote.size(); i++)
            r[ransomNote[i] - 97]++;

        for(int i=0; i<magazine.size(); i++)
            m[magazine[i] - 97]++;

        // there are 26 letters in the alphabet.
        for(int i=0; i<26; i++)
            if(r[i] > m[i]) 
                return false;
        
        return true;
    }
};
