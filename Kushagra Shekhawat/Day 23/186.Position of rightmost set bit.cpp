#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    //n = n&(-n);  //to get the right most bit
	    // then do log2(n)
	    //but the best is using ffs() function which returns index of
	    //least significant bit
	    cout<<ffs(n)<<endl;
	}
	return 0;
}