#include<bits/stdc++.h>
using namespace std;

int findLRS(string s);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    string s;
	    cin>>N>>s;
	    cout<<findLRS(s)<<endl;
	}
	return 0;
}

int findLRS(string s){
    int len = s.length()+1,maximum=INT_MIN;
    int LRS[len][len];
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(i==0 or j==0)
                LRS[i][j] = 0;
            else if(i>=j)
                LRS[i][j] = 0;
            else if(s[i-1] == s[j-1]){
                LRS[i][j] = LRS[i-1][j-1]+1;
                if(LRS[i][j]>maximum)
                    maximum =LRS[i][j];
            }
            else{
                LRS[i][j] = max(LRS[i-1][j],LRS[i][j-1]);
            }
        }
    }
    return maximum;
}