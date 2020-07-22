#include<bits/stdc++.h>
using namespace std;

#define MAX_N 1000004

string text, pattern;
int b[MAX_N];

void preprocess(){
    int n = pattern.size();
    b[0] = -1;
    int j = -1, i = 0;
    while( i < n ){
        while( j >= 0 && pattern[j] != pattern[i] ){
            j = b[j];
        }
        i++; j++;
        b[i] = j;
    }
}

int matching(){
    int i = 0;
    int j = 0;
    int cnt = 0;
    while( i < (int)text.size() ){
        while( j >= 0 && pattern[j] != text[i] ){
            j = b[j];
        }
        i++; j++;
        if( j == (int)pattern.size()){
            cnt++;
            j = b[j];
        }
    }
    return cnt;
}

int main(){
    int t;
    cin >> t;
    for( int Case = 1; Case <= t; Case++ ){
        cin >> text >> pattern;
        preprocess();
        int cnt = matching();
        cout << "Case " << Case << ": " << cnt << endl;
    }
}