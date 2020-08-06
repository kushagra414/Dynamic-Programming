#include <iostream>
#include<vector>
using namespace std;

vector<int> v ,fact = {1,1,2,6,24,120,720,5040,40320,362880} ;

int check( long long int n ){
    v.clear() ;
    
    int  i = 9 , state = 0 ;
    while( n!=0 ){
        
        while( i>=1 ){
            if( fact[i] <= n ){
                n-=fact[i] ;
                v.push_back(i) ;
                state = 1;
                break;
            }
            else{
                i--;
            }
        }
        if( state!=1 ){
            break;
        }
        
        state = 0 ;
    }
    
    if( n == 0 ){
        return 0 ;
    }
    else {
        return -1;
    }
    
}


int main() {
	int t ; cin>>t;
	while( t-- ){
	    long long int n ;
	    cin>>n;
	    if( check(n) !=-1 ){
	        for( int i = v.size()-1 ; i >= 0 ;i-- ){
	            cout<<v[i];
	        }
	    }
	    else{
	        cout<<-1 ;
	    }
	    cout<<endl;
	}
	return 0;
}
