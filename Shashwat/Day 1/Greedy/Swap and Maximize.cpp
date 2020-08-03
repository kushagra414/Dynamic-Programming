#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	
	int t ; cin>>t ;
	while( t-- ){
	    int n ; cin>>n;
	    int a[n];
	    for( int  i = 0 ; i<n ; i++ ){
	        cin>>a[i];
	    }
	    sort( a , a+n );
	    int i = 0 , j = n-1 , s = 0 , f = 0 ;
	    while( i<j ){
	        if( f ==0 ){
	            s += a[j] - a[i] ;
	            i++; f = 1 ;
	        }
	        else{
	            s += a[j] - a[i];
	            j-- ; f = 0 ;
	        }
	    }
	    s+=a[j] - a[0] ;
	    cout<<s<<endl;
	}
	return 0;
}
