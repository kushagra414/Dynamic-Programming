#include<bits/stdc++.h>
using namespace std;

struct Jobs{
    int id,deadline,profit;
};

bool Compare(Jobs job1, Jobs job2){
    if(job1.profit == job2.profit)
        return job1.deadline<job2.deadline;
    return job1.profit>job2.profit;
}

void JobSequencing(Jobs job[],int N);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    Jobs job[N];
	    for(int i=0;i<N;i++)
	        cin>>job[i].id>>job[i].deadline>>job[i].profit;
	    sort(job,job+N,Compare);
	    JobSequencing(job,N);
	}
	return 0;
}

void JobSequencing(Jobs job[],int N){
    int profit=0,numberOfJobs=0;
    int timeSlot[N];
    memset(timeSlot,-1,sizeof(int)*N);
    for(int i=0;i<N;i++){
        for(int deadline = min(N-1,job[i].deadline-1);deadline>=0;
        deadline--){
            if(timeSlot[deadline]==-1){
                timeSlot[deadline]=job[i].profit;
                break;
            }
        }
    }
    for(int i=0;i<N;i++)
        if(timeSlot[i] != -1){
            numberOfJobs++;
            profit+=timeSlot[i];
        }
    cout<<numberOfJobs<<" "<<profit<<endl;
}