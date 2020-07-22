#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10

struct trieNode{
    struct trieNode *childrean[MAX_N];
    bool isEndOfNumber;
};

struct trieNode *getNode(){
    struct trieNode *node = new trieNode;
    for( int i = 0; i < MAX_N; i++ ){
        node->childrean[i] = NULL;
    }
    node->isEndOfNumber = false;
    return node;
}

bool notEmpty( trieNode *root ){
    for( int i = 0; i < 10; i++ ){
        if( !root->childrean[i] ){
            return true;
        }
    }
    return false;
}

void insertNumber( struct trieNode *root, string number ){
    struct trieNode *tempRoot = root;
    for( int i = 0; i < (int)number.size(); i++ ){
        int v = number[i] - '0';
        if( !tempRoot->childrean[v] ){
            tempRoot->childrean[v] = getNode();
        }
        tempRoot = tempRoot->childrean[v];
    }
    tempRoot->isEndOfNumber = true;
}

bool check( trieNode *root ){
    if( !root ){
        return true;
    }
    if( root->isEndOfNumber ){
        for( int i = 0; i < MAX_N; i++ ){
            if( root->childrean[i] ){
                return false;
            }
        }
        return true;
    }
    bool res = true;
    for( int i = 0; i < 10; i++ ){
        if( root->childrean[i] && root->childrean[i]->isEndOfNumber == false ){
            res = res && check( root->childrean[i] );
        }
    }
    return res;
}

int main(){
    int t =-1;
    cin >> t;
    for( int Case = 1; Case <= t; Case++ ){
        struct trieNode *root = getNode();
        int n; cin >> n;
        for( int i = 0; i < n; i++ ){
            string number; cin >> number;
            insertNumber( root, number );
        }
        bool flag = check( root );
        if( flag ){
            cout << Case << ": YES\n";
        }else{
            cout << Case << ": NO\n";
        }
    }
}