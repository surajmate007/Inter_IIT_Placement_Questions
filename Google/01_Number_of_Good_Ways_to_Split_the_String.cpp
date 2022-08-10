// Problem Link : https://leetcode.com/problems/number-of-good-ways-to-split-a-string/submissions/

class Solution {
public:
    int numSplits(string s) {
        int ans = 0;
        unordered_map<char, int> mp1, mp2;
        int n = s.length(); 
        
        for(int i=0; i<n; i++){
            mp2[s[i]]++;
        }
        
        for(int i=0; i<n; i++){
            mp1[s[i]]++;
            if(mp2[s[i]] == 1){
                mp2.erase(s[i]);
            }
            else{
                mp2[s[i]]--;
            }
            
            if(mp1.size() == mp2.size()){
                ans++;
            }
        }
        
        return ans;
    }
};
