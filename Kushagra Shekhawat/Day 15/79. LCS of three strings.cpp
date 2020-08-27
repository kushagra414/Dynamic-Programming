#include<bits/stdc++.h>
using namespace std;

int findLCS(string s1,string s2,string s3);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,M,L;
	    string s1,s2,s3;
	    cin>>N>>M>>L;
	    cin>>s1>>s2>>s3;
	    cout<<findLCS(s1,s2,s3)<<endl;
	}
	return 0;
}

int findLCS(string s1,string s2,string s3){
    int len1 = s1.length()+1,len2 = s2.length()+1;
    int len3 = s3.length()+1;
    int LCS[len1][len2][len3];
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            for(int k=0;k<len3;k++){
                if(i==0 or j==0 or k==0)
                    LCS[i][j][k]=0;
                else if(s1[i-1]==s2[j-1] and s2[j-1]==s3[k-1]){
                    LCS[i][j][k] = LCS[i-1][j-1][k-1]+1;
                }else{
                    LCS[i][j][k] = max(LCS[i-1][j][k],
                    max(LCS[i][j-1][k],LCS[i][j][k-1]));
                }
            }
        }
    }
    return LCS[len1-1][len2-1][len3-1];
}