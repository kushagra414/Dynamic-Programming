#include<bits/stdc++.h>
using namespace std;

int fact[10];

int main()
 {
	int T;
	cin>>T;
	fact[0] = 1;
	for(int i=1;i<10;i++){
        fact[i] = fact[i-1]*i;
	}
	while(T--){
	    int N;
	    cin>>N;
	    string num = "";
	    while(N>0){
    	    for(int i=9;i>=0;i--){
    	        if(fact[i]<=N){
    	            num+=to_string(i);
    	            N -= fact[i];
    	            break;
    	        }
    	    }
	    }
	    reverse(num.begin(),num.end());
	    if(N == 0)
	        cout<<num<<endl;
	    else
	        cout<<-1<<endl;
	}
	return 0;
}