#include<iostream>
using namespace std;
int main()
 {
    long long int jumps[91]={0};
    int max=3;
    jumps[1]=1; jumps[2]=2;
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    for(int i=max;i<=N;i++){
	        jumps[i]=jumps[i-1]+jumps[i-2];
	    }
	    max=max>N?max:N;
	    cout<<jumps[N]<<endl;
	}
	return 0;
}