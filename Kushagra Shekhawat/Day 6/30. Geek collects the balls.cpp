#include<bits/stdc++.h>
using namespace std;

int FindMaxBalls(int road1[],int road2[],int N,int M);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,M;
	    cin>>N>>M;
	    int road1[N],road2[M],totalBallsRoad1=0,totalBallsRoad2=0;
	    for(int bucket=0;bucket<N;bucket++)
	        cin>>road1[bucket];
	    for(int bucket=0;bucket<M;bucket++)
	        cin>>road2[bucket];
	    cout<<FindMaxBalls(road1,road2,N,M)<<endl;
	}
	return 0;
}

int FindMaxBalls(int road1[],int road2[],int N,int M){
    int sumRoad1=0,sumRoad2=0,maxSum=0,i=0,j=0;
	for(i=0,j=0;i<N and j<M;){
	    while(road1[i]>road2[j] and j<M and i<N){
	        sumRoad2+=road2[j++];
	    }
	    while(road1[i]<road2[j] and i<N and j<M){
	        sumRoad1+=road1[i++];
	    }
	    if((j<M and i<N) and road1[i] == road2[j]){
	        maxSum += max(sumRoad1,sumRoad2);
	        maxSum+=road1[i];
	        sumRoad1=0, sumRoad2=0;
	        if(i+1<N and road1[i] == road1[i+1])
	            i++;
	        else if(j+1<M and road2[j] == road2[j+1] )
	            j++;
	        else
	            i++,j++;
	    }
	}
	while(i<N)
	    sumRoad1+=road1[i++];
	while(j<M)
	    sumRoad2+=road2[j++];
	if(sumRoad1!=0 or sumRoad2!=0)
	    maxSum += max(sumRoad1,sumRoad2);
	return maxSum;
}