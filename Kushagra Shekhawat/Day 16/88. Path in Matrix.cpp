
int ThreeWayMax(int up,int upLeft, int upRight){
    int maximum = up<upLeft?2:1;
    if(maximum==1)
        return up<upRight?3:1;
    return upLeft<upRight?3:2;
}

void ConstructMaxSumMatrix(int N,int MaxSum[][N], int Matrix[][N]){
    for(int i=1;i<N;i++)
        for(int j=0;j<N;j++){
            int up,upLeft,upRight,index;
            up = j;
            upLeft = j-1>=0?j-1:up;
            upRight = j+1<N?j+1:up;
            int maximum = ThreeWayMax(MaxSum[i-1][up],MaxSum[i-1][upLeft],MaxSum[i-1][upRight]);
            if(maximum==1)
                index=up;
            else if(maximum==2)
                index=upLeft;
            else
                index=upRight;
            MaxSum[i][j] = MaxSum[i-1][index]+Matrix[i][j];
        }
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	    int Matrix[N][N];
	    for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
	        scanf("%d",&Matrix[i][j]);
	    int MaxSum[N][N];
	    for(int i=0;i<N;i++)
	        MaxSum[0][i]=Matrix[0][i];
	    ConstructMaxSumMatrix(N,MaxSum,Matrix);
	    int max=0;
	    for(int i=N-1,j=0;j<N;j++)
	        max = MaxSum[i][j]>max?MaxSum[i][j]:max;
	    printf("%d\n",max);
	}
	return 0;
}
