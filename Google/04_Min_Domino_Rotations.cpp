class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        unordered_map<int, int> mp;
        
        for(int i=0; i<tops.size(); i++){
            if(tops[i] != bottoms[i]){
                mp[tops[i]]++;
                mp[bottoms[i]]++;
            }
            else{
                mp[tops[i]]++;
            }
        }
        
        int val = 0;
        
        for(auto item : mp){
            if(item.second == n){
                val = item.first;
            }
        }
        if(val == 0){
            return -1;
        }

        int ans;
        int tp = 0; int bt = 0;
        
        for(int i=0; i<n; i++){
            if(tops[i] != val and bottoms[i] == val){
                tp++;
            }
            else if(tops[i] == val and bottoms[i] != val){
                bt++;
            }
        }
        
        ans = min(tp, bt);
        return ans;
    }
};
