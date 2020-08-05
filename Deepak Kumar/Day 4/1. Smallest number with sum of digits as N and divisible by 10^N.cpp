#include <bits/stdc++.h>
using namespace std;

void solution(vector<int>& ans,int N){
    for(int i=0;i<N;i++){
        ans.push_back(0);
    }
    while(N){
        if(N<10){
            ans.push_back(N);
            return ;
        }
        else if(N>9){
            ans.push_back(9);
            N=N-9;
        }
    }
    return ;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    vector<int> ans;
	    solution(ans,N);
	    for(int i=ans.size()-1;i>=0;i--){
	        cout<<ans[i];
	    }
	    cout<<endl;
	}
	return 0;
}
