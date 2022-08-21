#include <algorithm>
#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int diff=INT_MAX;
    vector<pair<int,int>> ans;
    for(int i=1;i<n;i++){
        int x=nums[i]-nums[i-1];
        if(x < diff){
            ans.clear();
            diff=x;
            ans.push_back({nums[i-1],nums[i]});
        }
        else if(x==diff){
            ans.push_back({nums[i-1],nums[i]});
        }
    }
    
    for (auto it:ans){
        cout << it.first << " " << it.second << endl;
    }
    return;
}


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    
    solve(nums);
    return 0;
}
