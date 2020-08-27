
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int n,count=0;
	    cin>>n;
	    string s[n];
	    vector<int>groups;
	    vector<bool>isAnagram(n,false);
	    for(int i=0;i<n;i++)
	        cin>>s[i];
	    for(int i=0;i<n;i++)
	        sort(s[i].begin(),s[i].end());
	    for(int i=0;i<n;i++){
	        count=1;
	        if(isAnagram[i]==false)
    	        for(int j=i+1;j<n;j++){
    	            if(s[i]==s[j]){
    	                isAnagram[j]=true;
    	                count++;
    	            }
    	        }
	        if(isAnagram[i] == false)
	            groups.push_back(count);
	        isAnagram[i] = true;
	    }
	    sort(groups.begin(),groups.end());
	    for(int i=0;i<groups.size();i++)
	        cout<<groups[i]<<" ";
	    cout<<endl;
	}
	return 0;
}