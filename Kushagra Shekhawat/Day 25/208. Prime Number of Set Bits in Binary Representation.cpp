class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int count=0;
        vector<bool>isPrime = findAllPrimeTill32();
        for(int i=L;i<=R;i++)
            if(isPrime[__builtin_popcount(i)])
                count++;
        return count;
    }
    vector<bool> findAllPrimeTill32(){
        vector<bool>isPrime(33,true);
        isPrime[0]=false,isPrime[1]=false;
        for(int i=2;i*i<=32;i++){
            if(isPrime[i]==true){
                for(int j=i*i;j<=32;j+=i)
                    isPrime[j] = false;
            }
        }
        return isPrime;
    }
};