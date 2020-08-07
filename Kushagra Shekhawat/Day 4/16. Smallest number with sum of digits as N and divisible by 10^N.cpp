#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,M;
	    cin>>N;
	    string num="";
	    M = N;
	    while(N){
	        for(int i=9;i>=0;i--){
	            if(N-i>=0){
	                num += to_string(i);
	                N-=i;
	                break;
	            }
	        }
	    }
	    reverse(num.begin(),num.end());
	    cout<<num;
	    for(int i=0;i<M;i++)
	        cout<<"0";
	    cout<<endl;
	}
	return 0;
}