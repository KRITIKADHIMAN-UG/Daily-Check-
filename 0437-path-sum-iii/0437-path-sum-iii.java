class Solution {

    public int pathSum(TreeNode root, int targetSum) {
        if (root == null)
            return 0;

        return countPaths(root, targetSum)
                + pathSum(root.left, targetSum)
                + pathSum(root.right, targetSum);
    }

    private int countPaths(TreeNode root, long targetSum) {
        if (root == null)
            return 0;

        int count = 0;

        if (root.val == targetSum)
            count++;

        count += countPaths(root.left, targetSum - root.val);
        count += countPaths(root.right, targetSum - root.val);

        return count;
    }
}