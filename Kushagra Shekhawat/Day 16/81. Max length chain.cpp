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

bool ComparePair(val val1, val val2){
    return val1.second<val2.second;
}

int maxChainLen(struct val p[],int n)
{
    int max_chain=1;
    sort(p,p+n,ComparePair);
    for(int j=0,i=1;i<n;i++){
        if(p[i].first>p[j].second){
            //cout<<"Pair is :"<<"("<<p[j].first<<","<<p[j].second<<")"<<" <------ "<<"("<<p[i].first<<","<<p[i].second<<")"<<endl;
            j=i;
            max_chain++;
        }
    }
    return max_chain;
}