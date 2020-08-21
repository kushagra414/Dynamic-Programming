// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/

bool compare(val a,val b){
    if(a.first<b.first || (a.first==b.first && a.second<b.second)){
        return true;
    }
    return false;
}

int solution(val p[],int n){
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[i].first>p[j].second && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i]);
    }
    return ans;
}

int maxChainLen(struct val p[],int n){
    sort(p,p+n,compare);
    return solution(p,n);
}
