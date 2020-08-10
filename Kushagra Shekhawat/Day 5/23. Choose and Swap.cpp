#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    string s;
	    cin>>s;
	    int characters[26],N=s.length();
	    bool replaced = false;
	    memset(characters,-1,sizeof(int)*26);
	    for(int i=0;i<N;i++){
	        if(characters[s[i]-97] == -1){
	            characters[s[i]-97] = i;
	        }
	    }
	    for(int i=0;i<N;i++){
	        for(int j=0;j<s[i]-97;j++){
	            if(characters[j]>=0 and i<characters[j]){
	                int temp1 = s[i];
	                int temp2 = j+97;
	                replace(s.begin(),s.end(),s[i]+0,32);
	                replace(s.begin(),s.end(),j+97,temp1);
	                replace(s.begin(),s.end(),32,temp2);
	                replaced = true;
	                break;
	            }
	        }
	        if(replaced)
	           break;
	    }
	    cout<<s<<endl;
	}
	return 0;
}