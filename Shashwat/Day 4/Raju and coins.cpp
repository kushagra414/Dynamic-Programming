#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t ; cin>>t ;
	while(t--){
	    long long int n , k ; cin>>n>>k ; 
	    long long int a[n] ;
	    for(long long int i=0 ; i<n ; i++){
	         cin>>a[i] ;
	    }
	    sort( a , a+n );
	    long long int l = 1 , i = 0 , c = 0 ;
	    while( k >= l ){
	        if( a[i] != l ){
	            k-=l ;
	            c++ ;
	        }
	        else{
	            i++;
	        }
	        l++ ;
	    }
//	    cout<<"L="<<l<<endl;
	    cout<<c<<endl;

	}
	return 0;
}
