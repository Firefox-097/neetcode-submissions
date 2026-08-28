/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* build(vector<int>& preorder,int preStart,int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& ans){
        if (preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode * root=new TreeNode(preorder[preStart]);
        int inRoot=ans[root->val];
        int numsLeft=inRoot - inStart;
        root->left= build(preorder , preStart +1, preStart+numsLeft+1,inorder, inStart, inRoot-1, ans);
        root->right= build(preorder , preStart +numsLeft+1, preEnd,inorder, inRoot+1, inEnd, ans);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int , int> ans;
        for(int i = 0; i < inorder.size(); i++)
    ans[inorder[i]] = i;
        return build(preorder , 0, preorder.size()-1,inorder, 0, inorder.size()-1, ans );
    }
};
