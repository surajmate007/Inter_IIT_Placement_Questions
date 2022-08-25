#include<bits/stdc++.h>	
using namespace std;
int main(){
	int n,k;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>k;
	long int ans=-1;
	long int sum=0;
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		mp[arr[i]]++;
		if(i>=k){
			mp[arr[i-k]]--;
			if (mp[arr[i-k]]==0){
				mp.erase(arr[i-k]);
			}
			sum-=arr[i-k];

		}
		if(i>=k-1 and mp.size()==k){
			ans=max(ans,sum);

		}
	}
	cout<<ans<<endl;



}