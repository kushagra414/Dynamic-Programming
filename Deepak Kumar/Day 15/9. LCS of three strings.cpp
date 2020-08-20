#include <bits/stdc++.h>
using namespace std;
int dp[101][101][101];

int solution(string& s1,int len1,string& s2,int len2,string& s3,int len3){
    if(len1<=0||len2<=0||len3<=0){
        return 0;
    }
    else if(dp[len1][len2][len3]!=-1){
        return dp[len1][len2][len3];
    }
    else if(s1[len1-1]==s2[len2-1] && s1[len1-1]==s3[len3-1]){
        return 1+solution(s1,len1-1,s2,len2-1,s3,len3-1);
    }
    else if(s1[len1-1]!=s2[len2-1] && s1[len1-1]==s3[len3-1]){
        return dp[len1][len2][len3]=max(solution(s1,len1,s2,len2-1,s3,len3),solution(s1,len1-1,s2,len2,s3,len3-1));
    }
    else if(s1[len1-1]!=s3[len3-1] && s1[len1-1]==s2[len2-1]){
        return dp[len1][len2][len3]=max(solution(s1,len1,s2,len2,s3,len3-1),solution(s1,len1-1,s2,len2-1,s3,len3));
    }
    else if(s2[len2-1]!=s3[len3-1] && s1[len1-1]==s2[len2-1]){
        return dp[len1][len2][len3]=max(solution(s1,len1-1,s2,len2,s3,len3),solution(s1,len1-1,s2,len2-1,s3,len3));
    }
    else{
        return dp[len1][len2][len3]=max({solution(s1,len1,s2,len2-1,s3,len3),solution(s1,len1,s2,len2,s3,len3-1),solution(s1,len1-1,s2,len2,s3,len3)});
    }
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int len1,len2,len3;
	    cin>>len1>>len2>>len3;
	    string str1,str2,str3;
	    cin>>str1>>str2>>str3;
	    memset(dp,-1,sizeof(dp));
	    cout<<solution(str1,len1,str2,len2,str3,len3)<<endl;
	}
	return 0;
}
