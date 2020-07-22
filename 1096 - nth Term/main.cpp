#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_N 4
#define  mod 10007

struct Matrix{
    ll mat[MAX_N][MAX_N];
};

Matrix matrixMultiple( Matrix a, Matrix b ){
    Matrix ans;
    int k;
    for( int i = 0; i < MAX_N; i++ ){
        for( int j = 0; j < MAX_N; j++ ){
            for( ans.mat[i][j] = k = 0; k < MAX_N; k++ ){
                ans.mat[i][j] += ( a.mat[i][k]*b.mat[k][j] )%mod;
                ans.mat[i][j] %= mod;
            }
        }
    }
    return ans;
}

Matrix matrixExponent( Matrix base, ll n ){
    Matrix ans;
    for( int i = 0; i < MAX_N; i++ ){
        for( int j = 0; j < MAX_N; j++ ){
            ans.mat[i][j] = (i==j);
        }
    }
    while( n ){
        if( n & 1 ){
            ans = matrixMultiple( ans, base );
        }
        base = matrixMultiple( base, base );
        n >>= 1;
    }
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    for( int Case = 1; Case <= t; Case++ ){
        ll n;
        int a, b, c;
        scanf("%lld %d%d%d",&n,&a,&b,&c);

        Matrix base;
        base.mat[0][0] = 0;
        base.mat[0][1] = 1;
        base.mat[0][2] = 0;
        base.mat[0][3] = 0;

        base.mat[1][0] = 0;
        base.mat[1][1] = 0;
        base.mat[1][2] = 1;
        base.mat[1][3] = 0;

        base.mat[2][0] = b;
        base.mat[2][1] = 0;
        base.mat[2][2] = a;
        base.mat[2][3] = 1;

        base.mat[3][0] = 0;
        base.mat[3][1] = 0;
        base.mat[3][2] = 0;
        base.mat[3][3] = 1;

        if( n >= 3 ){
            base = matrixExponent( base, n-1 );
        }
        ll res = (((base.mat[0][2]%mod+base.mat[0][3]%mod)%mod)*c)%mod;

        printf("Case %d: %lld\n",Case, res);
    }
}