#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int t ; cin>>t;
	while( t-- ){
	    int n , k , c = 0 ;
	    cin>>n>>k;
	    int a[n] ;
	    for( int  i = 0 ; i < n ; i++ ){
	        cin>>a[i];
	    }
	    
	    sort( a , a+n );
	    
	    for( int  i = 0 ; i < n; i++ ){
	        if( a[i] > k ){
	            break;
	        } 
	        else{
	            c++ ; 
	            k-=a[i] ;
	        }
	    }
	    cout<<c<<endl;
	}
	return 0;
}
