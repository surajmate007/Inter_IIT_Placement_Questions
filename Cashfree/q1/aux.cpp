#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int solve(int *arr,int i,int k){
	if(k==0){
		return arr[i];
	}
	if(dp[i][k]!=-1){
		return dp[i][k];
	}
	int not_take=INT_MAX;
	int take=INT_MAX;
	if(i-1>=0){
		not_take=solve(arr,i-1,k);
	}
	if(i-2>=0){
		take=solve(arr,i-2,k-1);

	}
	return min(not_take,max(take,arr[i]));
}
int main(){
	int k;
	int n;
	cin>>n>>k;	
	memset(dp,-1,sizeof(dp));
	
	
	//memset(dp,-1,sizeof(dp));
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];

	}
	bool flag=true;
	int res=0;
	if(n%2==0){
		if(k>n/2){
			cout<<"Not possible"<<endl;

		}
		else{
			res=solve(arr,n-1,k-1);
		}
	}
	else{
		if(k>n/2+1){
			cout<<"Not possible"<<endl;
		}
		else{
			res=solve(arr,n-1,k-1);
		}
	}
	cout<<res<<endl;

	return 0;
}