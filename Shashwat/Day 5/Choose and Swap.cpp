#include <bits/stdc++.h>
using namespace std;

int main() {
	int t ; cin>>t ;
	while(t--){
	    string s; cin>>s ;
	    int a[26] ; memset(a , -1 , sizeof(int)*26) ;
	   // for( int i =0 ; i<25;i++ ){
	   //      cout<<a[i]<<" ";
	   //  }
	    for(int i = 0; i < s.length() ; i++ ){
	            if( a[s[i]-97] == -1 ){
	                a[s[i]-97] = i ;
	            }
	        }
	   //  for( int i =0 ; i<25;i++ ){
	   //      cout<<a[i]<<" ";
	   //  }   
	    int i = 0 , j = 25 ; int f =-1 , e =-1 ;
	    for( int  i = 0 ; i<s.length() ; i++){
	            for(int j = 0 ; j<s[i]-97 ; j++ ){
//	                cout<<i<<" "<<s[i]-97<<" "<<j<<" "<<a[j]<<endl;
	                if( a[j] != -1 &&  a[j] > a[s[i]-97] ){
	                    f = j ;
	                    e = s[i]-97 ;
	                    break;
	                }
	            }
	            if( f!=-1  ) break;
	    }
//	    cout<<f<<" "<<e<<endl;
	    for( int i = 0 ; i < s.length() ; i++ ){
	        if( s[i]-97 == f ){
	            s[i] = e+97 ;
	            continue;
	        }
	        
	        if( s[i]-97 == e ){
	            s[i] = f+97 ;
	        }
	    }
	    cout<<s<<endl;
	}
	return 0;
}
