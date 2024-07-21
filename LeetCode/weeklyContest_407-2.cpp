/* 100335. Vowels Game in a String */
class Solution {
public:
    bool doesAliceWin(string s) {
        // base case
        if(s.size() == 0) return 0;

        if()
    }
};

/* this is the code from almost leetcoder */
bool doesAliceWin(string s) {
    // store vowel
    string v = "aeiou";
    // if the string has at least one vowel, Alice win.
    // because, always Alice has a first turn and pick odd numbers
    // then, Bob has to pick even number of vowel. but Alice left just one vowel
    // so Bob has no vowel to pick :(
    for(char c: s)
        for(char t : v)
            if(t==c) return true;
    
    return false;
}