class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // creating a dictionary to store the current minimum cost required
        unordered_map<int,int> mp;
        mp[0]=0;
        // set to store the days value
        unordered_set<int> st(days.begin(),days.end());
        //iterating over all the days
        for(int i=1;i<366;i++){
            //if the day is not in set we could take the cost of the previous day
            if(st.count(i)==0){
               mp[i]=mp[i-1]; 
            }
            else{
                //else take the minimum of the three cases.
                // to tackle out of bound exception take max so that 0 is there.
                mp[i]=min({mp[i-1]+costs[0],mp[max(0,i-7)]+costs[1],mp[max(0,i-30)]+costs[2]});
                
                
            }
            
        }
        return mp[365];
        
        
    }
};
