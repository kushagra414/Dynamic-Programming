#include <iostream>
#include<algorithm>
using namespace std;

bool compare( int x ,  int y ){
    if( x > y ) return true;
    else return false ;
}

int main() {
	int t ; cin>>t ;
	while( t-- ){
	    
	    int n ; cin>>n ;
	    int a[n], b[n] ;
	    for( int i = 0 ; i < n ; i++ ){
	        cin>>a[i];
	    }
	    for( int i = 0 ; i < n ; i++ ){
	        cin>>b[i];
	    }
	    
	    sort( a , a+n );
	    sort( b , b+n , compare );
	    
	    
	    
	    long long int sum = 0 ;
	    for( int i = 0 ; i < n ; i++ ){
	        sum += a[i]*b[i] ;
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
