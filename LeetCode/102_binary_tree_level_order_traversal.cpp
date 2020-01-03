/* november 2019
runtime: 8ms [58th percentile]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) // make sure it's not empty
            return vector<vector<int>> ();
        
        queue<TreeNode*> nodeQueue; // set up queue for bfs
        nodeQueue.push(root);
        
        vector<vector<int>> res; // vector to hold our result
        
        while(!nodeQueue.empty()){ // do stuff while we still have a lineup
            
            vector<int> currentRow; // vector to hold each row
            int size = nodeQueue.size(); // number of nodes in the row
            
            for (int i=0; i<size; i++){ // iterate through the row
                TreeNode* currNode = nodeQueue.front();
                nodeQueue.pop();
                // appending to the list
                currentRow.push_back(currNode->val);   
                
                // updating the queue
                if (currNode->left){
                    nodeQueue.push(currNode->left);
                }
                if (currNode->right){
                    nodeQueue.push(currNode->right);
                }             
            }
            res.push_back(currentRow);
        }
        return res;
    }
};