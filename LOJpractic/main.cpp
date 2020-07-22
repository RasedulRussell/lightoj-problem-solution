#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-6

#define MOD 1000000007
#define base 3

ll bigMod( ll n )
{
    ll ans = 1;
    ll bs = base;
    while( n > 0 ){
        if( n & 1 ){
            ans *= bs;
            ans %= MOD;
        }
        bs *= bs;
        bs %= MOD;
        n >>= 1;
    }
    return ans%MOD;
}

int main()
{
    string inputString;
    while( cin >> inputString ){
        string temp = inputString;
        reverse( temp.begin(), temp.end() );
        map<char, int>mp;
        for( int i = 0; i < 26; i++ ){
            mp['a'+i] = i+1;
        }
        ll hashValue = 0;
        for( int i = 0; i < inputString.size(); i++ ){
            hashValue += mp[inputString[i]]*bigMod( i );
            hashValue %= MOD;
        }
        ll reverseHashValue = 0;
        for( int i = 0; i < temp.size(); i++ ){
            reverseHashValue += mp[temp[i]]*bigMod(i);
            reverseHashValue %= MOD;
        }
        if( hashValue == reverseHashValue ){
            cout << inputString.size() << endl;
        }else{
            int cnt = 0;
            ///cout << hashValue << " age " << reverseHashValue << endl;
            for( int i = 0, j = inputString.size()-1; i < inputString.size(); i++, j-- ){
                ll temp1 = mp[inputString[i]]*bigMod(i);
                ll temp2 = mp[temp[j]]*bigMod( j );
                temp1 %= MOD;
                temp2 %= MOD;
                hashValue -= temp2;
                reverseHashValue-=temp1;
                hashValue = (hashValue+MOD)%MOD;
                reverseHashValue = (reverseHashValue+MOD)%MOD;
                cnt++;
                cout << hashValue << " " << reverseHashValue << endl;
                if( hashValue == reverseHashValue ){
                    cout << inputString.size()+cnt << endl;
                    break;
                }
            }
        }
    }
}
