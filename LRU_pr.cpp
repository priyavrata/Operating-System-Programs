#include<bits/stdc++.h>
using namespace std;

int pageFaults(vector<int> pages, int n, int capacity)
{
    unordered_set<int> s;
    unordered_map<int, int> indexes;
    int page_faults = 0;
    for (int i=0; i<n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i])==s.end()){
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int lru = INT_MAX, val;
                for (auto it=s.begin(); it!=s.end(); it++)
                {
                    if (indexes[*it] < lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
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
    cout<<"PAGE FAULTS IN LRU page replacement: "<<pageFaults(pages,n,capacity);
    return 0;
}