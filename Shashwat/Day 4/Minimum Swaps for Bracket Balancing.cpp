#include <iostream>
using namespace std;

int main() {
	int t ; cin>>t ;
	while(t--){
	    int n ;
	    string s ; cin>>n>>s;
	    int l = s.length() ;
	    int lc = 0 , rc = 0 , bal = 0 , c = 0 ;
	    for(int i=0; i<l ; i ++ ){
	        if( s[i]=='[' ){
	            lc++ ;
	            if( bal > 0 ){
	                c+=bal ;
	                bal--;
	            }
	        }
	        else{
	                rc++ ;
	                bal = rc - lc ;
	            }
	    }
	    cout<<c<<endl ;
	}
	return 0;
}
