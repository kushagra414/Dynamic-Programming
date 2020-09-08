#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int a,b;
	    cin>>a>>b;
	    cout<<__builtin_popcount(a^b)<<endl;
	}
	return 0;
}