#include <iostream>
using namespace std;

int main() {
	int t ; cin>>t ;
	while(t--){
	    int  n , k ; cin>>n>>k  ;
	    int a[n] , b[n+1] = {0} , temp = k ;
	    for(int i=0; i < n  ;i++){
	        cin>>temp ;
	        a[i] = temp ;
	        b[temp] = i ;
	    }
	    
	        temp = k ;
	        int  lol ;
	        for( int i = 0 ; i < n && temp ; i++ ){
	            
	            if(a[i]== n-i ) continue;
	            
	            lol = b[n-i]  ;
	            b[a[i]] = b[n-i] ;
	            b[n-i] = i ;
	            
	            swap(a[lol], a[i]);
	            temp-- ;
	        }
	        int i ;
	        for( i = 0 ; i< n ; i++){
	            cout<<a[i]<<" ";
	        }
	    cout<<endl;
	}
	return 0;
}
