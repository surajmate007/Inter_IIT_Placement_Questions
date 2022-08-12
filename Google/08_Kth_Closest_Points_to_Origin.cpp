// We are using simple brute force approach where we are first calculating the distances of the points from the origin and then sorting the dist array
// and then chosing the first k points from the array.

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<pair<double, vector<int>>> dist;
        for(int i=0; i<n; i++){
            int x = points[i][0]; int y = points[i][1];
            double d = sqrt(x*x + y*y);
            dist.push_back({d, {x, y}});
        }
        
        sort(dist.begin(), dist.end());
        
        vector<vector<int>> ans;
        for(int i=0; i<k; i++){
            ans.push_back(dist[i].second);
        }
        
        return ans;
    }
};
