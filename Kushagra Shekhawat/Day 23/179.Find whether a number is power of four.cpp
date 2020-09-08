// { Driver Code Starts
#include<iostream>
using namespace std;

int isPowerOfFour(unsigned int n);

/*Driver program to test above function*/
int main()
{
int t,n;
cin>>t;
while(t--)
{
cin>>n;
if(isPowerOfFour(n))
	cout<<1<<endl;
else
	cout<<0<<endl;
}
//getchar();
}
// } Driver Code Ends


int isPowerOfFour(unsigned int n)
{
  //if a number is power of 4 then in its binary form it should have
  //only single bit as on.
  //eg:- 0100(4)
  if(__builtin_popcount(n)==1){
      // 4^n = 2^2n. so the position of that bit should be 2n
      if(__builtin_ctz(n)%2==0)
        return true;
  }
  return false;
}