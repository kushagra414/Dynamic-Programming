class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> Ones;
        int count=0,x;
        Ones.push_back(0);
        for(int i=1;i<=num;i++){
            x = i;
            count=0;
            while(x){
                x = x & (x-1);
                count++;
            }
            Ones.push_back(count);
        }
        return Ones;
    }
};