#include <bits/stdc++.h>
using namespace std;

int PriorityChecker(char c){
    switch(c){
        case '^':
            return 3;
        case '-':
            return 1;
        case '+':
            return 1;
        case '/':
            return 2;
        case '*':
            return 2;
        case '(':
            return 4;
        case ')':
            return 5;
        default :
            return 0;
    }
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    char Expression[1000];
	    int len,priority;
	    scanf("%s",Expression);
	    len = strlen(Expression);
	    
	    stack <char> s;
	    for(int i=0;i<len;i++){
	        priority = PriorityChecker(Expression[i]);
	        if(priority==0)
	            printf("%c",Expression[i]);
	        else if(priority==5){
	            while(s.top()!='('){
	                printf("%c",s.top());
	                s.pop();
	            }
	            s.pop();
	        }
	        else{
	            //if(!s.empty())
	                //printf("\nPriority of %c is %d and s.top() : %c\n",Expression[i],priority,s.top());
    	            while(!s.empty()&&priority<=PriorityChecker(s.top())&&s.top()!='('){
    	                printf("%c",s.top());
    	                s.pop();
    	            }
	            s.push(Expression[i]);
	        }
	    }
	    while(!s.empty()){
	        printf("%c",s.top());
	        s.pop();
	    }
	    printf("\n");
	}
	return 0;
}