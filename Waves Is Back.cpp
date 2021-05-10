#include <bits/stdc++.h>
#define int long long

using namespace std;

struct stall{
    int val, size;
    stall *left;
    stall *right;

    stall(){
        this-> val = 0;
        this->size = 0;
        this->left = NULL;
        this->right = NULL;
    }
};

void findSize(struct stall *root){
    if(!root) return;
    findSize(root->left);
    findSize(root->right);
    if(root->left)  root->size += root->left->size;
    if(root->right) root->size += root->right->size;
    root->size++;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        struct stall * stalls[n + 1];
        for(int i = 1; i <= n; i++) stalls[i] = new stall();

        for(int i = 1; i <= n; i++){
            int a,b,c;
            cin >> a >> b >> c;

            if(b != -1){
                stalls[a]->left = stalls[b];
            }

            if(c != -1){
                stalls[a]->right = stalls[c];
            }
        }

        stall *root = stalls[1];

        findSize(root);

        int res = INT_MAX;

        int idx = -1;

        for(int i = 1; i <= n; i++){
            int lSize = 0, rSize = 0, remaining = 0;

            if(stalls[i]->left){
                lSize = stalls[i]->left->size;
            }

            if(stalls[i]->right){
                rSize = stalls[i]->right->size;
            }

            remaining = n - stalls[i]->size;

            int ans = (lSize*(lSize - 1))/2 + (rSize*(rSize - 1))/2 + (remaining*(remaining - 1))/2 ;
            if(ans<res){
                idx=i;
                res=ans;
            }
        }
        cout<<idx<<'\n';
    }
    return 0;
}

