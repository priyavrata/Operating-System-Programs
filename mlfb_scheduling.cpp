#include <bits/stdc++.h>
using namespace std;

struct process
{
    char id;
    int arr_time, burst_time, wait_time, ta_time, remaining, comp_time;
} Q1[10], Q2[10], Q3[10];

int n;
void sortByArrival()
{
    struct process temp;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (Q1[i].arr_time > Q1[j].arr_time)
            {
                temp = Q1[i];
                Q1[i] = Q1[j];
                Q1[j] = temp;
            }
        }
    }
}

int main()
{
    int i, j, k = 0, r = 0, time = 0, tq1 = 5, tq2 = 8, flag = 0;
    cout<<"Enter no of processes:";
    cin>>n;
    for (i = 0; i < n; i++)
    {
        Q1[i].id = i+1;
        cout<<"Enter Arrival and Burst Time of process "<<i+1<<": ";
        cin>>Q1[i].arr_time>>Q1[i].burst_time;
        Q1[i].remaining = Q1[i].burst_time;
    }
    sortByArrival();
    time = Q1[0].arr_time;
    cout<<"Process in first queue following RR with Time Quantum=5\n";
    cout<<"\nProcess\t\tRT\t\tWT\t\tTAT\t\t\n";
    for (i = 0; i < n; i++)
    {

        if (Q1[i].remaining <= tq1)
        {

            time += Q1[i].remaining;
            Q1[i].remaining = 0;
            Q1[i].wait_time = time - Q1[i].arr_time - Q1[i].burst_time;
            Q1[i].ta_time = time - Q1[i].arr_time;
            printf("\n%d\t\t%d\t\t%d\t\t%d", Q1[i].id, Q1[i].burst_time, Q1[i].wait_time, Q1[i].ta_time);
        }
        else
        {
            Q2[k].wait_time = time;
            time += tq1;
            Q1[i].remaining -= tq1;
            Q2[k].burst_time = Q1[i].remaining;
            Q2[k].arr_time=Q1[i].arr_time;
            Q2[k].remaining = Q2[k].burst_time;
            Q2[k].id = Q1[i].id;
            k = k + 1;
            flag = 1;
        }
    }
    if (flag == 1)
    {
        cout<<"\nProcess in second queue following RR with Time Quantum=8";
        cout<<"\nProcess\t\tRT\t\tWT\t\tTAT\t\t\n";
    }
    for (i = 0; i < k; i++)
    {
        if (Q2[i].remaining <= tq2)
        {
            time += Q2[i].remaining;
            Q2[i].remaining = 0;
            Q2[i].wait_time = time - tq1 - Q2[i].burst_time;
            Q2[i].ta_time = time - Q2[i].arr_time;
            printf("\n%d\t\t%d\t\t%d\t\t%d", Q2[i].id, Q2[i].burst_time, Q2[i].wait_time, Q2[i].ta_time);
        }
        else
        {
            Q3[r].arr_time = time;
            time += tq2;
            Q2[i].remaining -= tq2;
            Q3[r].burst_time = Q2[i].remaining;
            Q3[r].remaining = Q3[r].burst_time;
            Q3[r].id = Q2[i].id;
            r = r + 1;
            flag = 2;
        }
    }

    {
        if (flag == 2)
            cout<<"\nProcess in third queue following FCFS ";
    }
    for (i = 0; i < r ; i++)
    {
        if (i == 0)
            Q3[i].comp_time = Q3[i].burst_time + time - tq1 - tq2;
        else
            Q3[i].comp_time = Q3[i - 1].comp_time + Q3[i].burst_time;
    }

    for (i = 0; i < r; i++)
    {
        Q3[i].ta_time = Q3[i].comp_time;
        Q3[i].wait_time = Q3[i].ta_time - Q3[i].burst_time;
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t", Q3[i].id, Q3[i].burst_time, Q3[i].wait_time, Q3[i].ta_time);
    }
    printf("\n");
}
