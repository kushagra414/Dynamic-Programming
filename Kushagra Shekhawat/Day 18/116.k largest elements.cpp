#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    priority_queue<int>pq;
	    for(int i=0;i<n;i++)
	        pq.push(arr[i]);
	    while(k--){
	        cout<<pq.top()<<" ";
	        pq.pop();
	    }
	    cout<<endl;
	}
	return 0;
}