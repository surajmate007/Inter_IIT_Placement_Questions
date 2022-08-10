// Problem Link : https://leetcode.com/problems/last-stone-weight-ii/

class Solution {
public:
    
    int getAns(vector<int>& stones, int n, int idx, int sum1, int sum2, vector<vector<int>>& dp){
        if(idx >= n){
            return abs(sum1 - sum2);
        }
        
        if(dp[idx][sum1] != -1){
            return dp[idx][sum1];
        }
        
        int ans1 = getAns(stones, n, idx+1, sum1+stones[idx], sum2, dp);
        int ans2 = getAns(stones, n, idx+1, sum1, sum2+stones[idx], dp);
        
        return dp[idx][sum1] = min(ans1, ans2);
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        return getAns(stones, n, 0, 0, 0, dp);
    }
};
