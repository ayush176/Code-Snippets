class Node{
    public:
        Node *child[26] = {NULL};
        bool flag = false;

        bool containsKey(char key){
            return child[key - 'a'] != NULL;
        }

        void insertKey(char key){
            child[key - 'a'] = new Node();
        }

        Node *getKey(char key){
            return child[key - 'a'];
        }

        void setEnd(){
            flag = true;
        }

        bool isEnd(){
            return flag;
        }
};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->insertKey(word[i]);
            }
            node = node->getKey(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->getKey(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->getKey(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
