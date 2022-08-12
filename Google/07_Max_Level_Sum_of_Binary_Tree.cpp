// leetcode link : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/submissions/ 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0; int ans = 0; int maxsum = INT_MIN;
        
        while(!q.empty()){
            int n = q.size(); level++; int sum = 0;
            while(n--){
                TreeNode* nd = q.front(); q.pop();
                sum += nd->val;
                if(nd->left){
                    q.push(nd->left);
                }
                if(nd->right){
                    q.push(nd->right);
                }
            }
            if(sum > maxsum){
                maxsum = sum;
                ans = level;
            }
        }
        
        return ans;
    }
};
