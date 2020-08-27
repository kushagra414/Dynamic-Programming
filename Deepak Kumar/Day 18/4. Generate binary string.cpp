#include <bits/stdc++.h>
using namespace std;

void solution(vector<string>& v,string str,string s,int start,int end){
    if(start==end){
        v.push_back(s);
        return ;
    }
    if(str[start]=='?'){
        solution(v,str,s+'0',start+1,end);
        solution(v,str,s+'1',start+1,end);
    }
    else{
        solution(v,str,s+str[start],start+1,end);
    }
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str;
	    cin>>str;
	    vector<string> v;
	    int len=str.length();
	    string s;
	    solution(v,str,s,0,len);
	    for(int i=0;i<v.size();i++){
	        cout<<v[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
