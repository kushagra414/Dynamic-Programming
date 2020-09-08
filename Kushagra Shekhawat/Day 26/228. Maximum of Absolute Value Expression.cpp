class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<int> sum1(n,0);
        vector<int> sum2 = sum1,diff1 = sum1,diff2 = sum1;
        for(int i=0;i<n;i++){
            sum1[i] = arr1[i] + arr2[i] + i;
            sum2[i] = arr1[i] + arr2[i] - i;
            diff1[i] = arr1[i] - arr2[i] +i;
            diff2[i] = arr1[i] - arr2[i] - i;
        }
        return 
            max(max(fmd(sum1),fmd(sum2)),max(fmd(diff1),fmd(diff2)));
    }
    //FindMaxDiff
    int fmd(vector<int> arr){
        int n = arr.size();
        int Min = INT_MAX,Max = INT_MIN;
        for(int i=0;i<n;i++){
            Max = max(arr[i],Max);
            Min = min(arr[i],Min);
        }
        return (Max-Min);
    }
};