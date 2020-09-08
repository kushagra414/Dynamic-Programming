#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    //Your code here
	    unsigned int n;
	    cin>>n;
	    if(!(n&(n-1)))
	        cout<<ffs(n)<<endl;
	    else
	        cout<<-1<<endl;
	}
	return 0;
}