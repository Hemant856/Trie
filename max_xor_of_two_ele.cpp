class TrieNode{
    public:
    int data;
    TrieNode** children;
    TrieNode(int bit){
        data = bit;
        children = new TrieNode*[2];
        children[0] = NULL;
        children[1] = NULL;
    }
};

class Trie{
    
    TrieNode* root;
    public:
    Trie(){
        root = new TrieNode(0);
    }
    void insert(TrieNode* root, int num){
        TrieNode* child;
       
        for(int i=31;i>=0;i--){
            int bit = ((1<<i)&num);
            if(bit>0)bit=1;
            if(root->children[bit]){
                root = root->children[bit];
            }
            else{
                child = new TrieNode(bit);
                root->children[bit] = child;
                root = child;
            }
        }
    }
    
    void insert(int num){
        insert(root, num);
    }
    
    int maxXor(TrieNode* root, int num){
        int ans = 0;
        TrieNode* child;
       
        for(int i=31;i>=0;i--){
            int bit = ((1<<i)&num);
            if(bit>0)bit=1;
            if(root->children[1-bit]){
                ans +=((1<<i));
                root = root->children[1-bit];
            }
            else{
                //child = new TrieNode(bit);
                child = root->children[bit];
                root = child;
            }
        }
        return ans;
    }
    int maxXor(int num){
       return maxXor(root, num);
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    // Write your code here. 
    Trie dummy;
    for(auto it : arr1){
        dummy.insert(it);
    }
    int ans = 0;
    for(auto it : arr2){
        int x = dummy.maxXor(it);
        ans = max(ans, x);
    }
    return ans;
}


/*
Sample Input 1:
1
7 7
6 6 0 6 8 5 6
1 7 1 7 8 0 2
Sample Output 1:
15

Sample Input 2:
1
3 3
25 10 2
8 5 3
Sample Output 2:
28

*/