#include<bits/stdc++.h>
using namespace std;

long long int FindMaxProduct(long long int arr1[]
, long long int arr2[], int N, int M);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,M;
	    cin>>N>>M;
	    long long int arr1[N],arr2[M];
	    for(int i=0;i<N;i++)
	        cin>>arr1[i];
	    for(int i=0;i<M;i++)
	        cin>>arr2[i];
	    cout<<FindMaxProduct(arr1,arr2,N,M)<<endl;
	    //FindMaxProduct(arr1,arr2,N,M);
	}
	return 0;
}

long long int FindMaxProduct(long long int arr1[],
long long int arr2[], int N, int M){
    long long int maxProduct[M][N],product,previousMax;
    memset(maxProduct,0,sizeof(maxProduct));
    for(int i=0;i<M;i++){
        for(int j=i;j<=N-M+i;j++){
            previousMax=0;
            product = (long long)arr2[i]*arr1[j];
            /*cout<<"arr2["<<i<<"]: "<<arr2[i]<<", arr1["<<j<<"]: "
            <<arr1[j]<<endl;*/
            //cout<<"product:"<<product<<", ";
            if(i>0){
                previousMax = *max_element(maxProduct[i-1],
                maxProduct[i-1]+j);
            }
            maxProduct[i][j] = previousMax+product;
        }
    }
    /*for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cout<<maxProduct[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    return *max_element(maxProduct[M-1],maxProduct[M-1]+N);
}