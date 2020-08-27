#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    cout<<__builtin_popcount(n)<<endl;
	}
	return 0;
}