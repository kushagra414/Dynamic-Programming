#include<bits/stdc++.h>
using namespace std;

int findLCS(string s1,string s2);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,M;
	    string s1,s2;
	    cin>>N>>M;
	    cin>>s1>>s2;
	    cout<<findLCS(s1,s2)<<endl;
	}
	return 0;
}

int findLCS(string s1,string s2){
    int len1 = s1.length()+1,len2 = s2.length()+1;
    int LCS[len1][len2];
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            if(i==0 or j==0)
                LCS[i][j]=0;
            else if(s1[i-1]==s2[j-1]){
                LCS[i][j] = LCS[i-1][j-1]+1;
            }else{
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }
    return LCS[len1-1][len2-1];
}