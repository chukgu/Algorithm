# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root : TreeNode) -> int:
        """ DFS 재귀 풀이
        if root is None:
            return 0
        else:
            left = 0
            right = 0
            if root.left is not None:
                left = self.maxDepth(root.left)

            if root.right is not None:
                right = self.maxDepth(root.right)

        return 1 + max(left,right)
        """
        if root is None:
            return 0
        q = collections.deque([root])
        depth = 0

        while q:
            depth+=1
            for i in range(len(q)):
                v = q.popleft()
                if v.left:
                    q.append(v.left)
                if v.right:
                    q.appned(v.right)
        return depth

if __name__ == "__main__":
    s = Solution()
    root = TreeNode(3,9,10)
    print(s.maxDepth(root = [3,9,20,None,None,15,7]))
    # root = TreeNode([1,None,2])
    # print(s.maxDepth(root))
    # root = TreeNode([])
    # print(s.maxDepth(root))
    # root = TreeNode([0])
    # print(s.maxDepth(root))