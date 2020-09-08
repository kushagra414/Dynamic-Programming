class Solution {
public:
    string toHex(int num) {
        if(num==0)
            return "0";
        string hexaDecimal;
        int temp,zero='0',A = 'a';
        u_int n = num;
        while(n){
            temp = n % 16;
            if(temp < 10){
                hexaDecimal += zero + temp;
            }else{
                hexaDecimal += A + temp - 10;
            }
            n /= 16;
        }
        reverse(hexaDecimal.begin(),hexaDecimal.end());
        return hexaDecimal;
    }
};