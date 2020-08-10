#include<iostream>
using namespace std;

unsigned long long int arr[100];
int Max=3;
void PadovanSequence(int n);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    arr[0]=arr[1]=arr[2]=1;
	    PadovanSequence(N);
	    cout<<arr[N]%1000000007<<endl;
	}
	return 0;
}

void PadovanSequence(int n){
    if(n>2){
        for(int i=Max;i<=n;i++){
            arr[i]=arr[i-2]+arr[i-3];
        }
	   Max=Max<n?n:Max;
    }
}