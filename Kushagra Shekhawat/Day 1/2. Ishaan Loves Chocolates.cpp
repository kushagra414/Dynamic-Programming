#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int chocolate[N];
	    for(int i=0;i<N;i++)
	        cin>>chocolate[i];
	    
	    cout<<*min_element(chocolate,chocolate+N)<<endl;
	}
	return 0;
}