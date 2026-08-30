class Codec {
public:
    int i=0;
    string serialize(TreeNode* root) {
       string ans="";
       if(root == NULL) return "#";
       return to_string(root->val)+","+serialize(root->left)+","+ serialize(root->right);
    }
    TreeNode* build(vector <string> &val, int &i){
        if(val[i]== "#") {
            i++;
            return NULL;
        }
        int ans=stoi(val[i]);
        i++;
        TreeNode* root= new TreeNode(ans);
        root->left =build(val , i);
        root->right =build(val , i);
        return root;
    }
    TreeNode* deserialize(string data) {
        vector <string> val;
        stringstream ss(data);
        string values;
        while(getline(ss,values,',')) val.push_back(values);
        return build(val , i);
    }
};
