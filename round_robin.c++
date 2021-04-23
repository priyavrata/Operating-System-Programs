#include<bits/stdc++.h>
using namespace std;

void populateWait(int n,vector<pair<pair<int,int>,int>>ptimes,int* turnaround_time,int* waiting_time){
    for(int k=0;k<n;k++){
        waiting_time[k]=turnaround_time[k]-ptimes[k].first.second;
    }
}

void populateTurnaround(vector<pair<pair<int,int>,int>>ptimes,queue<pair<pair<int,int>,int>> q, int* turnaround_time,int tq, int* compl_time){
    int cmpl=ptimes[0].first.first;
    while(!q.empty()){
        pair<pair<int,int>,int> cur=q.front();
        q.pop();
        // cout<<cur.first.first<<" "<<cur.first.second<<" "<<cur.second<<endl;
        if(cur.first.second>tq){
            cmpl+=tq;
            cur.first.second-=tq;
            q.push(cur);
        }
        else if(cur.first.second<=tq){
            cmpl+=cur.first.second;
            compl_time[cur.second-1]=cmpl;
            turnaround_time[cur.second-1]=cmpl-cur.first.first;
        }
    }
}



void findAvgTime(int n, vector<pair<pair<int,int>,int>> ptimes, int tq){
    int waiting_time[n], turnaround_time[n], completion_time[n];
    queue<pair<pair<int,int>,int>> q;
    for(int k=0;k<n;k++){
        q.push(ptimes[k]);
    }

    populateTurnaround(ptimes,q,turnaround_time,tq,completion_time);
    populateWait(n,ptimes,turnaround_time,waiting_time);

    int total_wt=0, total_tat=0;
    for(int k=0;k<n;k++){
        total_wt=total_wt+waiting_time[k];
        total_tat=total_tat + turnaround_time[k];
        cout<<"Process("<<ptimes[k].second<<"):\n";
        cout<<"Arrival time: "<<ptimes[k].first.first<<"\t Waiting time: "<<waiting_time[k];
        cout<<"\t Burst Time: "<<ptimes[k].first.second<<"\t Turn Around time: "<<turnaround_time[k];
        cout<<"\t Completion Time: "<<completion_time[k]<<endl;
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

    int tq;
    cout<<"Input Time quantum: ";
    cin>>tq;

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
    findAvgTime(n,ptimes,tq);
    return 0;
}