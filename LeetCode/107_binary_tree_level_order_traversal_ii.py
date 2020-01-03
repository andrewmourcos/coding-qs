""" november 2019
runtime: 32ms [74th percentile]
memory: 12.7Mb [?]
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return
        
        
        nodeQueue = [root]
        res = []
        
        while len(nodeQueue) > 0:
            row = []
            
            for i in range(len(nodeQueue)):
                currNode = nodeQueue.pop()
                row.append(currNode.val)
                
                if currNode.left:
                    nodeQueue.insert(0, currNode.left)
                if currNode.right:
                    nodeQueue.insert(0, currNode.right)
                    
            res.append(row)
            
        
        return reversed(res)
            
            