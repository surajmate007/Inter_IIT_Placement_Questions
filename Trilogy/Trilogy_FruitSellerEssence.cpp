#include <bits/stdc++.h>
using namespace std;

bool ok(vector<int>& B, int m, int C){
    vector<int> fruits(B);
    for(int i=0; i<fruits.size(); i++){
        if(fruits[i] >= m) fruits[i] = 1;
        else fruits[i] = -1;
    }

    vector<int> min_value(B.size());
    int psum = 0;
    for(int i=0; i<fruits.size(); i++){
        psum += fruits[i];
        if(i+1 >= C and psum > 0){
            return true;
        }
        if(i >= C and min_value[i-C] <= (psum-1)){
            return true;
        }
        // storing min value of psum till index i
        if(i > 0) min_value[i] = min(min_value[i-1], psum);
        else min_value[i] = psum;
    }

    return false;
}

int count_fruits(vector<int> B, int m){
    int cnt = 0;
    for(auto& e: B){
        if(e >= m) cnt++;
    }
    return cnt;
}

int solve(vector<int>& B, int C){
    int ans = -1;
    int l = *min_element(B.begin(), B.end()), r = *max_element(B.begin(), B.end());
    while(l <= r){
        int m = l + (r-l) / 2;
        if(ok(B, m, C)){
            ans = count_fruits(B, m);
            l = m + 1;
        }else{
            r = m - 1;
        }
    }   
    return ans;
}

int main(){
    int A, C;
    cin >> A >> C;
    vector<int> B(A);
    for(auto& e: B) cin>>e;
    cout<<solve(B, C)<<endl;
    return 0;
}
