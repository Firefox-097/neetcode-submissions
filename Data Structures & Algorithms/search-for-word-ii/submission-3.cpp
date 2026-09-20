class TrieNode{
public:
    TrieNode *child[26];
    bool isEnd;
    string word;
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    isEnd=false;
    word="";
    }
};
class Solution {
public:
    void insert(TrieNode* root, string word){
        TrieNode*curr =root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->child[index]==NULL) curr->child[index]=new TrieNode();
            curr=curr->child[index];
        }
        curr->isEnd=true;
        curr->word=word;
    }
    void dfs(vector<vector<char>>& board,int i , int j ,TrieNode* curr, vector<string>& ans){
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size()) return ;
        if(board[i][j] == '#' ) return;
        int index = board[i][j]-'a';
        if(curr->child[index]== NULL ) return;
        curr=curr->child[index];
        if(curr->isEnd){
            ans.push_back(curr->word);
            curr->isEnd = false;
        }
        char temp = board[i][j];
        board[i][j]='#';
        dfs(board, i , j+1 ,curr, ans);
        dfs(board, i , j-1 ,curr, ans);
        dfs(board, i+1 , j ,curr, ans);
        dfs(board, i-1 , j ,curr, ans);
        board[i][j]=temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root= new TrieNode();
        for(int i=0 ; i<words.size();i++){
            string word=words[i];
            insert(root , word);
        }
        vector <string> ans;
        for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            dfs(board, i,j,root, ans);
        }   
        }
        return ans;
    }
};
