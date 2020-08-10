#include<bits/stdc++.h>
using namespace std;

struct Gold{
    int weight,value;
    double vByW;
};

bool CompareProfit(Gold a, Gold b){
    return a.vByW>b.vByW;
}

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,C;
	    double profit=0;
	    cin>>N>>C;
	    Gold bars[N];
	    for(int i=0;i<N;i++){
	        cin>>bars[i].weight>>bars[i].value;
	        bars[i].vByW = (bars[i].value/(bars[i].weight*1.00));
	    }
	    sort(bars,bars+N,CompareProfit);
	    for(int i=0;i<N and C>0;i++){
	        int sqrtBar = sqrt(bars[i].weight);
	        if(sqrtBar*sqrtBar == bars[i].weight){
	            continue;
	        }
	        else if(C>=bars[i].weight){
	            C-=bars[i].weight;
	            profit+=bars[i].value;
	        }
	        else{
	            double cut = (bars[i].value*C)/((double)bars[i].weight);
	            profit +=cut;
	            C=0;
	        }
	    }
	    cout<<fixed<<setprecision(3)<<profit<<endl;
	}
	return 0;
}