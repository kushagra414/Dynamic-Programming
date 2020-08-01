#include <bits/stdc++.h>
using namespace std;

void solution(vector<int>& ans, int sum, int no_of_digit){
    if(sum==0 && no_of_digit==1){
        ans.push_back(0);
        return;
    }
    else if(sum==0 && no_of_digit!=1){
        ans.push_back(-1);
        return ;
    }
    else if(sum > 9*no_of_digit){
        ans.push_back(-1);
        return ;
    }
    
    sum=sum-1;
    for(int i=no_of_digit-1;i>=1;i--){
        if(sum>9){
            ans.push_back(9);
            sum=sum-9;
        }
        else{
            ans.push_back(sum);
            sum=0;
        }
    }
    ans.push_back(sum+1);
    return;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int sum=0,no_of_digit=0;
	    cin>>sum>>no_of_digit;
	    vector<int> ans;
	    solution(ans,sum,no_of_digit);
	    for(int i=ans.size()-1;i>=0;i--){
	        cout<<ans[i];
	    }
	    cout<<endl;
	}
	return 0;
}
