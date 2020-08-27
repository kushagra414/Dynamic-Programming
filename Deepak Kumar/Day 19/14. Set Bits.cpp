#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int count=0;
	    while(N){
	        if(N%2==1){
	            count++;
	        }
	        N=N/2;
	    }
	    cout<<count<<endl;
	}
	return 0;
}
