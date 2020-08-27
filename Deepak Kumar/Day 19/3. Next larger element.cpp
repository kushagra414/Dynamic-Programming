#include <bits/stdc++.h>
using namespace std;
#define ull long long

void solution(ull v[],ull N){
    ull ans[N]={0};
    stack<ull> s;
    for(int i=N-1;i>=0;i--){
        while(!s.empty() && v[i]>s.top()){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }
        s.push(v[i]);
    }
    for(int i=0;i<N;i++){
	    cout<<ans[i]<<" ";
    }
    return;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    ull N;
	    cin>>N;
	    ull v[N];
	    for(int i=0;i<N;i++){
	        cin>>v[i];
	    }
	    solution(v,N);
	    cout<<endl;
	}
	return 0;
}
