class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int f1 = coordinate1[0], f2 = coordinate2[0];
        int s1 = coordinate1[1], s2 = coordinate2[1];
        if( (f1 % 2 == f2 % 2 && s1 % 2 == s2 % 2) ||
            (f1 % 2 != f2 % 2 && s1 % 2 != s2 % 2) )
            return true;
        else
            return false;
    }
};
