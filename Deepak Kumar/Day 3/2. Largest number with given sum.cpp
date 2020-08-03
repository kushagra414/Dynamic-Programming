#include <bits/stdc++.h>
using namespace std;

void solution(vector<int>& ans,int no_of_digit,int sum){
    if(sum>9*no_of_digit){
        ans.push_back(-1);
        return ;
    }
    else{
        for(int i=0;i<no_of_digit;i++){
            if(sum>9){
                ans.push_back(9);
                sum=sum-9;
            }
            else if(sum==0){
                ans.push_back(0);
            }
            else if(sum<=9){
                ans.push_back(sum);
                sum=0;
            }
        }
        return ;
    }
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,S;
	    cin>>N>>S;
	    vector<int> ans;
	    solution(ans,N,S);
	    for(int i=0;i<ans.size();i++){
	        cout<<ans[i];
	    }
	    cout<<endl;
	}
	return 0;
}
