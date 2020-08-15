#include<bits/stdc++.h>
using namespace std;

int cutRod(int arr[],int N);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int rods[N];
	    for(int i=0;i<N;i++)
	        cin>>rods[i];
	    cout<<cutRod(rods,N)<<endl;
	}
	return 0;
}

int cutRod(int arr[],int N){
    int maxPrice[N+1]={0},quotient,Remainder,priceMax,price;
    maxPrice[1]=arr[0];
    for(int i=1;i<=N;i++){
        for(int j=1;j<i;j++){
            priceMax=INT_MIN;
            quotient = i/j;
            Remainder = i%j;
            price = quotient*maxPrice[j]+maxPrice[Remainder];
            maxPrice[i] = max(maxPrice[i],max(price,arr[i-1]));
        }
    }
    return maxPrice[N];
}