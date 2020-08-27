#include<bits/stdc++.h>
using namespace std;

void findNonRepeating(int arr[],int n);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    n = 2*n+2;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    findNonRepeating(arr,n);
	}
	return 0;
}

void findNonRepeating(int arr[],int n){
    int set_bit_no,xor_ = arr[0],x=0,y=0;
    for(int i=1;i<n;i++){
        xor_ = arr[i]^xor_;
    }
    //Find set_bit_no
    set_bit_no = xor_ & ~(xor_-1);
    //Divide the array in two sets where one set has set bit no and 
    //the other does not
    for(int i=0;i<n;i++){
        if(arr[i]&set_bit_no)
            x=x^arr[i];
        else
            y=y^arr[i];
    }
    cout<<min(x,y)<<" "<<max(x,y)<<endl;
}