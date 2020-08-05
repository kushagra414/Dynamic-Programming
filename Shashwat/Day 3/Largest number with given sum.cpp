#include <iostream>
#include<vector>
using namespace std;

vector<int> v ;

int check(int d , int s){
    v.clear() ;
     if( s > d*9 ){
        return -1 ;
    }
    
    for( int i=1; i<=d ; i++ ){
        if( s > 9 ){
            v.push_back(9) ;
            s-=9 ;
        }
        else{
            v.push_back(s);
            s = 0 ;
        }
    }
    return 0 ;
}

int main(){
	int t; cin>>t; 
	while(t--){
	    int d,s; cin>>d>>s;
	    if( check(d,s) !=-1 ){
	        for(int x:v){
	            cout<<x;
	        }
	    }
	    else{
	        cout<<-1;
	    }
	    cout<<endl;
	}
	return 0;
}
