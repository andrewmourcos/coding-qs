""" november 2019
runtime: 24ms [98th percentile]
memory: 13Mb
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return
        
        res = []
        nodeQueue = [root]
        
        while len(nodeQueue) > 0:
            row = []
            
            for i in range(len(nodeQueue)):
                currNode = nodeQueue.pop()
                row.append(currNode.val)
                if currNode.left is not None:
                    nodeQueue.insert(0, currNode.left)
                if currNode.right is not None:
                    nodeQueue.insert(0, currNode.right)
            
            res.append(row)
                    
        return res
        