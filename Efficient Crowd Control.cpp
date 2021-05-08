#include<bits/stdc++.h>
using namespace std;

void printQueue(queue <int> q, vector <int> number_of_tickets)
{
    if(q.empty())
        cout<<-1;
    else
    {
        while(!q.empty())
        {
            cout<<q.front()+1<<" ";
            q.pop();
        }
    }

    cout<<endl;
}

int main()
{
    int n,i;
    cin>>n;
       
    vector <int> number_of_tickets(n,0),arrival_times(n,0);

    for(i=0;i<n;i++)
        cin>>number_of_tickets[i];
    
    for(i=0;i<n;i++)
        cin>>arrival_times[i];
    
    vector <int> max_tickets(3,0);
    
    for(i=0;i<3;i++)
        cin>>max_tickets[i];

    int q;
    cin>>q;

    vector <int> print_times(q,0);

    for(i=0;i<q;i++)
        cin>>print_times[i];
    
    int MAX_TIME = print_times[q-1] + 1;
    int time = 0;

    int currPerson = 0;
    int currArrivalTime = 0;
    int currPrintTime = 0;

    queue <int> q1,q2,q3;

    while(time < MAX_TIME)
    {
        while(currArrivalTime < n && arrival_times[currArrivalTime] == time)
        {
            q1.push(currPerson);
            // cout<<"Pushing "<<currPerson<<endl;
            currPerson++;
            currArrivalTime++;
        }

        int f1=0,f2=0,f3=0;
        int temp1,temp2,temp3;

        if(!q1.empty())
        {
            temp1 = q1.front();
            q1.pop();
            number_of_tickets[temp1] = max(0,number_of_tickets[temp1] - max_tickets[0]);
            if (number_of_tickets[temp1] > 0)
                f1=1;
        }

        if(!q2.empty())
        {
            temp2 = q2.front();
            q2.pop();
            number_of_tickets[temp2] = max(0,number_of_tickets[temp2] - max_tickets[1]);
            if (number_of_tickets[temp2] > 0)
                f2=1;
        }

        if(!q3.empty())
        {
            temp3 = q3.front();
            q3.pop();
            number_of_tickets[temp3] = max(0,number_of_tickets[temp3] - max_tickets[2]);
            if (number_of_tickets[temp3] > 0)
                f3=1;
        }

        if(f1==1)
            q2.push(temp1);
        
        if(f2==1)
            q3.push(temp2);
        
        if(f3==1)
            q1.push(temp3);

        while(currPrintTime<q && time == print_times[currPrintTime])
        {
            // cout<<"Time : "<<time<<endl;
            // cout<<"Queue1:";
            printQueue(q1,number_of_tickets);
            // cout<<"Queue2:";
            printQueue(q2,number_of_tickets);  
            // cout<<"Queue3:";          
            printQueue(q3,number_of_tickets);

            currPrintTime ++;
        }
        
        time++;
    }
}