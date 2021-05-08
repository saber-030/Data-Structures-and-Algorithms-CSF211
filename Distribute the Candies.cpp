#include<bits/stdc++.h>
using namespace std;


//Helper function to count the value of R where R = number of candies you will give to your friend
long long helper(vector<long long>&v,long long val,long long n){
	long long sum=0;
    for(long long i=0;i<n;i++)
  		//If number of ith type of candies is <= p , it means we can't give that type of candy to friend
    	if((v[i]-val)<=0ll){
    		continue;
    	}
		//If number of ith type of candies is > p , it means we can give that type of candy to friend    	
    	else{
	    	sum = sum + v[i]-val;
    	}
    return sum;
 
}


//Using Binary Search to find value of p
void bs(vector<long long>&v, long long n,long long y){
	long long l=0,r=v[n-1];
	long long mid=(l+r)/2;
	long long ans=0;
	while(r>=l){ 
		mid=(l+r)/2;

//Try to notice relation between value of p and R.
//As value of p increases , value of R decreases.
//As value of p decreases , value of R increases.
//So we will use binary search to find value of p

		long long val = helper(v,mid,n);
//If value of R >= y , we try to increase the value of p and change its searching range accordingly . 
		if(val>=y){
			ans=mid;
			l=mid+1;
		}
//If value of R < y , we try to decrease the value of p and change its searching range accordingly .
		else{
			r=mid-1;
		}
			    
	}

//If with no value of p we can achieve R>=y
	if(helper(v,ans,n)<y){
		cout<<-1<<endl;
		return;
	}
//Print the answer in required format .
	cout<<ans<<" "<<helper(v,ans,n)<<endl;
}

//Function to distribute candies to c childrens
void distribute(vector<long long> &v,long long n, long long c){
	sort(v.begin(),v.end());

	long long j=0;
	long long cnt=0;
	long long i=0;

//Distributing the candies to the chilrens in O(n) after the array Arr has been sorted

	for(; i<c && j!=n; i++){
		// cout<<(v[j]-cnt)<<endl;
		cnt = cnt + (v[j]-cnt);
		j++;
		while(j!=n && v[j]==v[j-1]){
			j++;
		}
	}

	for(long long i=0; i<j; i++){
		v[i]=0;
	}

	for(; j<n; j++){
		v[j]-=cnt;
	}

//Printing the array Q which we get after distrubuting candies to children .

	for(auto i: v){
		cout<<i<<" ";
	}
	cout<<endl;
}

int main(){
	long long n;
	long long c;
	long long y;
	// freopen("Testcase0_Input.txt", "r", stdin); 
 //    freopen("Testcase0_Output.txt", "w", stdout);

//Taking input according to the Input fromat given in the question	
	cin>>n;
	cin>>c;
	cin>>y;
	vector<long long> v(n);
	for(long long i=0; i<n; i++){
		cin>>v[i];
	}
//Task1 - Distribute candies to C childrens.
	distribute(v,n,c);
//Task2 - Give atleast y candies to your friend .
	bs(v,n,y);
}


