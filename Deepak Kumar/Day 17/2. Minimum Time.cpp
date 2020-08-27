#include <bits/stdc++.h>
using namespace std;
int dp[101];

int solution(int num,int ins,int del,int copy){
    if(num==0){
        return 0;
    }
    if(num==1){
        return ins;
    }
    if(dp[num]!=-1){
        return dp[num];
    }
    else{
        if(num%2==1){
            return dp[num]=min(ins+solution(num-1,ins,del,copy),del+copy+solution((num+1)/2,ins,del,copy));
        }
        return dp[num]=min(ins+solution(num-1,ins,del,copy),copy+solution(num/2,ins,del,copy));
    }
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int num;
	    cin>>num;
	    int ins,del,copy;
	    cin>>ins>>del>>copy;
	    memset(dp,-1,sizeof(dp));
	    cout<<solution(num,ins,del,copy)<<endl;
	}
	return 0;
}
