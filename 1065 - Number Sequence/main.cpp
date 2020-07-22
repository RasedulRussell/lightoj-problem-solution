#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_N 2

ll mod;
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
    for( int i = 0; i < 2; i++ ){
        for( int j = 0; j < 2; j++ ){
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
        ll a, b, n, m;
        scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
        mod = 1;
        for( int i = 0; i < m; i++ ){
            mod *= 10;
        }
        Matrix base;
        base.mat[0][0] = 0;
        base.mat[0][1] = 1;
        base.mat[1][0] = 1;
        base.mat[1][1] = 1;

        base = matrixExponent( base, n );

        printf("Case %d: %lld\n",Case, (base.mat[0][0]*a+base.mat[0][1]*b)%mod);
    }
}