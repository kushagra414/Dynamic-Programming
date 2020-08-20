#include<bits/stdc++.h>
using namespace std;

long long int SticklerThief(long long int houses[],int N);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    long long int houses[N];
	    for(int i=0;i<N;i++)
	        cin>>houses[i];
	    cout<<SticklerThief(houses,N)<<endl;
	}
	return 0;
}

long long int SticklerThief(long long int houses[],int N){
    houses[2]+=houses[0];
    for(int i=3;i<N;i++){
        houses[i]+=max(houses[i-2],houses[i-3]);
    }
    return *max_element(houses,houses+N);
}