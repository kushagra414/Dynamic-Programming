#include<iostream>
#include <boost/multiprecision/cpp_int.hpp> 
using namespace std;
using namespace boost::multiprecision;

int main()
 {
    int256_t catalan[101]={0};
    int max=1;
    catalan[0] = catalan[1] = 1;
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    for(int i=max+1;i<=N;i++){
	        for(int j=0;j<i;j++){
	            // 2 pointer approach
	            catalan[i]+=catalan[j]*catalan[i-j-1];
	        }
	    }
	    max=max>N?max:N;
	    cout<<catalan[N]<<endl;
	}
	return 0;
}