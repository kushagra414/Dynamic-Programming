using namespace std;

int gcd(int a,int b);
int TwoWaterJug(int fromJug, int toJug, int d);
int findMinSteps(int m,int n,int d);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int m,n,d;
	    cin>>m>>n>>d;
	    cout<<findMinSteps(m,n,d)<<endl;
	}
	return 0;
}

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int TwoWaterJug(int fromJug,int toJug, int d){ 
    int from = fromJug; 
    int to = 0,temp; 
  
    int step = 1;
    while (from != d && to != d) 
    {
        temp = min(from, toJug - to); 
        to   += temp; 
        from -= temp; 
        step++;
        if(from == d or to == d) 
            break; 
        if(from == 0){ 
            from = fromJug; 
            step++; 
        } 
        if(to == toJug){ 
            to = 0; 
            step++; 
        } 
    } 
    return step; 
}

int findMinSteps(int m,int n,int d){
    if (m > n) 
        swap(m, n); 
    if (d > n) 
        return -1; 
    if ((d % gcd(n,m)) != 0) 
        return -1; 
    return min(TwoWaterJug(n,m,d),TwoWaterJug(m,n,d));
}