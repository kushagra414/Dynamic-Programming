#include<bits/stdc++.h>
using namespace std;

int MooreAlgo(int arr[],int n);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    cout<<MooreAlgo(arr,n)<<endl;
	}
	return 0;
}

int MooreAlgo(int arr[],int n){
    int count=1,majorityEle=arr[0],countMaj=0;
    for(int i=1;i<n;i++){
        if(arr[i]==majorityEle)
            count++;
        else{
            count--;
            if(count==0){
                majorityEle = arr[i];
                count++;
            }
        }
    }
    for(int i=0;i<n;i++)
        if(arr[i]==majorityEle)
            countMaj++;
    if(countMaj>n/2)
        return majorityEle;
    return -1;
}