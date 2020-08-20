class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> Ones;
        for(int i=0;i<=num;i++){
            Ones.push_back(__builtin_popcount(i));  //Used to count number of ones in 
                                                    //binary representation
        }
        return Ones;
    }
};