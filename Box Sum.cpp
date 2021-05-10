#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void helper(string & s, ll st, ll end, ll cur_box, unordered_map<ll, ll> & mid, unordered_map<ll, ll> & box){
	if(st == end) return;
	box[cur_box] += s[st];
	helper(s, st+2, mid[st+1]-1, cur_box-1, mid, box);
	helper(s, mid[st+1], end-1, cur_box+1, mid, box);
}
 
int main(){

	while(true){
        ll c;
        string s;
        cin>>c>>s;
        if(s == "exit") return 0;

        // mapping opening bracket to right subtree index
        unordered_map<ll, ll> mid;
        stack<ll> st;
        for(int i = 1; i<s.length(); i++){
            if(s[i] == '['){
                st.push(i);
            } else if(s[i] == ']'){
                st.pop();
            } else {
                if(!mid.count(st.top())){
                    // left subtree
                    mid[st.top()] = -1;
                } else {
                    // right subtree
                    mid[st.top()] = i;
                }
            }
        }
    
        unordered_map<ll, ll> box;
        helper(s, 0, s.length()-1, 0, mid, box);
        if(box.count(c)) cout<<box[c]<<endl;
        else cout<<"IMPOSSIBLE\n";
	}
 
	return 0;
}