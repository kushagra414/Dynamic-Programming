using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str;
	    int len = 0,temp,minLen=INT_MAX,count=0;
	    cin>>str;
	    int Strlen = str.length();
	    int Patlen = 0;
	    int strAscii[256]={0},patAscii[256]={0};
	    for(int i=0;i<Strlen;i++)
	        if(patAscii[str[i]]==0){
	            patAscii[str[i]]++;
	            Patlen++;
	        }
	    for(int i=0,j=0;i<Strlen;i++){
	        strAscii[str[i]]++;
	        if(patAscii[str[i]]!=0 and strAscii[str[i]]<=patAscii[str[i]])
	            count++;
	            
	        if(count==Patlen){
	            while(strAscii[str[j]]>patAscii[str[j]] or patAscii[str[j]]==0){
	                
	                if(strAscii[str[j]]>patAscii[str[j]])
	                    strAscii[str[j]]--;
	                j++;
	            }
    	        temp = i-j+1;
    	        if(temp<minLen)
    	            minLen = temp;
	         }
	    }
	    cout<<minLen<<endl;
	}
	return 0;
}