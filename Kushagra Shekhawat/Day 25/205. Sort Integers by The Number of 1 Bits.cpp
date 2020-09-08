class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](int num1,int num2){
                    int onesNum1 = __builtin_popcount(num1), onesNum2 =             
                                                                __builtin_popcount(num2);
        if(onesNum1<onesNum2)
            return true;
        else if(onesNum1>onesNum2)
            return false;
        else
            return num1<num2;
        });
        return arr;
    }
};