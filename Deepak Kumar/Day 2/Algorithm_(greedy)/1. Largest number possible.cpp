#include <bits/stdc++.h>
using namespace std;

void solution(vector<int>& ans, int no_of_digit, int sum){
    if(sum==0 && no_of_digit!=1){
        ans.push_back(-1);
        return ;
    }
    else if(sum > 9*no_of_digit){
        ans.push_back(-1);
        return ;
    }
    for(int i=0;i<no_of_digit;i++){
        if(sum>=9){
            ans.push_back(9);
            sum=sum-9;
        }
        else if(sum==0){
            ans.push_back(0);
        }
        else{
            ans.push_back(sum);
            sum=0;
        }
    }
    return;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int no_of_digit=0,sum=0;
	    cin>>no_of_digit>>sum;
	    vector<int> ans;
	    solution(ans,no_of_digit,sum);
	    for(int i=0;i<ans.size();i++){
	        cout<<ans[i];
	    }
	    ans.clear();
	    cout<<endl;
	}
	return 0;
}
