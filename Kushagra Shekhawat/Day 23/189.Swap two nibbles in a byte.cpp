#include<bits/stdc++.h>
using namespace std;
typedef unsigned char uc;

int leftCircularShift(uc n);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    //Simply do a left circular shift of 4 to swap the nibbles
	    cout<<leftCircularShift(n)<<endl;
	}
	return 0;
}

int leftCircularShift(uc n){
    return ((n<<4|n>>4)|255);
}