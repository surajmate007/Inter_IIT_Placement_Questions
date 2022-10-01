#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;

int32_t main(){
    ll n, k;
    cin>>n>>k;
    vector<ll> nums(n);
    for(auto& e: nums) cin>>e;

    vector<ll> ps(nums);
    for(ll i=1; i<n; i++) ps[i] += ps[i-1];

    vector<vector<ll>> dp(n, vector<ll>(k+1, 0));
    
    for(ll i=0; i<n; i++){
        dp[i][1] = ps[i] * ps[i];
    }

    for(ll p=2; p<=k; p++){
        for(ll e=p-1; e<n; e++){
            dp[e][p] = INT_MAX;
            for(ll s=e; s>0; s--){
                // s to e current partition
                // s-1, p-1 partitions required
                dp[e][p] = min(dp[e][p], dp[s-1][p-1] + (ps[e]-ps[s-1]) * (ps[e]-ps[s-1]));
            }
        }
    }

    cout<<dp[n-1][k]<<endl;

    return 0;
}
