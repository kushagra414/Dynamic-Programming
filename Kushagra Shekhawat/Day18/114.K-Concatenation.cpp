class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long maxSum,arraySum = accumulate(arr.begin(),arr.end(),0);
        maxSum = kadaneAlgo(arr,arr.size(),2);
        return (maxSum + (arraySum>0?(k-2)*arraySum:0))%1000000007;
    }
    long long kadaneAlgo(vector<int>& arr,int n,int k){
        long long sum=0,maxSum=0;
        for(int i=0;i<n*k;i++){
            sum = max((long long)arr[i%n],arr[i%n]+sum);
            maxSum = max(sum,maxSum);
        }
        return maxSum;
    }
};