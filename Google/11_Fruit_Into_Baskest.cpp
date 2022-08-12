// using sliding window:

class Solution {
public:
    int totalFruit(vector<int>& a) {
        int n = a.size();
        unordered_map<int, int> mp;

        int i=0; int j=0;
        int cnt = 0; int ans = 0;
        
        while(i<n and j<n){
            if(mp.find(a[j]) == mp.end()){
                mp[a[j]] = 1; cnt++;
            }
            else{
                mp[a[j]]++;
            }
            
            j++;
            
            if(cnt <= 2){
                ans = max(ans, j-i);
            }
            else{
                while(cnt > 2){
                    if(mp[a[i]] == 1){
                        mp.erase(a[i]); cnt--;
                    }
                    else{
                        mp[a[i]]--;
                    }
                    i++;
                }
                ans = max(ans, j-i);
            }
        }
        
        return ans;
    }
};
