#include<bits/stdc++.h>
using namespace std;
#define ll long long
unordered_map<int,int> mp;
bool find_factor(ll n){
	ll n1=n;
	while(n1%2==0){
		mp[2]++;
		n1=n1/2;
		//cout<<2<<" ";
	}
	for(ll i=3;i<=sqrt(n);i+=2){
		while(n1%i==0){
			mp[i]++;
			n1=n1/i;
			//cout<<i<<" ";
		}
	}

	if(n1>2){
		//cout<<n1<<" ";
		return false;
	}

	return true;
}
int main(){
	ll n;
	cin>>n;
	bool ans=find_factor(n);
	ll res=1;
	if(ans==true){
		for(auto x: mp){
			res*=(x.second+1);
		}
		cout<<res<<endl;
	}
	else{
		cout<<2<<endl;
	}

	return 0;
}