#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll findMinJumps(ll arr[],ll n, ll index,ll minJumps[]);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    ll n;
	    cin>>n;
	    ll arr[n];
	    for(ll i=0;i<n;i++)
	        cin>>arr[i];
	    ll minJumps[n];
	    memset(minJumps,-1,sizeof(minJumps));
	    findMinJumps(arr,n,0,minJumps);
	    if(minJumps[0]>=INT_MAX)
	        cout<<"-1"<<endl;
	    else
	        cout<<minJumps[0]<<endl;
	}
	return 0;
}

ll findMinJumps(ll arr[],ll n, ll i, ll minJumps[]){
    if(arr[i]==0)
        return INT_MAX;
    if(i>=n-1)
        return 0;
    if(minJumps[i]!=-1)
        return minJumps[i];
    
    ll minEle=INT_MAX;
    for(int start = 1;start<=arr[i];start++){
        ll jumps = findMinJumps(arr,n,i+start,minJumps);
        if(jumps<INT_MAX)
            jumps++;
        minEle = min(minEle,jumps);
        if(jumps==1)
            break;
    }    
    return (minJumps[i] = minEle);
}