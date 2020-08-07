#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;

int main() {
	int t ; cin>>t;
	while( t-- ){
	    int n , k ; cin>>k>>n ;
	    int a[n] , mini = 500 , max = 0 ;int  mean = 0 ;
	    
	    
	    for(int i=0;i<n;i++){
	        cin>>a[i] ;
	        if( a[i] < mini ){
	            mini = a[i] ;
	        }
	        if( a[i]>max ){
	            max = a[i] ;
	        }
//	        cout<<a[i]<<" ";
	    }
	    
	   // if( n == 2 ){
	   //     cout<<max-min<<endl;
	   //     continue ;
	   // }
	    
//	    cout<<endl;
	    
//	    sort( a , a+n );
	    
	    mean = ( mini + max )/(2) ;
	   // if( mean - (int) mean == 0 ){
	   //     mean -= 1 ;
	   // }
	    
//	    cout<<"Mean = "<<mean<<" "<<endl; ;
	    for( int i = 0 ; i < n ; i++ ){
	         if( a[i] <= mean ){
	             a[i]+= k;
	         } else{
	             a[i]-= k ;
	         }
//	         cout<<a[i]<<" ";
	    }
//	    cout<<endl;
	    sort( a , a+n ) ; 
	   // for( int  i = 0 ; i <n ; i++ )
	   //     cout<<a[i]<<" ";
	   // cout<<endl;
	    
	    cout<<min(a[n-1]-a[0] , max-mini)<<endl;
	}
	return 0;
}
