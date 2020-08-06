#include<bits/stdc++.h>
using namespace std;

struct PizzaOrders{
    int x,y,index;
};

bool Compare(PizzaOrders a, PizzaOrders b){
    if(a.x+a.y==b.x+b.y)
        return a.index<b.index;
    return a.x+a.y<b.x+b.y;
}

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    PizzaOrders orders[N];
	    for(int i=0;i<N;i++){
	        cin>>orders[i].x;
	        cin>>orders[i].y;
	        orders[i].index = i;
	    }
	    sort(orders,orders+N,Compare);
	    for(int i=0;i<N;i++){
	        cout<<orders[i].index+1<<endl;
	    }
	}
	return 0;
}