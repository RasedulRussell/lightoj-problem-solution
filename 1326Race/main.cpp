#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 10056

ll ncr[1001][1001];
ll dp[1001];

ll combination( int n, int r ){
    if( n == 1 || r == 0 || n == r ){
        return ncr[n][r] = 1;
    }
    if( ncr[n][r] != -1 ){
        return ncr[n][r];
    }
    return ncr[n][r] = (combination( n-1, r )+combination( n-1, r-1 ))%MOD;
}

int maxTime;

ll fun( int n ){
    if( n == 0 ){
        return 1;
    }
    if( dp[n] != -1 ){
        return dp[n];
    }
    ll res = 0;
    for( int i = 1; i <= n; i++ ){
        res += (ncr[n][i]*fun( n-i ))%MOD;
        res = res%MOD;
    }
    return dp[n] = res;
}

int main(){
    int n, r;
    memset( ncr, -1, sizeof ncr );
    for( int i = 1; i <= 1000; i++ ){
        for( int j = 1; j <= i; j++ ){
            combination( i, j );
        }
    }
    ///cout << ncr[3][3] << endl;
    int t;
    cin >> t;
    int Case = 1;
    while( t-- ){
        int n;
        cin >> n;
        memset( dp, -1, sizeof dp );
        cout << "Case " << Case++ << ": " << fun( n ) << endl;
    }
}