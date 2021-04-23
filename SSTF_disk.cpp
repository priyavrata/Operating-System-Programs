#include<bits/stdc++.h>
using namespace std;

void SSTF(vector<int> arr, int head){
    int n=arr.size();
    vector<int> seek_sequence;
    int seek_count=0;
    seek_sequence.push_back(head);
    int i=0;
    vector<bool> accessed(n,false);
    for(int k=0;k<n;k++){
        int diff=INT_MAX;
        int x;
        for(int t=0;t<n;t++){
            if(!accessed[t] && diff>(abs(arr[t]-head))){
                diff=abs(arr[t]-head);
                x=t;
                
            }
        }
        
        head=arr[x];
        accessed[x]=true;
        seek_count+=diff;
        seek_sequence.push_back(arr[x]);
    }
    cout<<"Total number of seek opeartions: "<<seek_count<<endl;
    cout<<"Seek sequence is:\n";
    for(int k=0;k<=n;k++){
        cout<<seek_sequence[k]<<endl;
    } 
}


int main()
{
    vector<int> arr;
    cout<<"Input requests (End with -1): ";
    int x;
    cin>>x;
    while(x!=-1){
        arr.push_back(x);
        cin>>x;
    }
    int head;
    cout<<"Input head: ";
    cin>>head;
    
    SSTF(arr, head);
  
    return 0;
}