class Solution {
public:
    int longestAwesome(string s) {
        int n = s.length(),LongestSubs = 1;
        vector<int> DP(1024,n);  //2^10 = 1024 total number of combination
        //this question is similar to max subarray with sum 0, when done in O(n).
        //Using hashing to store the index of the mask and checking if we have found the mask before.
        //If so then it means that XOR of all the inbetween numbers is zero which means the numbers have appeared even times.
        //We also check if the we have found the same XOR with one bit difference as palindrome can be odd.
        DP[0] = -1;
        int bitVector = 0;
        for(int i=0;i<n;i++){
            bitVector ^= 1<<(s[i]-'0');
            LongestSubs = max(LongestSubs,i - DP[bitVector]);
            //Check for 1 bit differnce
            for(int j = 0;j<10;j++)
                LongestSubs = max(LongestSubs, i - DP[bitVector ^ 1<<(j)]);
            
            //Store the left most index found for the mas;
            DP[bitVector] = min(i,DP[bitVector]);
        }
        return LongestSubs;
    }
};