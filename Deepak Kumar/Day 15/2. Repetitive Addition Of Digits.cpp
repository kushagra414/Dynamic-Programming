#include <iostream>
using namespace std;

int solution(int num){
    if(num==0){
        return 0;
    }
    int sum=0;
    while(num){
        if(num<10){
            return num;
        }
        else{
            num=num%10 + num/10;
        }
    }
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int num;
	    cin>>num;
	    cout<<solution(num)<<endl;
	}
	return 0;
}
