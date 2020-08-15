#include<bits/stdc++.h>
using namespace std;

int CountStrings(int len,int Bs,int Cs,int dp[][2][3]);

int main()
 {
    long long int strings[1001];
    strings[0] = 0;
    strings[1] = 3;
    strings[2] = 4;
    int max = 3;
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int dp[N+1][2][3];
	    memset(dp,-1,sizeof(dp));
	    cout<<CountStrings(N,0,0,dp)<<endl;
	}
	return 0;
}

int CountStrings(int len,int Bs,int Cs,int dp[][2][3]){
    if(len==0){
        return 1;
    }
    if(dp[len][Bs][Cs]!=-1)
        return dp[len][Bs][Cs];
        
    int a=0,b=0,c=0;
    a = CountStrings(len-1,Bs,Cs,dp);
    if(Bs<1)
        b = CountStrings(len-1,Bs+1,Cs,dp);
    if(Cs<2)
        c = CountStrings(len-1,Bs,Cs+1,dp);
    return (dp[len][Bs][Cs] = a+b+c);
        
}