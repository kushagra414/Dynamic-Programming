using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int v,e,x,y;
	    cin>>v>>e;
	    vector<int>vertices[v];
	    for(int i=0;i<e;i++){
	        cin>>x>>y;
	        vertices[x].push_back(y);
	        vertices[y].push_back(x);
	    }
	    for(int i=0;i<v;i++){
	        cout<<i;
	        for(auto edge:vertices[i]){
	            cout<<"-> "<<edge;
	        }
	        cout<<endl;
	    }
	}
	return 0;
}