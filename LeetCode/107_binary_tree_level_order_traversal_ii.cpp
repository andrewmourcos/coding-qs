/* november 2019
runtime: 8ms [66th percentile]
memory: 13.7Mb 
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> res;
        
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        
        while (!nodeQueue.empty()){ // keep doing stuff if we have a lineup
            
            vector<int> currRow; // set up a vector to hold the current row
            int size= nodeQueue.size();
            
            for (int i=0; i<size; i++){ // iterate over the size of the queue
                TreeNode* currNode = nodeQueue.front();
                nodeQueue.pop();
                
                currRow.push_back(currNode->val);
                
                if (currNode->left)
                    nodeQueue.push(currNode->left);
                    
                if (currNode->right)
                    nodeQueue.push(currNode->right);
            }
            res.push_back(currRow);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};