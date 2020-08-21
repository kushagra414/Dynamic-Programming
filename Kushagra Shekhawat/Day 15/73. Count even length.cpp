#include<bits/stdc++.h>
using namespace std;
int main()
 {
    long long int nCr[1001];
    nCr[0] = 1;
	int T;
	cin>>T;
	while(T--){
	    long long int N,res=1;
	    long long int mod = pow(10,9)+7;
	    cin>>N;
	    for(long long int i=1;i<N;i++){
	        nCr[i] = (((nCr[i-1]*(N+1-i)))/i)%mod;
	        res = (res+(nCr[i]*nCr[i]))%mod;
	    }
	    cout<<res<<endl;
	}
	return 0;
}