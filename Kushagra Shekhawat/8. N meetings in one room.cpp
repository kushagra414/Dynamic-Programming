#include<bits/stdc++.h>
using namespace std;

struct Metting{
    int start,end,index;
};

bool CompareMettings(Metting a, Metting b){
    return a.end<b.end;
}

void findMaxMettings(Metting mettings[],int N);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    Metting mettings[N];
	    for(int i=0;i<N;i++){
	        cin>>mettings[i].start;
	        mettings[i].index = i;
	    }
	    for(int i=0;i<N;i++)
	        cin>>mettings[i].end;
	    sort(mettings, mettings+N, CompareMettings);
	    findMaxMettings(mettings,N);
	}
	return 0;
}

void findMaxMettings(Metting mettings[],int N){
    int j=0;
    cout<<mettings[0].index+1<<" ";
    for(int i=1;i<N;i++){
        if(mettings[i].start>=mettings[j].end){
            j = i;
            cout<<mettings[i].index+1<<" ";
            }
    }
    cout<<endl;
}