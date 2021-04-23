#include <bits/stdc++.h>
using namespace std;
int pageFaults(vector<pair<int,int>> pages, int n, int capacity)
{
    vector<bool> sc(capacity, false);
    vector<pair<int,int>> arr(capacity);
    int idx = 0, flag = 1, pf = 0;
    for (int k = 0; k < n; k++)
    {
        flag = 1;
        for (int i = 0; i < arr.size() && flag; i++)
        {
            if (arr[i].first == pages[k].first)
            {
                sc[i] = true;
                arr[i].second=pages[k].second;
                flag = 0;
            }
        }
        if (flag)
        {
            int st_id=idx;
            int mn_idx=idx;
            int mn_sc=sc[idx];
            int mn_mod=arr[idx].second;
            idx=(idx+1)%capacity;
            while(idx!=st_id ){
                if(sc[idx]<mn_sc){
                    mn_sc=sc[idx];
                    mn_mod=arr[idx].second;
                    mn_idx=idx;
                }
                else if(sc[idx]==mn_sc){
                    if(arr[idx].second<mn_mod){
                        mn_sc=sc[idx];
                        mn_mod=arr[idx].second;
                        mn_idx=idx;
                    }
                }
                idx=(idx+1)%capacity;
            }
            int t;
            if(mn_sc==1){
                for(t=0;t<capacity;t++){
                    if(sc[t]) sc[t]=false;
                }
                arr[mn_idx]=pages[k];
                idx=(mn_idx+1)%capacity;
            }
            else{
                if(mn_idx<st_id) mn_idx+=capacity;
                for(t=st_id;t<mn_idx;t++){
                    if(sc[t%capacity]) sc[t%capacity]=false;
                }
                arr[t]=pages[k];
                idx=(t+1)%capacity;
            }

            pf++;
        }
    }
    return pf;
}

int main()
{
    int capacity;
    cout << "Input number of pages that memory can hold (capacity): ";
    cin >> capacity;
    vector<pair<int, int>> pages;
    cout << "Input pages and their Modify Bit (Input last page as -1): " << endl;
    int x, y;
    int n = 0;
    cin >> x;
    while (x != -1)
    {
        cin >> y;
        n++;
        pages.push_back(make_pair(x,y));
        cin >> x;
    }

    cout << "PAGE FAULTS IN Second chance page replacement: " << pageFaults(pages, n, capacity);

    return 0;
}