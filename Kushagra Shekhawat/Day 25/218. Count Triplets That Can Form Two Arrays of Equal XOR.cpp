class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int zero = 0,equal=0,count=0,temp;
        for(int i=1;i<arr.size();i++){
            zero = 0;
            zero ^= arr[i];
            for(int j=i-1;j>=0;j--){
                zero ^= arr[j];
                if(zero == 0){
                    temp = zero;
                    equal = 0;
                    for(int k = j;k<i;k++){
                        equal ^= arr[k];
                        temp ^= arr[k];
                        if(equal == temp){
                            count++;
                        }
                    }    
                }
            }
        }
        return count;
    }
};