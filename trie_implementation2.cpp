class TrieNode{
     public:
    char data;
    int preCount = 0;
    int wordCount = 0;
    TrieNode** children;
    bool isTerminal;
   
    TrieNode(char data){
        children = new TrieNode*[26];
        this->data = data;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
    
};



class Trie{
    TrieNode* root;
    public:

    Trie(){
        // Write your code here.
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root -> isTerminal = true;
            root->preCount++;
            root->wordCount++;
            return;
        }
        
        // Small Calculation
         root->preCount++;
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        
        // Recursive call
        insertWord(child, word.substr(1));
    }
    
    // For user
    void insert(string &word) {
        insertWord(root, word);
    }
    
    
     int countWordsEqualTo(TrieNode *root, string word)
    {
        // base condition
        if(word.size()==0){
            return root->wordCount;
        }
         
        //small calculation
        int index=word[0]-'a';
         TrieNode *child;
        if( root -> children[index]!=NULL)
        {
            child=root->children[index];
            return countWordsEqualTo(child,word.substr(1));
        }
        else
        {
            return 0;
        }    
        
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        return countWordsEqualTo(root, word);
    }

      int countWordsStartingWith(TrieNode *root, string word)
    {
        // base condition
        if(word.size()==0){
            return root->preCount;
        }
        //small calculation
         // cout<<word[0]<<" "<<root->preCount<<"\n";
        int index=word[0]-'a';
         TrieNode *child;
        if( root -> children[index]!=NULL)
        {
            child=root->children[index];
            return countWordsStartingWith(child,word.substr(1));
        }
        else
        {
           // cout<<root->data<<"xx";
            return 0;
        }    
        
    }
    
    int countWordsStartingWith(string &word){
        // Write your code here.
        return countWordsStartingWith(root, word);
    }

    void removeWord(TrieNode * root, string word) {
  // Base case
  if (word.size() == 0) {
    root -> isTerminal = false;
      root->wordCount--;
      root->preCount--;
    return;
  }
  // Small calculation
  TrieNode * child;
  int index = word[0] - 'a';
  if (root -> children[index] != NULL) {
    child = root -> children[index];
  } else {
    return;
  }
  removeWord(child, word.substr(1));
        root->preCount--;

}
    
    void erase(string &word){
        // Write your code here.
        removeWord(root, word);
    }
};
