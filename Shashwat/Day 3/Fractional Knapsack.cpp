#include <iostream>
#include<vector>
#include<algorithm>
#include <iomanip>
using namespace std;

struct inv{
    int we , val ;
    double wo ; 
    inv( int v , int w  ){ we = w ; val = v ; wo = val/(we*1.00) ; }
};

bool compare( struct inv* a , struct inv* b ){
    if( a->wo > b->wo  ) return true;
    else return false ;
}

vector< struct inv* > v ;

int main() {
	int t ;cin>>t ;
	while( t-- ){
	    v.clear() ;
	    int n , w , t1 ,t2 ; 
	    double max = 0.0  ;
	    cin>>n>>w;
	    for( int i=0 ; i<n ; i++ ){
	        cin>>t1>>t2 ;
	        v.push_back( new inv( t1 , t2 ) );
	    }
	    
	    sort( v.begin() , v.end() , compare );
/*	    
	    for( struct inv* x : v ){
	        cout<<x->we<<" "<<x->val<<" "<<x->wo<<endl;
	    }
*/  
        for( int i = 0 ; i < n; i++ ){
            
            if( w > v[i]->we   ){
                max += v[i]->val ;
                w-=v[i]->we ;
            }
            else if( v[i]->we >= w ){
                max +=( v[i]->wo * w ) ;
                break;
            }
 //           cout<<i<<" "<<v[i]->val<<" "<<v[i]->we<<" "<<max<<" "<<w<<endl;
	    }
	    std::cout<<std::fixed;
	    std::cout<<std::setprecision(2);
	    cout<<max<<endl;
	}
	return 0;
}
