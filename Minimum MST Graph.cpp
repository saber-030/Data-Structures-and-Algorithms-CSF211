#include <bits/stdc++.h>

#define ll long long

using namespace std;

long long n,m,s;
int t;

int main()
{
   scanf("%d",&t);

  while (t--)
  {
   scanf("%lld%lld%lld",&n,&m,&s);

   long long last=max(1ll,m-((n-2)*(n-1))/2); //number of edges from the last node
   long long pre=min(m-1,((n-2)*(n-1))/2); // total number of edges from all nodes, except the last node
   long long val=s-n+2; //value of edges from the last node
   long long ans=last*val+pre; // current answer
   if (last<=float(n-1)/2.0 || n==2) printf("%lld\n",ans); else //the best answer: all nodes has value 1 and last has val
    {
      long long k=(val-1)/(n-1); //added value to all nodes from 2 to n-1
      ans-=k*(last*(n-2)-pre); //new answer
      val-=(n-2)*k; //current vlaue in the last node
      if (val-k-1>1)
      {
      long long rem=val-k-2;//amount which can be decreased from the last node
      long long am=pre-((n-rem-1)*(n-rem-2))/2;
      if (am<=rem*last) ans-=rem*last-am;//new answer, in case we will decrease value in the last node again
      }
      printf("%lld\n",ans);
     }
    }
  return 0;
}