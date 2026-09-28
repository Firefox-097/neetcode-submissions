class Solution {
public:
    Node* search(Node* node , unordered_map <Node* , Node*> &ans) {
        if(node==NULL ) return NULL;
        if(ans.find(node)!= ans.end()) return ans[node];
        Node * clone = new Node(node->val);
        ans[node]=clone;
        for(Node* neighbour : node->neighbors){
            clone->neighbors.push_back(search(neighbour , ans));
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL ) return NULL;
        unordered_map <Node* , Node*> ans;
        return search(node , ans);
    }
};
