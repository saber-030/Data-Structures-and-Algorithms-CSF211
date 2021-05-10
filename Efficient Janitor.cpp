#include<bits/stdc++.h>

using namespace std;

int main(){
	long long n;
	cin>>n;
	double x;
	vector<double> obj(n);
	for(long long i=0; i<n; i++){
		cin>>x;
		obj[i] = x;
	}
	
	sort(obj.begin(), obj.end(), greater<double>());
	long long i=0, j=n-1, ans = 0;
	while(i<j){
		if(obj[i] + obj[j] <= 3){
			i++;
			j--;
		}
		else{
			i++;
		}
		ans++;
	}
	if(i==j){
		cout<<ans+1<<endl;
	}
	else{
		cout<<ans<<endl;
	}

	return 0;
}