#include<bits/stdc++.h>
using namespace std;

int ModifiedKadane(int arr[],int n);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cout<<ModifiedKadane(arr,n)<<endl;
	}
	return 0;
}


int ModifiedKadane(int arr[],int n){
    int maxSum=INT_MIN,minSum=INT_MAX,arrSum=0;
    int tempMaxSum=0,tempMinSum=0;
    for(int i=0;i<n;i++){
        tempMaxSum = max(tempMaxSum+arr[i],arr[i]);
        maxSum = max(tempMaxSum,maxSum);
        //Above two lines are simply kadanes algo
        //Below two lines are for calculating minimum subArray
        tempMinSum = min(tempMinSum+arr[i],arr[i]);
        minSum = min(tempMinSum,minSum);
        arrSum+=arr[i];
    }
    //if the whole array is neg no's then arrSum will be equal to minSum
    if(arrSum==minSum)
        return maxSum;
    else
        return max(maxSum,arrSum-minSum);
}