#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int  t ; cin>>t;
	while(t--){
	    int n , f ; cin>>n>>f;
	    int a[n] ;
	    for(int  i = 0 ; i < n ; i++){
	        cin>>a[i] ;
	    }
	    
	    sort( a, a+n );
	    
	    int  temp = n ; int c=0;
	    for( int i=0 ; i<temp ; i++ ){
	        c+=a[i];
	        temp-=f;
	    }
	    cout<<c<<" ";
	    temp = 0 ;c=0;
	    for( int i=n-1 ; i >= 0 ; i-- ){
	        c+=a[i];
	        temp+=f;
	        if( temp >= i ){
	            break;
	        }
	    }
	    cout<<c<<endl;
	    
	}
	return 0;
}
