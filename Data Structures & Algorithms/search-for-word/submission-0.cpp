class Solution {
public:

    bool solve(vector<vector<char>>& board, string& word,
               int i, int j, int k) {

        // We found the complete word
        if(k == word.size())
            return true;

        // Out of bounds
        if(i < 0 || i >= board.size() ||
           j < 0 || j >= board[0].size())
            return false;

        // Current cell doesn't match
        if(board[i][j] != word[k])
            return false;

        // Mark this cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Try all 4 directions
        bool found =
            solve(board, word, i + 1, j, k + 1) ||
            solve(board, word, i - 1, j, k + 1) ||
            solve(board, word, i, j + 1, k + 1) ||
            solve(board, word, i, j - 1, k + 1);

        // Undo the visit
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {

                if(board[i][j] == word[0]) {

                    if(solve(board, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};