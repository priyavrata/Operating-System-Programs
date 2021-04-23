#include <bits/stdc++.h>
using namespace std;
  
void FCFS(vector<int> arr, int head)
{
    int n=arr.size();
    int seek_count = 0;
    int distance, cur_track;
  
    for (int i = 0; i < n; i++) {
        cur_track = arr[i];
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
  
    cout << "Total number of seek operations = "
         << seek_count << endl;
  
    cout << "Seek Sequence is" << endl;
  
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
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
  
    FCFS(arr, head);
  
    return 0;
}