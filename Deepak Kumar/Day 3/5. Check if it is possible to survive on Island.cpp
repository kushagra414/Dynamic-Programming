#include <bits/stdc++.h>
using namespace std;

void solution(float survival_days,float food_bought,float food_required){
    if(food_bought<food_required){
        cout<<-1;
        return ;
    }
    else if(survival_days>6 && ((food_bought-food_required)*6 < food_required)){
        cout<<-1;
        return ;
    }
    else{
        float temp=(food_bought/food_required);
        //cout<<"temp  "<<temp<<endl;
        float ans=(survival_days/temp);
        //cout<<"ans  "<<ans<<endl;
        ans=ceil(ans);
        cout<<ans;
        return ;
    }
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    float survival_days,food_bought,food_required;
	    cin>>survival_days>>food_bought>>food_required;
	    solution(survival_days,food_bought,food_required);
	    cout<<endl;
	}
	return 0;
}
