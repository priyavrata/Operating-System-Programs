#include<bits/stdc++.h>
using namespace std;
int pageFaults(vector<int> pages, int n, int capacity){
    unordered_map<int,bool> isPresent;
    queue<int> idx;
    int page_faults=0;
    for(int k=0;k<n;k++){
        if(isPresent.size()<capacity){
            if(isPresent.find(pages[k])==isPresent.end()){
                isPresent[pages[k]]=true;
                page_faults++;
                idx.push(pages[k]);
            }
        }
        else{
            if(isPresent.find(pages[k])==isPresent.end()){
                int val=idx.front();
                idx.pop();
                isPresent.erase(val);
                isPresent[pages[k]]=true;
                idx.push(pages[k]);
                page_faults++;
            }
        }
    }
    return page_faults;
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
    cout<<"PAGE FAULTS IN FIFO page replacement: "<<pageFaults(pages,n,capacity);
    return 0;
}