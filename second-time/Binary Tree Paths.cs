/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public IList<string> BinaryTreePaths(TreeNode root) {
        List<string> result = new List<string>();
        if(root == null)
            return result;
        List<int> path = new List<int>();
        DFS(result, root, path);
        return result;
    }
    
    public void DFS(List<string> res, TreeNode cur, List<int> path){
        path.Add(cur.val);
        if (cur.left == null && cur.right == null)
        {
            StringBuilder sb = new StringBuilder();
            foreach (int n in path)
            {
                sb.Append(n.ToString() + "->");
            }
            sb.Remove(sb.Length - 2, 2);
            res.Add(sb.ToString());
            return;
        }
        if (cur.left != null)
        {
            DFS(res, cur.left, path);
            path.RemoveAt(path.Count() - 1);
        }
        if (cur.right != null)
        {
            DFS(res, cur.right, path);
            path.RemoveAt(path.Count() - 1);
        }
        
    }
}