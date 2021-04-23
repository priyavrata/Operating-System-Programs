#include<bits/stdc++.h>
using namespace std;

void populateWaitTurnAround(int n, vector<pair<pair<int,int>,int>> ptimes, int* waiting_time, int* turnaround_time, priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> process, int it, vector<int>& order) {
    int scheduled_time[n];
    int ctime;
    waiting_time[0]=0;
    int k=1;
    while(!process.empty() && it<=n){
        pair<int,pair<int,int>> cp=process.top();   //current process
        process.pop();
        order.push_back(cp.second.second);
        if(cp.second.second==1){
            scheduled_time[0]=cp.second.first;
            ctime=scheduled_time[0]+cp.first;
            turnaround_time[0]=cp.first;
            for(it;it<n && ptimes[it].first.first<=ctime;it++){
                process.push(make_pair(ptimes[it].first.second,make_pair(ptimes[it].first.first,ptimes[it].second)));
            }
            continue;
        }
        else{
            scheduled_time[k]=ctime;
            ctime+=cp.first;
            for(it;it<n && ptimes[it].first.first<=ctime;it++){
                process.push(make_pair(ptimes[it].first.second,make_pair(ptimes[it].first.first,ptimes[it].second)));
            }
            waiting_time[k]=scheduled_time[k]-cp.second.first;
            turnaround_time[k]=waiting_time[k]+cp.first;
            k++;
        }
    }
    

}




void findAvgTime(int n, vector<pair<pair<int,int>,int>> ptimes, priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> process){
    int waiting_time[n], turnaround_time[n];
    vector<int> order;
    int it=1;
    populateWaitTurnAround(n,ptimes,waiting_time,turnaround_time,process,it,order);

    int total_wt=0, total_tat=0;
    for(int k=0;k<n;k++){

        total_wt=total_wt+waiting_time[k];
        total_tat=total_tat + turnaround_time[k];
        int compl_time=turnaround_time[k]+ptimes[order[k]-1].first.first;
        cout<<"Process("<<order[k]<<"):\n";
        cout<<"Arrival time: "<<ptimes[order[k]-1].first.first<<"\t Waiting time: "<<waiting_time[k];
        cout<<"\t Burst Time: "<<ptimes[order[k]-1].first.second<<"\t Turn Around time: "<<turnaround_time[k];
        cout<<"\t Completion Time: "<<compl_time<<endl;
    }

    cout<<"Average Waiting Time: "<<1.0*total_wt/n<<endl;
    cout<<"Average TurnAround Time: "<<1.0*total_tat/n<<endl;
}

bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    if(a.first.first==b.first.first) return a.first.second<b.first.second;
    return a.first.first<b.first.first;
}

int main(){
    int n;
    cout<<"Input number of processes: ";
    cin>>n;

    // vector of size n containing arrival time, burst time, and process number 
    vector<pair<pair<int,int>,int>> ptimes(n);

    cout<<"Input arrival time and burst time for "<<n<<" processes: \n";
    for(int k=0;k<n;k++){
        cout<<k+1<<": \n";
        cout<<"ARRIVAL TIME: ";
        int arv,brst;
        cin>>arv;
        cout<<"\t BURST TIME: ";
        cin>>brst;
        ptimes[k]=make_pair(make_pair(arv,brst),k+1);    
    }  

    sort(ptimes.begin(),ptimes.end(), comp);

    //priority queue (burst time, arrival time, process number) to maintain a min heap sorted on burst time 
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> process;
    process.push(make_pair(ptimes[0].first.second,make_pair(ptimes[0].first.first,1)));
    //Calculate avg waiting and turn around time
    findAvgTime(n,ptimes,process);
    return 0;
}