// There are multiple approaches to soling this question. The crux of the problem lied in 
// Solving the question in O(n) time, and we would make use of a data structure(queue/priority_queue/deque/stack/vector(C++))

// The basic idea of the algorithm is as follows: 

// 1. Loop through the input array Arr and put on the front of the vector the currently available minimum;
// 2. Whenever there are enough elements in the remaining of the input to form k-size sequence, 
//    keep checking if the current element is less than the vector end; if yes, keep popping out the back of the vector;
// 3. Otherwise, check if the vector has alreay reached the size of k; if no, append it to the vector; if yes, ignore it.
// 4. Upon termination of the loop, the elements in the stack form the required sequence.

// NOTE : There are 2 vectors, one for maintaing the input elements and one for our result(exact subsequence required)
//Complexity: both time and space complexity is O(n)


// Solution-1 (Using Vectors)--> A simple implementation of the above logic using the most basic data structure, a vector
#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n;i++)             // Taking inputs
    {
        cin>>v[i];
    }
    int k;
    cin>>k;
    vector <int> res;                   // A vector of to store the result

    for (int i = 0; i < n; ++i) 
    {
        while (!res.empty() && res.back() > v[i] && res.size() - 1 + v.size() - i >= k) // Take care of this condition "res.size() - 1 + v.size() - i >= k"                                                  
        {                                                                               // This condition is used only when there are enough elements 
            res.pop_back();                                                             // in the remaining of the input Arr, to form k-size sequence
        }

        if (res.size() < k)             // If the size of the result hasn't reached 'k', push the incoming element onto our vector
        {
            res.push_back(v[i]);
        }
    }

    for(int i = 0; i<res.size();i++)    // Printing the output
    {
        cout<<res[i]<<" ";
    }

    return 0;
}

// Solution-2(Using deque) --> Using a better version of the queue, 
//Deque is a sequence container with the ability of expansion and contraction on both ends.
//It is similar to vectors but are more efficient for the insertion and deletion of elements.

#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n;i++)             // Taking inputs
    {
        cin>>v[i];
    }
    int k;
    cin>>k;

    deque<int> dq;
    for (int i = 0; i < v.size(); i++) 
    {
        while (dq.size() > 0 && v[i] < dq.back() && v.size() - i + dq.size() > k) 
        {
            dq.pop_back();
        }

        if (dq.size() < k) 
        {
            dq.push_back(v[i]);
        }
    }
    vector<int> res(k);                 // A vector of size = k, to store the result
    int idx = 0;
    while (!dq.empty()) {
        res[idx++] = dq.front();
        dq.pop_front();
    }
    
    for(int i = 0; i<res.size();i++)    // Printing the output
    {
        cout<<res[i]<<" ";
    }
    
    return 0;
}
