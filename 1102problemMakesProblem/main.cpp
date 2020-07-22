

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 2000003
ll MOD = 1000000007;

ll factorial[MAX_N];


void factorialGenerate(){
    factorial[0] = 1;
    for( int i = 1; i < MAX_N; i++ ){
        factorial[i] = factorial[i-1]*i;
        factorial[i] %= MOD;
    }
}

ll bigMod( ll base, ll pow ){
    ll ans = 1;
    while( pow ){
        if( pow & 1 ){
            ans = ans*base;
            ans %= MOD;
        }
        base = (base*base)%MOD;
        pow >>= 1;
    }
    return ans%MOD;
}


ll nCr( int n, int r ){
    return ( ((factorial[n]*bigMod( factorial[r], MOD-2 ))%MOD)*bigMod( factorial[n-r], MOD-2 ) )%MOD;
}

int main(){

    factorialGenerate();
    ////cout << factorial[8] << " " << inverse[3] << " " << inverse[5] << endl;
    ll n, r;
    int t = 0;
    cin >> t;
    for( int Case = 1; Case <= t; Case++ ){
        cin >> n >> r;
        n = n + (r-1);
        cout << "Case " << Case <<": " << nCr(n,r-1) << endl;
    }

}