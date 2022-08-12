class Solution {
public:
    
    bool getAns(vector<int>& arr, int n, int idx, vector<int>& visited){
        if(idx >= n or idx < 0){
            return false;
        }
        
        if(arr[idx] == 0){
            return true;
        }
        
        if(visited[idx] == 1){
            return false;
        }
        
        visited[idx] = 1;
        
        if(getAns(arr, n, idx+arr[idx], visited) == true){
            return true;
        }
        
        if(getAns(arr, n, idx-arr[idx], visited) == true){
            return true;
        }
        
        return false;
    }
    
    bool canReach(vector<int>& arr, int start){
        int n = arr.size();
        vector<int> visited(n, 0);
        return getAns(arr, n, start, visited);
    }
};
