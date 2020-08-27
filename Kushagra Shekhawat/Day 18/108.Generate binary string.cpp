#include<bits/stdc++.h>
using namespace std;

unordered_set<string>us;

void generateBinaryString(string s,int i,int n,int count);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    us.clear();
	    string s;
	    cin>>s;
	    int n = s.length(),count=0;
	    for(int i=0;i<n;i++){
	        if(s[i]=='?')
	            count++;
	    }
	    generateBinaryString(s,0,n,count);
	    cout<<endl;
	}
	return 0;
}

void generateBinaryString(string s,int i,int n,int count){
    if(count==0 or i>=n){
        cout<<s<<" ";
        return;
    }
    if(s[i]=='?'){
        s[i]='0';
        generateBinaryString(s,i+1,n,count-1);
        s[i]='1';
        generateBinaryString(s,i+1,n,count-1);
    }else if(count>0){
        generateBinaryString(s,i+1,n,count);
    }
}