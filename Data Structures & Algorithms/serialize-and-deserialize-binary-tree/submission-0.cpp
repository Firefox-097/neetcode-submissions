class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if (root == NULL) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }
    TreeNode* build(vector<string> &values , int &i){
        if(values[i] == "#"){
            i++;
            return NULL;
        }
        int value = stoi(values[i]);
        i++;
        TreeNode* root= new TreeNode(value);
        root->left=build(values,i);
        root->right=build(values,i);
        return root;

    }
    TreeNode* deserialize(string data) {
        vector<string> values;
        stringstream ss(data);
        string value;
        while(getline(ss,value,','))
        values.push_back(value);
        int i=0;
        return build(values,i);
    }
};
