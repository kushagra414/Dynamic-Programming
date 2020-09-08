class Solution {
public:
    char findTheDifference(string s, string t) {
        int Xor=0,lenS=s.length(),i=0;
        for(i=0;i<lenS;i++){
            Xor = Xor ^ s[i] ^ t[i];
        }
        return Xor ^ t[i];
    }
};