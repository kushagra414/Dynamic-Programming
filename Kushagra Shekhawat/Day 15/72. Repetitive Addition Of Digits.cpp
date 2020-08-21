#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    if(n%9==0)
	        cout<<9<<endl;
	    else
	        cout<<n%9<<endl;
	}
	return 0;
}