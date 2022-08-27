int mod=1e9+7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        //store them in pair in vector first efficiency then speed
        vector<pair<int,int>> res;
        
        for(int i=0;i<n;i++){
            res.push_back({efficiency[i],speed[i]});
        }
        //reverse sort according to the efficiency
        //we have reduce the dimension using the sorting
        //since the res is sorted we need to consider now the second part first will be always less than prev.
        sort(res.rbegin(),res.rend());
        //make a minheap  of sum elements
        
        priority_queue<int,vector<int>,greater<int>> pq;
        long ans=0;
        long sum=0;
        for(int i=0;i<n;i++){
              
            int e=res[i].first;
            int s=res[i].second;
            //push the speed in the minheap
            pq.push(s);
            sum+=s;
            //update the current sum
            if(pq.size()>k){
                //if size of minheap is more than k remove the minimum sum element from it.
                //reduce the sum by that
                sum-=pq.top();
                pq.pop();
                
            }
            // e will be minimum in this case.
            
            ans=max(ans,sum*e);
        }
        //return mod 
        ans=ans%mod;
        return ans;
    }
};