#include<bits/stdc++.h>
using namespace std;

int MinSurvivalKit(int surviveDays,int maxFoodBuy,int FoodEachDay);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int S,N,M;
	    cin>>S>>N>>M;
	    cout<<MinSurvivalKit(S,N,M)<<endl;
	}
	return 0;
}

int MinSurvivalKit(int surviveDays,int maxFoodBuy,int FoodEachDay){
    int TotalFood = surviveDays*FoodEachDay;
    int BuyFoodDays = ceil(TotalFood/(maxFoodBuy*1.00));
    if(FoodEachDay>=maxFoodBuy or surviveDays>6 and(maxFoodBuy - FoodEachDay)*6<FoodEachDay)
        return -1;
    return BuyFoodDays;
}