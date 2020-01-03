/* november 2019
runtime: 8ms [not too good]
memory: 13.5Mb [great]
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
        
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res; // result
        
        if(!root){ // empty
            return vector<vector<int>> ();
        }
        
        deque<TreeNode*> nodeQueue; // queue for bfs
        nodeQueue.push_front(root);
        bool left2right = 1;
        
        while(!nodeQueue.empty()){ // waiting line
            int size = nodeQueue.size(); // get the width of the tree level
            
            vector<int> currentLevel;
            
            
            for(int i=0; i<size; i++){
                TreeNode* currNode;
                
                // getting the row left 2 right vs right 2 left
                if (left2right){
                    currNode = nodeQueue.front();
                    nodeQueue.pop_front();
                }
                else{
                    currNode = nodeQueue.back();
                    nodeQueue.pop_back();
                }
                
                currentLevel.push_back(currNode->val);
                
                if (left2right){
                    // add to queue for next iter
                    if (currNode->left){
                        nodeQueue.push_back(currNode->left);
                    }
                    if (currNode->right){
                        nodeQueue.push_back(currNode->right);
                    }  
                }
                else{
                    if (currNode->right){
                        nodeQueue.push_front(currNode->right);
                    } 
                    
                    if (currNode->left){
                        nodeQueue.push_front(currNode->left);
                    }
                }
                
            }
            
            // swap direction on next pass
            if (left2right)
                left2right=0;
            else
                left2right=1; 
            
            // add all to result
            res.push_back(currentLevel);
        }
        return res;
    }  
};