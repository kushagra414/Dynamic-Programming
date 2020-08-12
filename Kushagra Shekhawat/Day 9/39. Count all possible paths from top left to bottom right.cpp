#include<bits/stdc++.h>
using namespace std;

long long int FindPaths(int N,int M);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,M;
	    cin>>N>>M;
	    cout<<FindPaths(N,M)<<endl;
	}
	return 0;
}

long long int FindPaths(int N,int M){
    long long int PathMatrix[N][M];
    long long int Mod = pow(10,9)+7;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            PathMatrix[i][j]=1;
    for(int i=1;i<N;i++)
        for(int j=1;j<M;j++){
            PathMatrix[i][j]=(PathMatrix[i-1][j]+PathMatrix[i][j-1])%Mod;
        }
    return (PathMatrix[N-1][M-1])%Mod;
}