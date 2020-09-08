// { Driver Code Starts
#include<stdio.h>
 

int countValues (int n);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		
		printf("%d\n",countValues(n));
	}
}// } Driver Code Ends


/*You are required to complete this method */
int countValues (int n)
{
    int unsetBits=0;
    while(n){
        if(!(n & 1))
            unsetBits++;
        n = n>>1;
    }
    return 1<<unsetBits;
}
 