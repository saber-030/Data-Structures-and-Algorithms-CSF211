#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, x, t;
    cin>>n;
    vector<int> A(n), B(n), C(n);
    unordered_map<int, long long> m;
    for(int i=0; i<n; i++){
        cin>>x;
        A[i] = x;
    }

    stack<long long> s;
    for(long long i=0; i<A.size(); i++){
        if(i==0){
            B[i]=-1;
            s.push(i);
            continue;
        }
        if(A[s.top()]>=A[i]){
            B[i]=s.top();
            s.push(i);
        }
        else{
            while(!s.empty() && A[s.top()]<A[i]){
                s.pop();
            }
            if(s.empty()){
                s.push(i);
                B[i]=-1;
            }
            else{
                B[i]=s.top();
                s.push(i);
            }
        }
    }

    stack<long long> s1;
    for(long long i=A.size()-1; i>=0; i--){
        if(i==A.size()-1){
            C[i]=A.size();
            s1.push(i);
            continue;
        }
        if(A[s1.top()]>A[i]){
            C[i]=s1.top();
            s1.push(i);
        }
        else{
            while(!s1.empty() && A[s1.top()]<=A[i]){
                s1.pop();
            }
            if(s1.empty()){
                s1.push(i);
                C[i]=A.size();
            }
            else{
                C[i]=s1.top();
                s1.push(i);
            }
        }
    }

    for(int i=0; i<n; i++){
        m[A[i]] += ((long long)(i - B[i]))*(C[i] - i);
    }

    cin>>t;
    while(t--){
        cin>>x;
        if(m.find(x) == m.end()){
            cout<<"0\n";
        }
        else{
            cout<<m[x]<<"\n";
        }
    }

    return 0;
}