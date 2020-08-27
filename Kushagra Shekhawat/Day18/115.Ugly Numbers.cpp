using namespace std;

long long int min(long long int a, long long int b, long long int c){
    long long int minimum =  a>b?b:a;
        return minimum>c?c:minimum;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    cin>>N;
	    long long int uglyNos[N];
	    int i2=0,i3=0,i5=0;
	    long long int next_multiple_of_2 = 2, next_multiple_of_3 = 3, next_multiple_of_5 = 5;
	    long long int next_ugly_no=1;
	    uglyNos[0]=1;
	    for(int i=1;i<N;i++){
	        next_ugly_no = min(next_multiple_of_2,next_multiple_of_3,next_multiple_of_5);
	        uglyNos[i]=next_ugly_no;
	        
	        if(next_ugly_no == next_multiple_of_2){
	            i2++;
	            next_multiple_of_2 = uglyNos[i2]*2;
	        }
	        if(next_ugly_no == next_multiple_of_3){
	            i3++;
	            next_multiple_of_3 = uglyNos[i3]*3;
	        }
	        if(next_ugly_no == next_multiple_of_5){
	            i5++;
	            next_multiple_of_5 = uglyNos[i5]*5;
	        }
	    }
	    cout<<next_ugly_no<<endl;;
	}
	return 0;
}