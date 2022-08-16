#include<bits/stdc++.h>

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



vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
    Trie dummy;
    int q = queries.size();
    vector<int> ans(q, -1);
    // {xi,{A[i],index}}
    vector<pair<int,pair<int, int>>> aqq(q);
    int i=0;
    for(auto it : queries){
        aqq[i]={it[1],{it[0], i}};
        i++;  
    }
    sort(arr.begin(),arr.end());
    sort(aqq.begin(),aqq.end());
    int j=0;
    i=0;
    int n = arr.size();
    while(i<q){
        int ai = aqq[i].first;
        while(j<n && arr[j]<=ai){
            dummy.insert(arr[j]);
            j++;
        }
        int temp = -1;
        if(j>0){
            temp = dummy.maxXor(aqq[i].second.first);
        }
        
        ans[aqq[i].second.second]=temp;
        i++;
    }
    return ans;
}


/*

Sample Input 1:
2
5 2
0 1 2 3 4
1 3
5 6
1 1
1
1 0  
Sample Output 1:
3 7
-1

Sample Input 2:
2
6 3
6 6 3 5 2 4
6 3
8 1
12 4 
5 2
0 0 0 0 0
1 0
1 1
Sample Output 2:
5 -1 15
1 1

*/