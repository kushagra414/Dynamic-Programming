using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int A[N],B[N];
	    for(int i=0;i<N;i++){
	        cin>>A[i];
	    }
	    for(int i=0;i<N;i++){
	        cin>>B[i];
	    }
	    long long unsigned int sum=0;
	    sort(A,A+N);
	    sort(B,B+N,greater<int>());
	    for(int i=0;i<N;i++){
	        sum=sum+(A[i]*B[i]);
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
