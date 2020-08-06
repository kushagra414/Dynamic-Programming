#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
	    string str;
	    cin>>str;
	    string cp=str;
	    sort(cp.begin(),cp.end());
	    int i;
	    char c1='&',c2='&';
	    int flag=0;
	    for(i=0;i<str.size();i++){
	        size_t f=str.find(cp[i]);
	        for(int j=0;j<f;j++){
	            if(str[j]>cp[i]){
	                c1=str[j];
	                c2=cp[i];
	                flag=1;
	                break;
	            }
	        }
	        if(flag==1)
	            break;
	    }
	    for(int i=0;i<str.size();i++){
            if(str[i]==c1)
                cout<<c2;
            else if(str[i]==c2)
                cout<<c1;
            else
                cout<<str[i];
        }
        cout<<endl; 
	}
	return 0;
}
