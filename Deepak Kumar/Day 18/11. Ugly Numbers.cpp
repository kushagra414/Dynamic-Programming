#include <iostream>
using namespace std;
#define ll long long
ll dp[10001];

ll min(ll a,ll b,ll c){
    ll minimum=a<b?a:b;
    return minimum<c?minimum:c;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    dp[0]=1;
	    ll index2=0,index3=0,index5=0;
	    ll value2=2;
	    ll value3=3;
	    ll value5=5;
	    for(int i=1;i<N;i++){
	        ll minimum=min(value2,value3,value5);
	        dp[i]=minimum;
	        if(value2==minimum){
	            index2++;
	            value2=2*dp[index2];
	        }
	        if(value3==minimum){
	            index3++;
	            value3=3*dp[index3];
	        }
	        if(value5==minimum){
	            index5++;
	            value5=5*dp[index5];
	        }
	    }
	    cout<<dp[N-1]<<endl;
	}
	return 0;
}
