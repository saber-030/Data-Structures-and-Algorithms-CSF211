#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    string s;
    cin>>s;
    long long max=0, max_cnt=1;
    stack<int> sa;
    sa.push(-1);
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('){
            sa.push(i);
        }
        else{
            sa.pop();
            if(sa.size()!=0){
                if(i - sa.top() > max){
                    max = i - sa.top();
                    max_cnt = 1;
                }
                else{
                    if(i - sa.top() == max){
                        max_cnt++;
                    }
                }
            }
            else{
                sa.push(i);
            }
        }
    }
 
    cout<<max<<" "<<max_cnt<<endl;
 
 
    return 0;
}