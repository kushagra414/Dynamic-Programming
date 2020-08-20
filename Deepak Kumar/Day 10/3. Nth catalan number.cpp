#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int  n;
	    cin>>n;
	    cpp_int dp[n+1];
	    dp[0]=1;
	    dp[1]=1;
	    for(int i=2;i<=n;i++){
	        dp[i]=0;
	        for(int j=0;j<i;j++){
	            dp[i] = dp[i] + dp[j]*dp[i-j-1];
	        }
	    }
	    cout<<dp[n]<<endl;
	}
	return 0;
}
