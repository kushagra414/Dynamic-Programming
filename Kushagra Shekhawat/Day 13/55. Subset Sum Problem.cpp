#include<bits/stdc++.h>
using namespace std;

bool findEqualSets(int set[],int sum,int size);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int set[N];  
	    for(int i=0;i<N;i++)
	        cin>>set[i];
	    int sum = accumulate(set,set+N,0);
	    if(sum%2==0)
	        findEqualSets(set,sum/2,N)==1?cout<<"YES"<<endl:cout<<"NO"<<endl;
	    else
	        cout<<"NO"<<endl;
	}
	return 0;
}

bool findEqualSets(int set[],int sum,int size){
    if(sum == 0){
        return true;
    }
    if(size<=0 or sum<0){
        return false;
    }
    return findEqualSets(set,sum-set[size-1],size-1)
    or findEqualSets(set,sum,size-1);
}
