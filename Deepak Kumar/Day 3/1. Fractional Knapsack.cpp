#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,weight;
	    cin>>N>>weight;
	    vector<pair<float,pair<float,float>>> ans;
	    double value, item;
	    for(int i=0;i<N;i++){
	        cin>>value>>item;
	        ans.push_back(make_pair((double)(value/item),make_pair(value,item)));
	    }
	    double solution=0;
	    int i=N-1;
	    sort(ans.begin(),ans.end());
	    while(weight && i>=0){
	        if(ans[i].second.second<=weight){
	            weight=weight-ans[i].second.second;
	            solution=solution+ans[i].second.first;
	        }
	        else{
	            solution=solution + (weight*(ans[i].first));
	            break;
	        }
	        i--;
	    }
	    //ans.clear();
	    cout<<fixed<<setprecision(2)<<solution<<endl;
	}
	return 0;
}
