class words {
public:
    words* alpha[26];
    bool isEnd;

    words() {
        for(int i = 0; i < 26; i++) {
            alpha[i] = NULL;
        }

        isEnd = false;
    }
};


class WordDictionary {
public:
    words* ans = new words();

    WordDictionary() {
    }

    void addWord(string word) {
        words* curr = ans;

        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';

            if(curr->alpha[index] == NULL)
                curr->alpha[index] = new words();

            curr = curr->alpha[index];
        }

        curr->isEnd = true;
    }

    bool searchHelper(words* curr, string word, int i) {

        // Entire word has been processed
        if(i == word.size())
            return curr->isEnd;

        // Normal character
        if(word[i] != '.') {

            int index = word[i] - 'a';

            if(curr->alpha[index] == NULL)
                return false;

            return searchHelper(curr->alpha[index], word, i + 1);
        }

        // '.': try every possible character
        for(int j = 0; j < 26; j++) {

            if(curr->alpha[j] != NULL) {

                if(searchHelper(curr->alpha[j], word, i + 1))
                    return true;
            }
        }

        return false;
    }

    bool search(string word) {
        return searchHelper(ans, word, 0);
    }
};