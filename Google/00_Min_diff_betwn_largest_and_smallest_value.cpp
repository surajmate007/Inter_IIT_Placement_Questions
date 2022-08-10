// problem link : https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/


class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums.size() <= 4){
            return 0;
        }
        
        int a = abs(nums[0] - nums[n-3-1]);
        int b = abs(nums[1] - nums[n-3]);
        int c = abs(nums[2] - nums[n-2]);
        int d = abs(nums[3] - nums[n-1]);
        
        return min({a, b, c, d});
    }
};
