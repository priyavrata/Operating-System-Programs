#include<bits/stdc++.h>
using namespace std;
int pageFaults(vector<int> pages, int n, int capacity){
    vector<bool> sc(capacity,false);
    vector<int> arr(capacity);
    int idx=0,flag=1,pf=0;
    for(int k=0;k<n;k++){
        flag=1;
        for(int i=0;i<capacity && flag;i++){
            if(arr[i]==pages[k]){
                sc[i]=true;
                flag=0;
            }
        }
        if(flag){
            while(flag){
                if(!sc[idx]){
                    arr[idx]=pages[k];
                    idx=(idx+1)%capacity;
                    flag=0;
                    continue;
                }
                sc[idx]=false;
                idx=(idx+1)%capacity;
            }
            pf++;
        }
    }
    return pf;
}

int main(){
    int capacity;
    cout<<"Input number of pages that memory can hold (capacity): ";
    cin>>capacity;
    vector<int> pages;
    cout<<"Input pages (Input last page as -1): "<<endl;
    int x;
    int n=0;
    cin>>x;
    while(x!=-1){
        n++;
        pages.push_back(x);
        cin>>x;
    }
    cout<<"PAGE FAULTS IN Second chance page replacement: "<<pageFaults(pages,n,capacity);
    return 0;
}