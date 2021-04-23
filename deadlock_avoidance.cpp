#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Input number of processes (n): ";cin>>n;
    cout<<"Input number of resources types (m): ";cin>>m;
    int available[m],max[n][m],allocation[n][m],need[n][m];
    int finish[n],ans[n],ind=0;
    int count=0;
    cout<<"Input currently available "<<m<<" instances:\n";
    for(int k=0;k<m;k++){
        cin>>available[k];
    }
    cout<<"Input maximum demand for "<<n<<" processes:\n";
    for(int i=0;i<n;i++){
        cout<<"Process("<<i+1<<"): \n";
        for(int j=0;j<m;j++){
            cin>>max[i][j];
        }
    }
    cout<<"Input currently allocated instances to "<<n<<" processes:\n";
    for(int i=0;i<n;i++){
        int f=0;
        cout<<"Process("<<i+1<<"): \n";
        for(int j=0;j<m;j++){
            cin>>allocation[i][j];
            need[i][j]=max[i][j]-allocation[i][j];
            if(allocation[i][j]!=0) f=1;
        }
        if(f){
            finish[i]=0;
        }
        else{
            finish[i]=1;
            count++;
        }
    }
    int p=0;
    while(count!=n){
        if(p==n){
            cout<<"DEADLOCK EXISTS NO SAFE SEQUENCE\n";break;
        }
        for(int i=0;i<n;i++){
            if(finish[i]==0){
                int flag=0;
                for(int j=0;j<m;j++){
                    if(need[i][j]>available[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    ans[ind++]=i;
                    for(int y=0;y<m;y++){
                        available[y]+=allocation[i][y];
                    }
                    finish[i]=1;
                    count++;
                }
            }
        }
        p++;
    }
    if(p<n){
        cout<<"Following is the SAFE Sequence\n";
        for(int i=0;i<n-1;i++)
            cout<<"P"<<ans[i]<<"->";
        cout<<"P"<<ans[n-1]<<endl;
    }
    return 0;
}