using namespace std;

int arr[1000001];
int Max=0;
void Count4(int n);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,count=0;
	    cin>>N;
	    arr[0]=0;
	    Count4(N);
	   
	    cout<<arr[N]<<endl;
	}
	return 0;
}


void Count4(int n){
    int previous=arr[Max];
    for(int i=Max+1;i<=n;i++){
            string test = to_string(i);
            size_t found=test.find('4');
            if(found != std::string::npos){
                arr[i]=++previous;
            }
            else{
                arr[i]=previous;
            }
    }
    Max=Max<n?n:Max;
}