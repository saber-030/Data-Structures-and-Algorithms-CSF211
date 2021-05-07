#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int> a, int k){
    if(a.size() > 1){
        vector<int> b;
        vector<int> c;

        int pivot_element = (k%a.size());

        cout<<a[pivot_element]<<" ";


        for(int i = 0; i < a.size(); i++){
            if(i != pivot_element){
                if(a[i] < a[pivot_element]){
                    b.push_back(a[i]);
                }
                else{
                    c.push_back(a[i]);
                }
                
            }
        }

        quickSort(b, k);
        quickSort(c, k);
    }
}

int main(){  
        int n,k;
        cin>>n>>k;

        vector<int> a;
        
        for(int i = 0; i < n; i++){
            int l;
            cin>>l;
            a.push_back(l);
        }

        quickSort(a, k);
}