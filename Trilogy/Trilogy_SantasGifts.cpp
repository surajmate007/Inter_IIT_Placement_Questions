#include <bits/stdc++.h>
using ll = long long;
#define pb push_back

using namespace std;

ll go(vector<vector<ll>>& like, vector<vector<ll>>& dp, ll& visited, ll h, ll sh, ll p){
    int n = like.size();
    if(p == n){
        if(h == n || sh > 0) return 1;
        return 0;
    }
    ll& val = dp[p][visited];
    if(val != -1) return val;
    val = 0;
    for(int i=0; i<n; i++){
        if(!(visited&(1<<i))){
            visited ^= (1<<i);
            ll lh = 0, lsh = 0;
            if(like[p][i] == 3){
                lsh++;
            }else if(like[p][i] == 2){
                lh++;
            }
            val += go(like, dp, visited, h+lh, sh+lsh, p+1);
            visited ^= (1<<i);
        }
    }
    return val;
}

int32_t main(){
    ll n;
    cin>>n;
    vector<vector<ll>> like(n, vector<ll>(n));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cin>>like[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(1<<n, -1));
    ll visited = 0;
    ll res = go(like, dp, visited, 0, 0, 0);
    cout<<res<<endl;

    return 0;
}
