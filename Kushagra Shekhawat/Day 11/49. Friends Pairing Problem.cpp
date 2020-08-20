#include<bits/stdc++.h>
using namespace std;
int main()
 {
    long long int friends[101];
    int max=3;
    friends[0]=0;friends[1]=1;friends[2]=2;
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int mod = 1000000007;
	    for(int i=max;i<=N;i++){
	        friends[i] = (friends[i-1]+((i-1)*friends[i-2])%mod)%mod;
	    }
	    max=max>N?max:N;
	    cout<<friends[N]<<endl;
	}
	return 0;
}