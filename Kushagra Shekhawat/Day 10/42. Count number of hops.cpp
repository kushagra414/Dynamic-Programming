#include<iostream>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	long long int jumps[51];
    int max=4;
    jumps[0]=0;
    jumps[1]=1; jumps[2]=2;jumps[3]=4;
	while(T--){
	    int N;
	    cin>>N;
	    for(int i=max;i<=N;i++){
	        jumps[i] = jumps[i-1]+jumps[i-2]+jumps[i-3];
	    }
	    max = max>N?max:N;
	    cout<<jumps[N]<<endl;
	}
	return 0;
}