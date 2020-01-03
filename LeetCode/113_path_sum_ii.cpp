/* november 2019
runtime: 20ms [45th percentile]
memory: 36.6Mb [18th]
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> path; 
        DFS2(root, sum, path, paths);
        return paths;
    }
    
    void DFS2(TreeNode* root, int sum, vector<int> path, vector<vector<int>> &paths){
        
        if (root==NULL)
            return;
        
        path.push_back(root->val);
        
        if (root->left == NULL && root->right == NULL){
            if (sum - root->val == 0){
                paths.push_back(path);
            }
            return;
        }
        
        DFS2(root->left, sum-root->val, path, paths);
        DFS2(root->right, sum-root->val, path, paths);
        
    }
    
    
    
    
    
    
    
    
    
    void DFS1(TreeNode* root, int sum, vector<int> path, vector<vector<int>> &paths){
        if ((root->left == NULL)&&(root->right == NULL)){
            if (sum - root->val == 0){
                path.push_back(root->val);
                paths.push_back(path);
            }
            return;
        }
        
        else{
            if (root->left != NULL){
                path.push_back(root->val);
                DFS1(root->left, sum+root->val, path, paths);
            }
            if (root->right != NULL){
                path.push_back(root->val);
                DFS1(root->right, sum+root->val, path, paths);
            }
        }
    }
    
    
    
    
    
    
    void DFS(TreeNode* root, int sum, vector<int> path, vector<vector<int>> paths){
        int newSum = sum - root->val;
        
        if (root->right != NULL && newSum >= 0){
            path.push_back(root->val);
            DFS(root->right, newSum, path, paths);
        }
        
        if (root->left != NULL && newSum>=0){
            path.push_back(root->val);
            DFS(root->left, newSum, path, paths);
        }
        
        if ((newSum == 0) && (root->left != NULL && root->right!= NULL)){
            paths.push_back(path);
        }
        
    }
};