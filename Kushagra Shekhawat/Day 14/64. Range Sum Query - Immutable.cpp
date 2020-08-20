class NumArray {
public:
    int *sumArray;
    NumArray(vector<int>& nums) {
        sumArray = new int[nums.size()];
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            sumArray[i] = sum;
        }
    }
    
    int sumRange(int i, int j) {
        i--;
        if(i>=0){
            return sumArray[j]-sumArray[i];
        }
        return sumArray[j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */