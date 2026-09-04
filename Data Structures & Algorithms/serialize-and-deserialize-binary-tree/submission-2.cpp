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

class Codec {
public:
    int i=0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if (root==NULL) return "#";
        return to_string(root->val)+","+serialize(root->left)+','+serialize(root->right);
    }
    TreeNode* build(vector<string> &val , int &i){
        if(val[i]=="#"){
            i++;
            return NULL;
        }
        int x=stoi(val[i]);
        i++;
        TreeNode* root = new TreeNode(x);
        root->left=build(val ,i);
        root->right=build(val ,i);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector <string> values;
        stringstream ss(data);
        string value;
        while(getline(ss,value,',')) values.push_back(value);
        return build(values ,i);
    }
};
