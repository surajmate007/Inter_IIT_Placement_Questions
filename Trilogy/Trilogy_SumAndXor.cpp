#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;

int32_t main(){
    string A;
    ll B;
    cin >> A >> B;
    // 1 -> O and 1, 1 and 0, = 2 possible pairs of (X, Y) possible
    // 0 -> 0

    // Finding the subarray for operation where diff(count(0) - count(1)) is maximum
    // Assign 1 to '0' and -1 to '1' and find the subarray with maximum sum
    // Intuition - More number of 1's will give raise to more number of X and Y pairs

    ll pmin = 0, mdiff = 0, psum = 0, tones = 0;
    for(auto c: A){
        psum += (c == '0') ? 1 : -1;
        tones += (c == '1') ? 1 : 0;
        mdiff = max(mdiff, (psum - pmin));
        pmin = min(pmin, psum);
    }

    // Total number of 1's in the final inverted A, would be tones + mdiff(0's converted to 1)
    // Intuition for -2 => Two pairs of X and Y where (A, 0) and (0, A) should be substracted
    ll res = 1;
    tones += mdiff;
    const ll mod = 1e9 + 7;
    while(tones--){
        res = res * 2;
        res = res % mod;
    }
    cout<<(res-2)<<endl;

    return 0;
}
