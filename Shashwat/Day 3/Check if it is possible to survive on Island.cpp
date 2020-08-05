#include <iostream>
using namespace std;

int main() {
	int t ; cin>>t;
	while(t--){
	    int n, s, m , c=0 ;
	    cin>>s>>n>>m ;
	    if( m >= n ){
	        c = -1;
	    }
	    else{
	        int stock = 0  ;
	        int total_needed = s*m ;
	        for(int i = 1; i <= s ; i++ ){
	            if( total_needed <= 0 ){
	                break;
	            }
	                if( stock < m && i % 7 == 0 ){
	                    c=-1;
	                    break;
	                }
	                else if( i % 7 != 0 ){
	                    stock+=n;
	                    c++ ;
	                    stock-=m;
	                    total_needed -= n ;
	                }
	                else{
	                    stock-=m;
	                }
	            }
	        }
	            cout<<c<<endl;
	    }
	return 0;
}
