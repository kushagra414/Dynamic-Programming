#include <bits/stdc++.h>
using namespace std;

void findNextLarger(long long int array[], long long int N);

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    long long int N;
	    scanf("%lld",&N);
	    long long int array[N];
	    for(int i=0;i<N;i++)
	        scanf("%lld",&array[i]);
	    findNextLarger(array, N);
	    printf("\n");
	}
	return 0;
}

void findNextLarger(long long int array[], long long int N){
    long long int foundNextLarger=0,ans[N];
    stack <long long int> s;
    for(int i=N-1;i>=0;i--){
        while(!s.empty()&&array[i]>s.top())
            s.pop();
        ans[i] = s.empty()?-1:s.top();
        s.push(array[i]);
    }
    for(int i=0;i<N;i++)
        printf("%lld ",ans[i]);
}