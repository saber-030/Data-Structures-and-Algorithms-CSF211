#include<bits/stdc++.h>
using namespace std;
#define ll long long

int arr[1000002];

int main()
{
    int n,num_query;
    cin>>num_query;
    
    while (num_query--)
    {
        memset(arr,0,sizeof(arr));
        cin>>n;
        if(n == 0)
        {
            cout<<-1<<endl;
            continue;
        }
        queue<int> q;
        q.push(n);
        arr[n] = 0;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            if(front == 1){           //if front==1, that means we have reached 1 from N
                break;                
            } 

//if front !=1, we have 2 choices ...

    //1. To convert N-> N-1 , so we push N-1 to Queue

            if(arr[front-1] == 0)      
            {
                arr[front-1] = arr[front]+1;
                q.push(front-1);
            }
    //2. If N is of form N=p*q, push max(p,q) or p+q depending on parity of p and q 
            for(int i = 2; i*i <= front; i++)              //finding factors of N i.e p in our case
            {
                if(front%i == 0)
                {
                    if((i&1)==((front/i)&1)){             //if both p and q have same parity
                        int fac = max(i, front/i);
                        if(arr[fac] == 0)                 //if fac hasnot been discovered until now, it means we have reached fac in minimum number of steps = arr[front] + 1 
                        {
                            arr[fac] = arr[front]+1;
                            q.push(fac);                  //push fac to queue
                        }
                        else{                             //if fac has already been visited , it means we can reach fac in <= arr[front]+1 steps
                        	continue;
                        }
                    }
                    else{                                 //if both p and q have different parity
                        int fac = (i+(front/i));
                        if(arr[fac] == 0)
                        {
                            arr[fac] = arr[front]+1;
                            q.push(fac);
                        }
                    }
                }
            }
        }
        cout<<(arr[1])*(arr[1])*(arr[1])<<endl;           //print output which wiint be cube of minimum number of steps to reach 1
    }
    return 0;
}

