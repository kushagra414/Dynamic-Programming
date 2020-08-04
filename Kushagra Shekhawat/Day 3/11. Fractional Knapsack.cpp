#include<bits/stdc++.h>
using namespace std;

struct KnapSack{
    int value,weight;
    double wByV;
};

bool compareKnapSack(KnapSack a, KnapSack b){
    return a.wByV > b.wByV;
}

double findMaxTotal(KnapSack knapSack[],int N,int C);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,C;
	    cin>>N>>C;
	    KnapSack knapSack[N];
	    for(int i=0;i<N;i++){
	        cin>>knapSack[i].value>>knapSack[i].weight;
	        knapSack[i].wByV = knapSack[i].value/(knapSack[i].weight*1.00);
	    }
	    sort(knapSack,knapSack+N,compareKnapSack);
	    cout<<fixed<<setprecision(2)<<findMaxTotal(knapSack,N,C)<<endl;
	}
	return 0;
}

double findMaxTotal(KnapSack knapSack[],int N, int C){
    double Maxtotal = 0;
    for(int i=0;i<N and C>0;i++){
        if(knapSack[i].weight<=C){
            Maxtotal += knapSack[i].value;
            C-=knapSack[i].weight;
        }
        else if(knapSack[i].weight>C){
            Maxtotal += (C*knapSack[i].value/(knapSack[i].weight*1.00));
            C = 0;
        }
    }
    return Maxtotal;
}