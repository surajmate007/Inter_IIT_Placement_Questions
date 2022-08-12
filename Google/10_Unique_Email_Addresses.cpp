class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set <string > stt;
        for(auto email : emails){
            string local = ""; string domain = "";
            bool in_local = true; 
            bool before_plus = true;
            for(auto it : email){
                if(it == '@'){
                    in_local = false;
                    continue;
                }
                if(in_local){
                    if(it == '+')before_plus = false;
                    else if(it != '.'){
                        if(before_plus) local += it;        
                    }
                  
                }else if(in_local == false){
                    domain +=it;
                }
            }
            
            
            string final_email = local + '@' + domain ;
            stt.insert(final_email);
        }
        return stt.size();
    }
};
