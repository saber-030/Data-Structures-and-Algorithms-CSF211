#include<bits/stdc++.h>
using namespace std;


/*
We initialize two pointers left and right. 
Iterate right pointer from the start to the end of nums. 
In each position of the right pointer, 
we move left pointer as left as possible until the subarray 
sum is equal to or less than the required total - g.
*/


int main() {    
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t; 
    cin>> t;    
    while(t--){
		int n,x;        
		cin >> n;        
		vector<int> nums(n);
		for(int i=0;i<n;i++){
            int y; 
            cin >> y;
            nums[i]=y;
        }
        cin >> x;
        int tot_sum=0;
        for(int i=0;i<n;i++)
            tot_sum+=nums[i];
        int max_len=INT_MIN;
        int left=0,right=0;
        int req_sum=tot_sum-x;
        int cur_sum=0;
        for(;right<n;right++){
            while(cur_sum+nums[right]>req_sum && left<=right){
                cur_sum=cur_sum-nums[left];
                left++;            
            }
            cur_sum+=nums[right];
            if(cur_sum==req_sum){
                max_len=max(max_len,right-left+1);
            }
        }
        if(max_len==INT_MIN)
            cout<<0<<'\n';
        else         
        	cout<<(n-max_len)<<'\n';    
    }    
    return 0;
}