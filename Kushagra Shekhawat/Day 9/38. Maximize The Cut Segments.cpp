#include<bits/stdc++.h>
using namespace std;

int maxCutSegments(int N,int x,int y,int z);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,x,y,z;
	    cin>>N>>x>>y>>z;
	    cout<<maxCutSegments(N,x,y,z)<<endl;
	}
	return 0;
}

int maxCutSegments(int N,int x,int y,int z){
    int ropeSegments[N+1];
    memset(ropeSegments,-1,sizeof(ropeSegments));
    ropeSegments[0]=0;
    for(int i=0;i<=N;i++){
        if(ropeSegments[i]==-1)
            continue;
        if(i+x<=N)
            ropeSegments[i+x]=max(ropeSegments[i+x],
            ropeSegments[i]+1);
        if(i+y<=N)
            ropeSegments[i+y]=max(ropeSegments[i+y],
            ropeSegments[i]+1);
        if(i+z<=N)
            ropeSegments[i+z]=max(ropeSegments[i+z],
            ropeSegments[i]+1);
    }
    return ropeSegments[N];
}