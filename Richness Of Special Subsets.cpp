#include<bits/stdc++.h>

using namespace std;


 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ans=0;
class Pair{
    public:
    int sum;
    bool isbst;
    int maxLeft;
    int minRight;

    Pair(){
        sum=0;
        isbst=true;
        maxLeft=INT_MIN;
        minRight=INT_MAX;
    }
};

Pair max_sum(TreeNode*root){
    Pair p;
    if(!root){
        return p;
    }
    Pair left=max_sum(root->left);
    Pair right=max_sum(root->right);


    if(left.isbst and right.isbst){
        if(left.maxLeft<root->val and root->val<right.minRight){
            p.sum+=left.sum+right.sum+root->val;
            ans=max(p.sum,ans);
            p.maxLeft=max(root->val,right.maxLeft);
            p.minRight=min(root->val,left.minRight);
            p.isbst=true;
            return p;
        }
    }
    p=left.sum>right.sum?left:right;
    p.isbst=false;
    return p;
}
int maxPower(TreeNode* root){

    if(!root) return 0;
    max_sum(root);
    int answer=ans;
    ans=0;
    return answer;
}

TreeNode* generator(vector<int> level){
    int currLevel = 0;
    int n = level.size();
    int i = 0, expectedNumbers = 2;

    vector<TreeNode*> prevLevelPointers;
    TreeNode* root = new TreeNode(level[0]);
    i++;
    prevLevelPointers.push_back(root);
    if(level[0] == -9999999)    return NULL;

    while(i < n){
        expectedNumbers = prevLevelPointers.size()*2;
        vector<TreeNode*> currLevelPointers;
        int plIndex = 0;
        for(int j=0; j<expectedNumbers; j++){
            int a = level[i+j];
            if(j%2 == 0){
                if(a == -9999999){
                    prevLevelPointers[plIndex]->left = NULL;

                }
                else{
                    TreeNode* newNode = new TreeNode(a);
                    prevLevelPointers[plIndex]->left = newNode;
                    currLevelPointers.push_back(newNode);
                }
            }
            else{
                if(a == -9999999){
                    prevLevelPointers[plIndex]->right = NULL;
                }
                else{
                    TreeNode* newNode = new TreeNode(a);
                    prevLevelPointers[plIndex]->right = newNode;
                    currLevelPointers.push_back(newNode);
                }
                plIndex++;
            }
        }
        prevLevelPointers = currLevelPointers;
        currLevelPointers.clear();
        i+=expectedNumbers;
    }
    return root;
}

void inorder(TreeNode* root){
    if(!root)    return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(){
    vector<int> level;
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int k;
        cin>>k;
        level.push_back(k);
    }

    if(level.size() == 0){    
        cout<<0; 
        return 0;
    }

    TreeNode* root = generator(level);
    cout<<maxPower(root);
    return 0;
}