#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int t ; cin>>t ;
	while(t--){
	    int n , m ; cin>>n>>m;
	    vector<vector<int>> a ;
	    for(int i=0;i<n;i++){
	        a.push_back({}) ;
	        for(int j=0;j<m;j++){
	            int temp ;
	            cin>>temp ;
	            a[i].push_back(temp) ;
	        }
	    }
	    for(int i=0;i<n;i++){
	        sort( a[i].begin() , a[i].end() );
	    }
/*	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cout<<a[i][j]<<" ";
	        }
	        cout<<endl;
	    }
        cout<<endl;
*/      int sum = a[n-1][m-1] , last= sum , f=0 ;
        for( int i = n-2 ; i>=0 ;i--){
            for( int j = m-1 ; j>=0 ;j-- ){
                if( a[i][j] < last ){
//                    cout<<"A="<<a[i][j]<<" "<<last<<endl ;
                    sum+=a[i][j] ;
                    last = a[i][j] ;
                    f = 1 ;
                    break;
                }
            }
            if( f==1 ){
                f = 0 ;
            }
            else{
                sum = 0 ;
                break;
            }
        }
        cout<<sum<<endl;
	}
	return 0;
}
