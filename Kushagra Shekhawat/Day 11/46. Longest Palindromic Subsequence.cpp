
int findLPS(string s);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    string s;
	    cin>>s;
	    cout<<findLPS(s)<<endl;
	}
	return 0;
}

int findLPS(string s){
    int length = s.length();
    int matrix[length][length]={0};
    for(int l=1;l<=length;l++){
        for(int row=0,col=l-1;row<length and col<length;row++,col++){
            if(l==1)
                matrix[row][col]=1;
            else{
                if(s[row]==s[col])
                    matrix[row][col] = 2+matrix[row+1][col-1];
                else{
                    matrix[row][col] = max(matrix[row+1][col],
                    matrix[row][col-1]);
                }
            }
        }
    }
    return matrix[0][length-1];
}