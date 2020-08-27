#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long 

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str;
	    cin>>str;
	    int N=str.length();
	    ull sum=0;
	    ull dp[N];
	    dp[0]=str[0]-'0';
	    sum=dp[0];
	    for(int i=1;i<N;i++){
	        dp[i]=(i+1)*(str[i]-'0')+10*dp[i-1];
	        sum+=dp[i];
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
