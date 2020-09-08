#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int n,xor_=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    for(int i=0;i<n;i++)
	        xor_ = arr[i]^xor_;
	    cout<<xor_<<endl;
	}
	return 0;
}