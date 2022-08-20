//DP
int solve(int ind, vector<int>&nums){
        if(ind>=nums.size()-1){
            return 0;
        } 
        int temp=INT_MAX;
        for(int i=1; i<=ind+nums[ind]; i++){
            temp = min(temp, 1 + solve(ind+i,nums));  
        }   
       return temp;
    }


//GREEDY
 int jump(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int left=0;
        int right=0;
        
        while(right<n-1){
            
            int maxReach=0;
            
            for(int i=left; i<=right; i++){
                maxReach=max(maxReach,i+nums[i]);
            }
            
            left=right+1;
            right=maxReach;
            ans++;
        }
        
        return ans;
        

