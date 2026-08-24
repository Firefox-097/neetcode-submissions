class Solution {
public:
    int ans;

    int maxPath(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        int left = max(0, maxPath(root->left));
        int right = max(0, maxPath(root->right));

        ans = max(ans, left + root->val + right);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root)
    {
        ans = INT_MIN;

        maxPath(root);

        return ans;
    }
};