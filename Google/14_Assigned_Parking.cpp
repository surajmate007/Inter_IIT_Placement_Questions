// problem link : https://leetcode.com/discuss/interview-question/2415742/AirBnb-or-Thapar-University-Question

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int getXdist(vector<int>& arr, int n){
    int lo = arr[0]; int hi = arr[n-1]; int ans = 1e9;
    
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        int lower=0, upper=0, total=0;
        
        for(int i=0; i<n; i++){
            if(i<n/2){
                lower += abs(arr[i]-(mid-(n/2-i)));
            }
            else{
                upper += abs(arr[i]-(mid+(i-n/2))); 
            }
        }
        
        ans = min(ans, upper+lower);
        
        if(upper > lower){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    
    return ans;
}

int getAns(vector<pair<int, int>>& arr, int n){
    vector<int> xaxis, yaxis;
    for(int i=0; i<n; i++){
        xaxis.push_back(arr[i].first);
        yaxis.push_back(arr[i].second);
    }
    
    sort(xaxis.begin(), xaxis.end());
    sort(yaxis.begin(), yaxis.end());
    
    int median = 0; int ydist = 0;
    if(n%2 == 1){
        median = yaxis[n/2];
    }
    else{
        median = (yaxis[n/2] + yaxis[(n/2)-1])/2;
    }
    
    for(int i=0; i<n; i++){
        ydist += abs(yaxis[i] - median);
    }
    
    int xdist = getXdist(xaxis, n);
    
    return xdist + ydist;
}

int main() {
    int n; cin>>n;
    vector<pair<int, int>> arr;
    for(int i=0; i<n; i++){
        int x, y; 
        cin>>x>>y;
        arr.push_back({x, y});
    }
    
    int ans = getAns(arr, n);
    
    cout<<ans<<endl;
    
    return 0;
};
