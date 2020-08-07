#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,K,temp,buy=0;
	    cin>>N>>K;
	    set<int>s;
	    for(int i=0;i<N;i++){
	        cin>>temp;
	        s.insert(temp);
	    }
	    int maxCoins = pow(10,9);
        for(int i=1;i<=maxCoins;i++){
            if(s.find(i) == s.end() and K>=i){
                buy++;
                K-=i;
            }
            else if(K<i)
                break;
        }
        cout<<buy<<endl;
	}
	return 0;
}