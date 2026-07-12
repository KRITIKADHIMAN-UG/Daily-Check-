class Solution {
public:
    void traversal(TreeNode* root, vector<int>& ans,
                   int& prev, int& count, int& maxCount) {
        if (!root) return;

        traversal(root->left, ans, prev, count, maxCount);

        if (prev == root->val)
            count++;
        else {
            prev = root->val;
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            ans.clear();
            ans.push_back(root->val);
        }
        else if (count == maxCount) {
            ans.push_back(root->val);
        }

        traversal(root->right, ans, prev, count, maxCount);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ans;

        int prev = INT_MIN;
        int count = 0;
        int maxCount = 0;

        traversal(root, ans, prev, count, maxCount);

        return ans;
    }
};