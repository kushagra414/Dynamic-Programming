class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        unsigned long maxLen=0;
        vector<int> bitVector(n,0);
        for(int i=0;i<n;i++){
            for(auto letter: words[i]){
                bitVector[i] |= 1<<(letter-'a');
            }
        }
        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)
                if((bitVector[i] & bitVector[j]) == 0)
                    maxLen = max(maxLen,
                                 words[i].length()*words[j].length());
        return maxLen;
    }
};