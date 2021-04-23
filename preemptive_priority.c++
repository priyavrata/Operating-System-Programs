#include<bits/stdc++.h>
using namespace std;

void populateTurnAround(int n,vector<vector<int>>ptimes,int* turnaround_time,int* waiting_time){
    int ctime=ptimes[0][0];
    int k=1;
    priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>> pq; 
    vector<int> a;
    a.push_back(ptimes[0][0]);
    a.push_back(ptimes[0][1]);
    a.push_back(ptimes[0][3]);
    pq.push(make_pair(ptimes[0][2],a));

    while(!pq.empty()){
        pair<int,vector<int>> cur=pq.top();
        int bst=cur.second[1];

        // cout<<cur.first<<" ";
        // for(auto x:cur.second) cout<<x<<" ";
        // cout<<endl;
        pq.pop();
        int sub=0;
        int fl=0;
        for(k;k<n && ptimes[k][0]<=ctime+bst;k++){
            vector<int> a;
            a.push_back(ptimes[k][0]);
            a.push_back(ptimes[k][1]);
            a.push_back(ptimes[k][3]);
            // cout<<"** "<<ptimes[k][2]<<endl;
            pq.push(make_pair(ptimes[k][2],a));
            if(ptimes[k][2]<cur.first){
                sub=ptimes[k][0];
                k++;
                if(ptimes[k][0]<ctime+bst) fl=1;
                break;
            }   
        }
        if(!fl) {
            ctime+=bst;
            cur.second[1]=0;
            turnaround_time[cur.second[2]-1]=ctime-cur.second[0];
            waiting_time[cur.second[2]-1]=turnaround_time[cur.second[2]-1]-ptimes[cur.second[2]-1][1];
        }
        else {
            cur.second[1]-=(sub-cur.second[0]);
            ctime=sub;
            // cout<<"*** "<<cur.first<<endl;
            pq.push(cur);
        }
        // cout<<"SIZE: "<<pq.size() <<" "<< "TIME: "<<ctime<<endl;
            
    }
    // for(int k=1;k<n;k++){
    //     if(ptimes[k][0]<
    // }
    // for(int k=0;k<n;k++){
    //     turnaround_time[k]=waiting_time[k]+ptimes[k].first.second;
    // }
}


void findAvgTime(int n, vector<vector<int>> ptimes){
    int waiting_time[n], turnaround_time[n];
    // priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>, greater<pair<int,pair<int,int>> pq;   //remaining time and process number
    populateTurnAround(n,ptimes,turnaround_time,waiting_time);
    // populateWait(n,ptimes,waiting_time);

    int total_wt=0, total_tat=0;
    for(int k=0;k<n;k++){
        total_wt=total_wt+waiting_time[k];
        total_tat=total_tat + turnaround_time[k];
        int compl_time=turnaround_time[k]+ptimes[k][0];
        cout<<"Process("<<ptimes[k][3]<<"):\n";
        cout<<"Arrival time: "<<ptimes[k][0]<<"\t Waiting time: "<<waiting_time[k];
        cout<<"\t Burst Time: "<<ptimes[k][1]<<"\t Turn Around time: "<<turnaround_time[k];
        cout<<"\t Completion Time: "<<compl_time<<endl;
    }

    cout<<"Average Waiting Time: "<<1.0*total_wt/n<<endl;
    cout<<"Average TurnAround Time: "<<1.0*total_tat/n<<endl;
}

bool comp(vector<int> a, vector<int> b){
    if(a[0]==b[0]) return a[2]<b[2];
    return a[0]<b[0];
}

int main(){
    int n;
    cout<<"Input number of processes: ";
    cin>>n;

    // vector of size n containing pairs of arrival time and burst time
    vector<vector<int>> ptimes;

    cout<<"Input arrival time and burst time for "<<n<<" processes: \n";
    for(int k=0;k<n;k++){
        vector<int> a;
        cout<<k+1<<": \n";
        cout<<"ARRIVAL TIME: ";
        int arv,brst,pri;
        cin>>arv;
        a.push_back(arv);
        cout<<"BURST TIME: ";
        cin>>brst;
        a.push_back(brst);
        cout<<"PRIORITY: ";
        cin>>pri;
        a.push_back(pri);
        a.push_back(k+1);
        ptimes.push_back(a);
        // cout<<ptimes[0][0]<<"* ";
        for(auto x:ptimes[k]) cout<<x<<" ";
        cout<<endl;

    }  

    sort(ptimes.begin(),ptimes.end(), comp);
    findAvgTime(n,ptimes);
    return 0;
}