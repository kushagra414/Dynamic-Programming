#include<bits/stdc++.h>
using namespace std;

//LIS ---> Longest Increasing Sum

struct Sequence{
    int value, LIS;
};

int MSIS(Sequence seq[], int N);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int x;
	    Sequence seq[N];
	    for(int i=0;i<N;i++){
	        cin>>x;
	        seq[i].value = seq[i].LIS = x;
	    }
	    cout<<MSIS(seq,N)<<endl;
	}
	return 0;
}

int MSIS(Sequence seq[], int N){
    int maximumSum = INT_MIN;
    for(int i=1;i<N;i++){
    	for(int j=0;j<i;j++){
    	    if(seq[j].value<seq[i].value){
    	        seq[i].LIS = max(seq[i].LIS,
    	        seq[i].value+seq[j].LIS);
    	    }
    	}
	}
	for(int i=0;i<N;i++){
	    maximumSum = maximumSum>seq[i].LIS?maximumSum:seq[i].LIS;
	}
	return maximumSum;
}