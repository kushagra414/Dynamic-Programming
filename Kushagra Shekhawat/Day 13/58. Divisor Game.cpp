class Solution {
public:
    bool divisorGame(int N) {
        bool aliceWins = false;
        for(int i=1;i<N;i++){
            if(N%i==0){
                N-=i;
                aliceWins = !aliceWins;
                i=0;
            }
        }
        return aliceWins;
    }
};