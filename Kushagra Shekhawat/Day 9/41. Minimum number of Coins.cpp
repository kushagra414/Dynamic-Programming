#include<bits/stdc++.h>
using namespace std;

int rupee[] =  {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
void findMinCoins(int N);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    findMinCoins(N);
	    cout<<endl;
	}
	return 0;
}

void findMinCoins(int N){
    int wholeCoins;
    for(int i=9;i>=0;i--){
        wholeCoins = N/rupee[i];
        if(wholeCoins)
            N %= rupee[i];
        while(wholeCoins--){
            cout<<rupee[i]<<" ";
        }
    }
}
