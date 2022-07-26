// Not exactly correct.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string last = "";

void getStrings(vector<vector<int>>& mat, vector<int>& arr, int i, int n, string ans, int latest){
    if(i == n){
        ans.pop_back();
        last += ans;
        last.push_back(',');
        return;
    }
    
    for(int j=0; j<mat[i].size(); j++){
        if(arr[mat[i][j]] > latest){
            getStrings(mat, arr, i+1, n, ans + to_string(arr[mat[i][j]]) + ">", arr[mat[i][j]]);
        }
    }
}

void getAns(vector<int>& arr, int n){
    pair<int, int> pr;
    vector<int> dp(n, 1);
    int maxlen = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
            maxlen = max(maxlen, dp[i]);
        }
    }
    
    vector<vector<int>> mat (maxlen, vector<int>());
    for(int i=0; i<n; i++){
        mat[dp[i]-1].push_back(i);
    }
    
    getStrings(mat, arr, 0, maxlen, "", -1e7);
}

int main() {
	int n; cin>>n;
	vector<int> arr(n);
	
	for(int i=0; i<n; i++){
	    cin>>arr[i];
	}
	
	getAns(arr, n);
	last.pop_back();
	
	cout<<last<<endl;
	
	return 0;
}

