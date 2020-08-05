#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N;
	    cin>>N;
	    string str;
	    cin>>str;
	    int j=0,count=0;
	    stack<char> s;
	    for(int i=0;i<N;i++){
	        if(str[i]=='['){
	            s.push(str[i]);
	        }
	        else if(!s.empty() && s.top()=='[' && str[i]==']'){
	            s.pop();
	        }
	        else if(str[i]==']'){
	            j=i+1;
	            while(str[j]!='['){
				    j++;
			    }
			    if(str[j]=='['){
				    swap(str[i],str[j]);
				    count = count + (j-i);
				    s.push(str[i]);
			    }
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
