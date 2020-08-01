#include <iostream>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        int ans=A[0];
        for(int i=0;i<N;i++){
            if(A[i]<ans){
                ans=A[i];
            }
        }
        cout<<ans<<endl;
    }
	return 0;
