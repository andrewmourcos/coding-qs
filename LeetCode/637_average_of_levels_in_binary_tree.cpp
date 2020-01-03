/* november 2019
runtime: 24ms [42 percentile]
memory: 21.5Mb [?]
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

#include <queue>

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL)
            return {};
        
        vector<double> res;
        
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(! nodeQueue.empty()){
            double row_sum = 0;
            
            double size = nodeQueue.size();
            
            for(int i=0; i<size; i++){
                TreeNode* currNode = nodeQueue.front();
                nodeQueue.pop();
                row_sum += currNode->val;
                
                if(currNode->left)
                    nodeQueue.push(currNode->left);
                
                if(currNode->right)
                    nodeQueue.push(currNode->right);
            }
            res.push_back(row_sum/size);
        }
        return res;
    }
};