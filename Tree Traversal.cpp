#include<bits/stdc++.h>
using namespace std;

int post_index;

void pre_traversal(int *in_order, int *post_order, 
                        int start, int end, stack<int> &s, map<int, int> hm){

    if(start > end)
        return;
    
    int post_element = post_order[post_index--];
    int in_index = hm[post_element];                // finding index of post_element in inorder[] 

    /* As in preorder traversal the sequence of printing elements is:
        1) Root element
        2) Left subtree
        3) Right subtree
        We will push elements in reverse order so that first root element is printed 
        and then left and right subtree elements.
    */

    // First traverse right subtree and push elements in stack
    pre_traversal(in_order, post_order, (in_index + 1), end, s, hm);

    // Now traverse left subtree and push elements in stack
    pre_traversal(in_order, post_order, start, (in_index - 1), s, hm);

    // push current element in stack
    s.push(post_element);
}

int main(){
    int N;
    cin >> N;

    stack<int> s;
    int *in_order = new int[N];
    int *post_order = new int[N];
    int *stack = new int[N];

    post_index = N - 1;
    if(N && (!in_order || !post_order || !stack))
        exit(1);
    
    for(int i = 0; i < N; i++)
        cin >> in_order[i];
    for(int i= 0; i < N; i++)
        cin >> post_order[i];
    
    // Initializing hash map with elements' indices 
    map<int,int>hm;
    for(int i = 0; i < N ; i++)
        hm[in_order[i]] = i;

    pre_traversal(in_order, post_order, 0, (N - 1), s, hm);
    
    // Pop the elements
    while(s.size()){
        cout << s.top() << " ";
        s.pop();
    }

    delete in_order;
    delete post_order;
    return 0;    
}