#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Input number of blocks (n):";
    cin>>n;
    vector<int> blockSize(n);
    cout<<"Input "<<n<<" Memory Blocks: "<<endl;;
    for(int k=0;k<n;k++){
        cout<<"Block "<<k+1<<": ";
        cin>>blockSize[k];
    }

    int p;
    cout<<"Input number of processes (p): ";
    cin>>p;
    vector<int> processSize(p);
    cout<<"Input process sizes: "<<endl;
    for(int k=0;k<p;k++){
        cout<<"Process "<<k+1<<": ";
        cin>>processSize[k];
    }

    vector<int> allocation(n,-1);
    for(int i=0;i<p;i++){
        int idx=-1;
        for(int j=0;j<n;j++){
            if(blockSize[j]>=processSize[i]){
                if(idx==-1)
                    idx=j;
                else if(blockSize[idx] > blockSize[j])
                    idx=j;
            }
        }
        if(idx!=-1){
            allocation[i]=idx;
            blockSize[idx]-=processSize[i];
        }
    }
    
    cout<<"\n Process No. \t Process Size \t Block no. \n"<<endl;
    for(int i=0;i<p;i++){
        cout<<" "<<i+1<<"\t\t"<<processSize[i]<<"\t\t";
        if (allocation[i]!=-1)
            cout<<allocation[i]+1;
        else    
            cout<<"Not Allocation";
        cout<<endl;
    }
    return 0;
}