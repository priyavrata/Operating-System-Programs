#include<bits/stdc++.h>
using namespace std;

int pageFaults(vector<int> pages, int n, int capacity){
    unordered_map<int,int> freq, idx;
    int pf=0;
    for(int k=0;k<n;k++){
        if(idx.size()<capacity){
            if(idx.find(pages[k])!=idx.end())
                freq[pages[k]]++;
            else{
                freq[pages[k]]++;
                idx[pages[k]]=k;
                pf++;
            }
        }
        else{
            if(idx.find(pages[k])!=idx.end()) {
                freq[pages[k]]++;
            }
            else{
                int mni=INT_MAX, mnf=INT_MAX, el;
                for(auto x:idx){
                    if(mnf>=freq[x.first] && mni>x.second){
                        mnf=freq[x.first];
                        mni=x.second;
                        el=x.first;
                    }
                }
                freq.erase(el);
                idx.erase(el);
                idx[pages[k]]=k;
                freq[pages[k]]++;
                pf++;
            }
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
    cout<<"PAGE FAULTS IN LFU page replacement: "<<pageFaults(pages,n,capacity);
    return 0;
}