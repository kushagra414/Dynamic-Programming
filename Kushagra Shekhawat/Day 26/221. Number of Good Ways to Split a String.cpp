class Solution {
public:
    int numSplits(string s) {
        int goodSplit=0;
        int s2[26] = {0};
        int bitVectorS1=0,bitVectorS2=0;
         for(int i=0;i<s.length();i++){
            s2[s[i]-'a']++;
            bitVectorS2 |= 1<<(s[i]-'a');
         }
        for(int i=0;i<s.length();i++){
            bitVectorS1 |= 1<<(s[i]-'a');
            s2[s[i]-'a']--;
            if(s2[s[i]-'a'] == 0)
                bitVectorS2 &= ~(1<<(s[i]-'a'));
            if(__builtin_popcount(bitVectorS1) == 
               __builtin_popcount(bitVectorS2))
                goodSplit++;
        }
        return goodSplit;
    }
};