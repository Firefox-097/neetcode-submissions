class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;
    string word;

    TrieNode() {
        for(int i = 0; i < 26; i++) {
            child[i] = NULL;
        }

        isEnd = false;
        word = "";
    }
};


class Solution {
public:

    void insert(TrieNode* root, string word) {
        TrieNode* curr = root;

        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';

            if(curr->child[index] == NULL)
                curr->child[index] = new TrieNode();

            curr = curr->child[index];
        }

        curr->isEnd = true;
        curr->word = word;
    }


    void dfs(vector<vector<char>>& board,
             int i,
             int j,
             TrieNode* curr,
             vector<string>& ans) {

        // Out of bounds
        if(i < 0 || i >= board.size() ||
           j < 0 || j >= board[0].size())
            return;

        // Already visited
        if(board[i][j] == '#')
            return;

        int index = board[i][j] - 'a';

        // Character doesn't exist in Trie
        if(curr->child[index] == NULL)
            return;

        curr = curr->child[index];

        // Found a complete word
        if(curr->isEnd) {
            ans.push_back(curr->word);
            curr->isEnd = false;
        }

        // Mark visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Four directions
        dfs(board, i + 1, j, curr, ans);
        dfs(board, i - 1, j, curr, ans);
        dfs(board, i, j + 1, curr, ans);
        dfs(board, i, j - 1, curr, ans);

        // Backtrack
        board[i][j] = temp;
    }


    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = new TrieNode();

        // Put all words into Trie
        for(string word : words) {
            insert(root, word);
        }

        vector<string> ans;

        // Start DFS from every board cell
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }
};