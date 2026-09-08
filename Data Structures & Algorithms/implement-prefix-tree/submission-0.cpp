class TrieNode{
    public:
    TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    isEnd=false;
    }
};
class PrefixTree {
public:
    TrieNode *root= new TrieNode();
    PrefixTree() {
    }
    void insert(string word) {
        TrieNode*curr =root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->child[index]==NULL)curr->child[index]= new TrieNode();
            curr=curr->child[index];
        }
        curr->isEnd=true;
    }
    bool search(string word) {
        TrieNode*curr =root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->child[index]== NULL) return false;
            curr=curr->child[index];
        }
        return curr->isEnd;
    }
    bool startsWith(string prefix) {
        TrieNode*curr =root;
        for(int i=0;i<prefix.size();i++){
            int index=prefix[i]-'a';
            if(curr->child[index]== NULL) return false;
            curr=curr->child[index];
        }
        return true;
    }
};
