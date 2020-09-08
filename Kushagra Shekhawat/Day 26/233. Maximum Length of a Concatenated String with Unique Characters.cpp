class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        int maxLen = 0;
        for(string s: arr){
            bitset<26> bitRep;
            for(char c: s)
                bitRep.set(c-'a');
            int n = bitRep.count();
            if(n != s.length())
                continue;
            //The string has repeated chars
            for(int i = 0;i<dp.size();i++){
                bitset<26> bitRepDp = dp[i];
                if((bitRep & bitRepDp).any())
                    continue;
                dp.push_back(bitRepDp | bitRep);
                maxLen = max(maxLen,(int)bitRepDp.count()+n);
            }
        }
        return maxLen;
    }
};