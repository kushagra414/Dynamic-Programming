class Solution {
public:
    int numSteps(string s) {
        int steps=0,index;
        while(s.length()>1){
            index = s.length()-1;
            if(((s[index]-'0') & 1) == 0){
                s.erase(s.end() - 1);
            }else{
                while(index >= 0 and s[index] != '0'){
                    s[index--] = '0';
                }
                if(index<0)
                    s.insert(0,"0");
                else
                    s[index] = '1';
            }
            steps++;
        }
        return steps;
    }
};