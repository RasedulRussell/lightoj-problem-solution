#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;
int main(){
    int n,q,k;
    cin >> n >> q >> k;
    ordered_set<int>s;
    ll arr[n+2];
    for( int i = 0; i < n; i++ ){
        ll a;
        cin >> a;
        arr[i+1] = a;
        s.insert(a);
    }
    while( q-- ){
        int t;
        cin >> t;
        if( t == 0 ){
            int a;
            ll b;
            cin >> a >> b;
            s.erase( s.find(arr[a]) );
            arr[a] = b;
            s.insert(b);
        }else{
            ll a,b,c,d;
            cin >> a >> b >> c >> d;
            a = max( a, c );
            b = min( b,d );
            int aa = s.order_of_key(a);
            int bb = s.order_of_key(b);
            int m = bb - aa;
            if( m >= k ){
                cout << "Propose\n";
            }else{
                cout << "Do not propose\n";
            }
        }
    }
}
