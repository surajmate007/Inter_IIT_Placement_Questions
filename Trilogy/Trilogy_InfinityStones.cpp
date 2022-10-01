#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;

int32_t main(){
    ll n;
    cin>>n;
    vector<ll> stones(n);
    for(auto& e: stones) cin>>e;

    sort(stones.rbegin(), stones.rend());
    ll res = 0;
    for(ll i = 0; i<n; i++){
        res = max(res, stones[i]*(i+1));
    }
    cout<<res<<endl;

    return 0;
}
