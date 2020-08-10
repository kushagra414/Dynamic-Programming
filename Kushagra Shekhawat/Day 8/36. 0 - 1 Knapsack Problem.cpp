using namespace std;

int knapSack(int val[],int wt[],int N,int cap);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,cap;
	    cin>>N>>cap;
	    int val[N],wt[N];
	    for(int i=0,j=0;i<N,j<N;){
	        if(i<N)
	            cin>>val[i++];
	        else
	            cin>>wt[j++];
	    }
	    cout<<knapSack(val,wt,N,cap)<<endl;
	}
	return 0;
}

int knapSack(int val[],int wt[],int n,int W) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
  
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
} 