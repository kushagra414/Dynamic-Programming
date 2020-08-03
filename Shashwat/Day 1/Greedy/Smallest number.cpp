#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int check( int s , int d ){
    v.clear() ;
    if( s > 9*d ){
        return -1;
    }
    
    s = s-1 ;
    for( int i = d-1 ; i >= 1 ; i-- ){
        if( s > 9 ){
            v.push_back(9) ;
            s-=9 ;
        }
        else{
            v.push_back(s) ;
            s=0;
        }
    }
    v.push_back(s+1);
    return 0 ;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int s = 0, d = 0;
	    cin>>s>>d;
	    vector<int> ans;
	    if( check( s , d ) != -1 ) {
	        for( int i = v.size()-1 ; i >= 0 ; i--  ){
	            cout<<v[i];
	        }
	        cout<<endl;
	    }
	    else{
	        cout<<-1<<endl;
	    }
	}
	return 0;
}
