#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,S,sum=0,lowerLimit=0;
	    string num="";
	    bool notFound;
	    cin>>N;
	    cin>>S;
	    for(int i=0;i<N;i++){
	        notFound = true;
	        for(int j=9;j>=0;j--){
	            if(j+sum<=S){
	                sum+=j;
	                num+=to_string(j);
	                notFound = false;
	                break;
	            }
	        }
	        if(notFound)
	            break;
	    }
	    if(notFound or sum != S)
	        cout<<-1<<endl;
	    else
	        cout<<num<<endl;
	}
	return 0;
}