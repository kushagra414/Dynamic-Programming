#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    vector<pair<int,int>> v;
	    int profit=0,deadline=0,id=0;
	    for(int i=0;i<N;i++){
	        cin>>id>>deadline>>profit;
	        v.push_back(make_pair(profit,deadline));
	    }
	    int max_profit=0,count=0;
	    sort(v.begin(),v.end(),greater<pair<int,int>>());
	    int slot[N]={0};
	    for(int i=0;i<N;i++){
	        for(int j=min(N-1,v[i].second-1);j>=0;j--){
	            if(slot[j]==0){
	                slot[j]=1;
	                count++;
	                max_profit+=v[i].first;
	                break;
	            }
	        }
	    }
	    cout<<count<<" "<<max_profit<<endl;
	}
	return 0;
}
