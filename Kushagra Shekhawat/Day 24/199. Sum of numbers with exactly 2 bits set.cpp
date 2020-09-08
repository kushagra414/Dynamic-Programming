// C++ program to find sum of numbers 
// upto n whose 2 bits are set 
#include <bits/stdc++.h> 
using namespace std; 

// To calculate sum of numbers 
int findSum(int n) 
{ 
	int sum = 0; 

	// Find numbers whose 2 bits are set 
	for (int i = 1; (1 << i) < n; i++) { 
		for (int j = 0; j < i; j++) { 
			int num = (1 << i) + (1 << j); 

			// If number is greater then n 
			// we don't include this in sum 
			if (num <= n) 
				sum += num; 
		} 
	} 

	// Return sum of numbers 
	return sum; 
} 

// Driver program to test findSum() 
int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        cout<<findSum(x)<<endl;
    }
}