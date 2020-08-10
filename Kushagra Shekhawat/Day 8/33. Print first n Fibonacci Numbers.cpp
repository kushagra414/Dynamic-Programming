#include<bits/stdc++.h>
using namespace std;
int main()
 {
    long long fibonacci[84];
    memset(fibonacci,-1,sizeof(long long int)*84);
    fibonacci[0]=1,fibonacci[1]=1;
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    for(int i=2;i<N;i++){
	        if(fibonacci[i]==-1){
	            fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
	        }
	    }
	    for(int i=0;i<N;i++)
	        cout<<fibonacci[i]<<" ";
	    cout<<endl;
	}
	return 0;
}