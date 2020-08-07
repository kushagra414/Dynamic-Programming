#include <iostream>
#include <vector>
using namespace std;

vector<int> v ;

void find(int temp){
    v.clear() ;
    while( temp!=0 ){
        if( temp > 9 ){
            v.push_back(9);
            temp -= 9 ;
        }
        else{
            v.push_back(temp);
            temp = 0 ;
        }
    }
}

int main() {
	int t ; cin>>t ;
	while(t--){
	    int n ; cin>>n;
	    string s = "";
	    find(n);
	    
	    for(int i=v.size()-1 ; i>=0 ;i--){
	        cout<<v[i];
	    }
	    
	    for(int i=0;i<n;i++){
	        s+='0' ;
	    }
	    cout<<s<<endl;
	}
	return 0;
}
