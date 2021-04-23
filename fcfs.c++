#include<bits/stdc++.h>
using namespace std;
void populateWait(int n, vector<pair<pair<int,int>,int>> ptimes, int* waiting_time){
    int scheduled_time[n];
    scheduled_time[0]=ptimes[0].first.first;
    waiting_time[0]=0;
    for(int k=1;k<n;k++){
        int t=scheduled_time[k-1]+ptimes[k-1].first.second;
        scheduled_time[k]=ptimes[k].first.first<t?t:ptimes[k].first.first;
        waiting_time[k]=scheduled_time[k]-ptimes[k].first.first;
    }
}

void populateTurnAround(int n,vector<pair<pair<int,int>,int>>ptimes,int* turnaround_time,int* waiting_time){
    for(int k=0;k<n;k++){
        turnaround_time[k]=waiting_time[k]+ptimes[k].first.second;
    }
}


void findAvgTime(int n, vector<pair<pair<int,int>,int>> ptimes){
    int waiting_time[n], turnaround_time[n];
    populateWait(n,ptimes,waiting_time);
    populateTurnAround(n,ptimes,turnaround_time,waiting_time);

    int total_wt=0, total_tat=0;
    for(int k=0;k<n;k++){
        total_wt=total_wt+waiting_time[k];
        total_tat=total_tat + turnaround_time[k];
        int compl_time=turnaround_time[k]+ptimes[k].first.first;
        cout<<"Process("<<ptimes[k].second<<"):\n";
        cout<<"Arrival time: "<<ptimes[k].first.first<<"\t Waiting time: "<<waiting_time[k];
        cout<<"\t Burst Time: "<<ptimes[k].first.second<<"\t Turn Around time: "<<turnaround_time[k];
        cout<<"\t Completion Time: "<<compl_time<<endl;
    }

    cout<<"Average Waiting Time: "<<1.0*total_wt/n<<endl;
    cout<<"Average TurnAround Time: "<<1.0*total_tat/n<<endl;
}

bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    return a.first.first<b.first.first;
}

int main(){
    int n;
    cout<<"Input number of processes: ";
    cin>>n;

    // vector of size n containing pairs of arrival time and burst time
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
    findAvgTime(n,ptimes);
    return 0;
}