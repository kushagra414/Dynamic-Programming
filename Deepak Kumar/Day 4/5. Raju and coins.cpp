#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int len,money;
	    cin>>len>>money;
	    int A[len];
	    for(int i=0;i<len;i++){
	        cin>>A[i];
	    }
	    map<int,int> mp;
	    for(int i=0;i<len;i++){
	        mp[A[i]]++;
	    }
	    int count=0;
	    for(int i=1;i<=money;i++){
	        if(mp.count(i)>0){
	            continue;
	        }
	        else if(mp.count(i)==0 && money>0){
	            count++;
	            money=money-i;
	        }
	        else if(money<=0){
	            break;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
