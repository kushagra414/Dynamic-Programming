#include <bits/stdc++.h>
using namespace std;

int solution(int N){
    int sub_count=0;
    int div_count=0;
    while(N){
        int temp=N%2;
        if(temp==1){
            sub_count++;
        }
        div_count++;
        N=N/2;
    }
    return (div_count+sub_count-1);
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    cout<<solution(N)<<endl;
	}
	return 0;
}
