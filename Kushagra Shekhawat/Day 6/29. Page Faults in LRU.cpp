#include<bits/stdc++.h>
using namespace std;

int PageFaults(int pages[],int N,int C);
void pushPageBack(deque<int> &dq,
unordered_map<int,int> &ump,int page);
void RemovePageAndAddNew(deque<int> &dq,
unordered_map<int,int> &ump,int page);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,C;
	    cin>>N;
	    int pages[N];
	    for(int i=0;i<N;i++)
	        cin>>pages[i];
	    cin>>C;
	    cout<<PageFaults(pages,N,C)<<endl;
	}
	return 0;
}

int PageFaults(int pages[],int N,int C){
    deque<int>dq;
    unordered_map<int,int>ump;
    int capacity = C,i=0;
    int pageFault=0;
    for(i=0;capacity>0 and i<N;i++){
        if(ump.find(pages[i])==ump.end()){
            dq.push_back(pages[i]);
            ump[pages[i]] = dq.size();
            pageFault++;
            capacity--;
        }else{
            pushPageBack(dq,ump,pages[i]);
        }
    }
    //cout<<"pageFault:"<<pageFault<<endl;
    for(;i<N;i++){
        if(ump.find(pages[i])==ump.end()){
            RemovePageAndAddNew(dq,ump,pages[i]);
            pageFault++;
            //cout<<"RemovePageAndAddNew :"<<dq.front()<<" and "<<pages[i]<<endl;
        }else{
            //cout<<"PushPageBack, pageNo:"<<pages[i]<<endl;
            pushPageBack(dq,ump,pages[i]);
        }
    }
    return pageFault;
}

void pushPageBack(deque<int> &dq,
unordered_map<int,int> &ump,int page){
    int position = ump[page];
    for(auto it = dq.begin();it!=dq.end();++it)
        if(--position == 0){
            auto tempit = it;
            while(tempit!=dq.end()){
                ump[*tempit] = ump[*tempit]-1;
                ++tempit;
            }
            dq.erase(it);
            ump.erase(page);
            break;
        }
    dq.push_back(page);
    ump[page]=dq.size();
}

void RemovePageAndAddNew(deque<int> &dq,
unordered_map<int,int> &ump,int page){
    int removePage = dq.front();
    for(auto it=dq.begin();it!=dq.end();++it){
        ump[*it] = ump[*it]-1;
    }
    dq.pop_front();
    ump.erase(removePage);
    dq.push_back(page);
    ump[page] = dq.size();
}