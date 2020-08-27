// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5

void solution(vector<string>& ans,int m[MAX][MAX],int n,string str,int x,int y){
    if(x<0 || x>=n || y<0 || y>=n || m[x][y]!=1){
        return ;
    }
    if(x==n-1 && y==n-1){
        ans.push_back(str);
        return;
    }
    m[x][y]=0;
    solution(ans,m,n,str+'D',x+1,y);
    solution(ans,m,n,str+'L',x,y-1);
    solution(ans,m,n,str+'R',x,y+1);
    solution(ans,m,n,str+'U',x-1,y);
    m[x][y]=1;
}

vector<string> printPath(int m[MAX][MAX], int n) {
    vector<string> ans;
    string str="";
    int x=0,y=0;
    solution(ans,m,n,str,x,y);
    return ans;
}
