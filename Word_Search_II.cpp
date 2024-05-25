struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Solution {
private:
    TrieNode* getNode() {
        return new TrieNode();
    }

    void insert(TrieNode* root, const string& key) {
        TrieNode* node = root;
        for (char ch : key) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = getNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    void dfs(vector<vector<int>>& visited, TrieNode* node, string& currentWord, set<string>& result, int i, int j, vector<vector<char>>& board) {
        if (node->isEndOfWord) {
            result.insert(currentWord);
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] == 1 || node->children.find(board[i][j]) == node->children.end()) {
            return;
        }

        visited[i][j] = 1;
        char ch = board[i][j];
        currentWord.push_back(ch);

        TrieNode* nextNode = node->children[ch];
        if(i<board.size()-1)
        dfs(visited, nextNode, currentWord, result, i + 1, j, board);
        if(i>0)
        dfs(visited, nextNode, currentWord, result, i - 1, j, board);
        if(j<board[0].size()-1)
        dfs(visited, nextNode, currentWord, result, i, j + 1, board);
        if(j>0)
        dfs(visited, nextNode, currentWord, result, i, j - 1, board);

        currentWord.pop_back();
        visited[i][j] = 0;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = getNode();
        for (const string& word : words) {
            insert(root, word);
        }

        set<string> result;
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        string currentWord;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(visited, root, currentWord, result, i, j, board);
            }
        }

        return vector<string>(result.begin(), result.end());
    }
};