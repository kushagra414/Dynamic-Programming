#include <iostream>
#include <algorithm>
using namespace std;

struct order{
    int no , st , ti, end ;
};

bool compare( struct order a , struct order b){
    if( a.end < b.end ){
        return true ;
    }
    else if( a.end == b.end ){
        if( a.no < b.no )
        return true ;
        else return false ;
    }
    else{
        return false ;
    }
}

int main() {
	int t ; cin>>t ;
	while( t-- ){
	    int n ; cin>> n ;
	    struct order a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i].st>>a[i].ti;
	        a[i].no = i+1 ;
	        a[i].end = a[i].st + a[i].ti ;
	    }
	    sort( a , a+n , compare ) ;
	    for(int i=0;i<n;i++){
	        cout<<a[i].no<<endl ; 
	    }
	}
	return 0;
}
