class Solution {
public:

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int preStart, int preEnd,
                    int inStart, int inEnd) {

        // Nothing left to build
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        // First element of this preorder section = root
        int rootValue = preorder[preStart];

        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int index;

        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootValue) {
                index = i;
                break;
            }
        }

        // How many nodes are in the left subtree?
        int leftSize = index - inStart;

        // Build LEFT subtree
        root->left = build(preorder, inorder,
                           preStart + 1,
                           preStart + leftSize,
                           inStart,
                           index - 1);

        // Build RIGHT subtree
        root->right = build(preorder, inorder,
                            preStart + leftSize + 1,
                            preEnd,
                            index + 1,
                            inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return build(preorder, inorder,
                     0, preorder.size() - 1,
                     0, inorder.size() - 1);
    }
};