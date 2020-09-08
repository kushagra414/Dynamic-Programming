class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0 or n == INT_MIN or (n & (n-1)))
            return false;
        else if((n-1) % 3 == 0)
            return true;
        return false;
    }
};