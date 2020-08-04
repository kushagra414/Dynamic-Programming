#include <iostream>
using namespace std;

int main() {
    int t; cin>>t;
    while( t-- ){
        int n ,temp , c=0 ; cin>>n;
        temp = n;
        
        while( temp!=0 ){
            if( temp%2==0 && temp-temp/2 != 0 ){
                c++ ;
                temp /= 2 ;
            }
            else{
                temp--;
                c++;
            }
        }
        cout<<c<<endl ;
    }
	return 0;
}
