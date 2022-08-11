class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        int n = s.length();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(s[i] != '-'){
                cnt++;
            }
        }
        
        int less = cnt%k;
        int i=0;
        while(less){
            if(s[i] != '-'){
                ans += toupper(s[i]);
                less--;
            }
            i++;
        }
        
        if(ans != ""){
            ans += "-";
        }
        
        cnt = 0;
        for(int j=i; j<n; j++){
            if(s[j] != '-'){
                ans += toupper(s[j]); cnt++;
            }
            if(cnt == k){
                cnt = 0;
                ans += "-";
            }
        }
        
        if(ans.back() == '-'){
            ans.pop_back();
        }
        
        return ans;
    }
};
