#include<bits/stdc++.h>
#define bits 16
using namespace std;
typedef unsigned short int usi;

usi leftCircularShift(usi n,usi d);
usi rightCircularShift(usi n,usi d);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    usi n,d;
	    cin>>n>>d;
	    d%=bits;
	    cout<<leftCircularShift(n,d)<<endl;
	    cout<<rightCircularShift(n,d)<<endl;
	}
	return 0;
}

usi leftCircularShift(usi n,usi d){
    return (n<<d | n>>(bits-d));
}
usi rightCircularShift(usi n,usi d){
    return (n>>d | n<<(bits-d));
}