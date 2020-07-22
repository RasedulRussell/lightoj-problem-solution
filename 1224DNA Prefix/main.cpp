#include <bits/stdc++.h>
using namespace std;

map<char, int>character;

void INT(){
    character['A'] = 0;
    character['C'] = 1;
    character['G'] = 2;
    character['T'] = 3;
}

struct trieNode{
    struct trieNode *nextTrieNode[4];
    int visitTime ;
};

struct trieNode *getNode(){
    struct trieNode *node = new trieNode;
    for( int i = 0; i < 4; i++ ){
        node->nextTrieNode[i] = NULL;
    }
    node->visitTime = 0;
    return node;
}

void insertTrie( trieNode *root, string input ){
    for( int i = 0; i < input.size(); i++ ){
        int index = character[input[i]];
        if( !root->nextTrieNode[index] ){
            root->nextTrieNode[index] = getNode();
        }
        root->nextTrieNode[index]->visitTime++;
        root = root->nextTrieNode[index];
    }
}

int dfs( trieNode *root, int depth ){
    if( !root ){
        return 0;
    }
    int res = 0;
    for( int i = 0; i < 4; i++ ){
        res = max( res , max( root->visitTime*depth , dfs( root->nextTrieNode[i], depth+1 ) ) );
    }
    return res;
}

void removeNode( struct trieNode *root ){
    if( !root ){
        return ;
    }
    for( int i = 0; i < 4; i++ ){
        removeNode( root->nextTrieNode[i] );
        delete( root->nextTrieNode[i] );
    }
}

int main(){
    INT();
    int test;
    cin >> test;
    for( int i = 0; i < test; i++ ){
        int n;
        cin >> n;
        struct trieNode *root = getNode();
        for( int j = 0; j < n; j++ ){
            string s;
            cin >> s;
            insertTrie( root, s );
        }
        cout << "Case " << i+1 << ": " << dfs( root, 0 ) << endl;
        removeNode( root );
    }
}