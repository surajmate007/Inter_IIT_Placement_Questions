int maxResult(vector<int>& nums) {
        int n=nums.size();
        int ans[n];
        priority_queue<pair<int,int>>pq;
        // ans[n-1]=nums[n-1];
        
        for(int i=n-1; i>=0; i--){
            
            while(pq.size() && pq.top().second > i+nums[i] ){
                pq.pop();
            }
            
            ans[i]=nums[i];
            
            if(pq.size()>0){
                ans[i] = ans[i]+pq.top().first;
            }
            else{
                ans[i]+=0;
            }
            
            pq.push({ans[i], i});
            
        }
        return ans[0];

}
        

