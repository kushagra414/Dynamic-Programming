#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        //printf("This is N: %d\n",N);
        char character;
        int InStream[N],flag=0,charCount[26];
        memset(charCount,0,26*sizeof(int));
        for(int i=0;i<N;i++){
            scanf(" %c",&character);
            InStream[i]=character;
        }
        queue <int> q;
        //printf("%c ",InStream[0]);
        for(int i=0;i<N;i++){
            q.push(InStream[i]-97);
            //printf("q.front :%d\n",q.front());
            charCount[InStream[i]-97]++;
            //printf("charCount: %d\n",charCount[InStream[i]-97]);
            //printf("InStream[i]-97 : %d\n",InStream[i]-97);
            while(!q.empty()){
                    //printf("q.front():%d, charCount[i] ;%d\n",q.front(),charCount[q.front()]);
                if(charCount[q.front()]>1){
                    q.pop();
                }
                else{
                    printf("%c ",q.front()+97);
                    break;
                }
            }
            if(q.empty())
                printf("-1 ");
        }

        printf("\n");
    }
    return 0;
}
