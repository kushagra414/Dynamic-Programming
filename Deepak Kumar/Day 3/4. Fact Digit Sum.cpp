#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    unsigned long long int num;
	    cin>>num;
	    unsigned long long int A[]={1,1,2,6,24,120,720,5040,40320,362880};
	    int i=9;
	    vector<int> ans;
	    while(num && i>=0){
	        if(A[i]==num){
	            ans.push_back(i);
	            break;
	        }
	        else if(num>A[i]){
	            num=num-A[i];
	            ans.push_back(i);
	        }
	        if(num<A[i]){
	            i--;
	        }
	    }
	    for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i];
        }
	    cout<<endl;
	}
	return 0;
}
