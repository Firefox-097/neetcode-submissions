class Solution {
public:

    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {

        if(node == NULL)
            return NULL;

        if(visited.find(node) != visited.end())
            return visited[node];

        Node* clone = new Node(node->val);

        visited[node] = clone;

        for(Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, visited));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {

        if(node == NULL)
            return NULL;

        unordered_map<Node*, Node*> visited;

        return dfs(node, visited);
    }
};