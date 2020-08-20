class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr=nums;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for(int k = i; k <= j; k++){
            sum = sum + arr[k];
        }
        return sum;
    }
};
