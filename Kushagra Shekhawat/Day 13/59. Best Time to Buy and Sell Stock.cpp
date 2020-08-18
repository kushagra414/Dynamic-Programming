class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int maxProfit=0,buy=prices[0],sell;
        for(int i=1;i<prices.size();i++){
            if(buy>=prices[i]){
                buy = prices[i];
            }else{
                sell = prices[i];
                if(sell-buy>maxProfit)
                    maxProfit = sell-buy;
            }
        }
        return maxProfit;
    }
};