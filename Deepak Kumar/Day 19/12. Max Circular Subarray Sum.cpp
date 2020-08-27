#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solution(ll A[],ll N){
    ll max_sum=INT_MIN;
    ll curr_max_sum=0;
    for(ll i=0;i<N;i++){
        curr_max_sum+=A[i];
        max_sum=max(max_sum,curr_max_sum);
        if(curr_max_sum<0){
            curr_max_sum=0;
        }
    }
    if(max_sum<0){
        return max_sum;
    }
    
    ll total_sum=0;
    for(int i=0;i<N;i++){
        total_sum+=A[i];
    }
    
    ll min_sum=INT_MAX;
    ll curr_min_sum=0;
    for(ll i=0;i<N;i++){
        curr_min_sum+=A[i];
        min_sum=min(min_sum,curr_min_sum);
        if(curr_min_sum>0){
            curr_min_sum=0;
        }
    }
    return max(max_sum,total_sum-min_sum);
}

int main(){
	int T;
	cin>>T;
	while(T--){
	    ll N;
	    cin>>N;
	    ll A[N];
	    for(ll i=0;i<N;i++){
	        cin>>A[i];
	    }
	    cout<<solution(A,N)<<endl;
	}
	return 0;
}
