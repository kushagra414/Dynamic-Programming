class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i,j;
        for(i=0,j=0;i<t.length() and j<s.length();i++){
            if(s[j]==t[i]){
                j++;
            }
        }
        if(j==s.length())
            return true;
        return false;
    }
};