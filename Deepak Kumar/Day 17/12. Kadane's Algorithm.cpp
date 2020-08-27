#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,i=0,min;
        cin>>N;
        int arr[N];
        for(i=0;i<N;i++){
            cin>>arr[i];
        }
        min=arr[0];
        for(i=1;i<N;i++){
            if(min<arr[i]){
                min=arr[i];
            }
        }
        int temp_max=min, max=0;
        for(i=0;i<N;i++){
            max=max+arr[i];
            if(max<0){
                max=0;
            }
            else if(temp_max<max){
                temp_max=max;
            }
        }
        cout<<temp_max<<endl;
    }
	return 0;
}
