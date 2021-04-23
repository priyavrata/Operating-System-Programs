#include<bits/stdc++.h>
using namespace std;

void LOOK (vector<int> arr, int head){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int idx=upper_bound(arr.begin(),arr.end(),head)-arr.begin();
    int seek_count=0;
    vector<int> seek_sequence;
    seek_sequence.push_back(head);
    for(int k=idx;k<arr.size();k++){
        int diff=abs(head-arr[k]);
        head=arr[k];
        seek_sequence.push_back(arr[k]);
        seek_count+=diff;
    }
    for(int k=idx-1;k>=0;k--){
        seek_count+=abs(head-arr[k]);
        seek_sequence.push_back(arr[k]);
        head=arr[k];
    }

    cout<<"Total number of seek operations: "<<seek_count<<endl;
    cout<<"Seek Sequence is:\n";
    for(int k=0;k<seek_sequence.size();k++){
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
    
    LOOK(arr, head);
  
    return 0;
}
   