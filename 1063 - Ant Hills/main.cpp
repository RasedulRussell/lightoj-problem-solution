#include<bits/stdc++.h>
using namespace std;
#define MAX_N 10003

vector<int>hil[MAX_N];
int visitTime[MAX_N];
int lowTime[MAX_N];
bool visit[MAX_N];
bool articulationPoint[MAX_N];
int dfsCounter;

void dfs( int u, int parent ){

    visit[u] = true;
    visitTime[u] = lowTime[u] = dfsCounter++;
    int children = 0;

    for( int i = 0; i < hil[u].size(); i++ ){
        int v = hil[u][i];
        if( v == parent )continue;
        if( visit[v] ){
            lowTime[u] = min( lowTime[u], visitTime[v] );
        }else{
            dfs( v, u );
            lowTime[u] = min( lowTime[u], lowTime[v] );
            if( visitTime[u] <= lowTime[v] && parent != -1 ){
                articulationPoint[u] = true;
            }
            children++;
        }
    }
    if( parent == -1 && children > 1 ){
        articulationPoint[u] = true;
    }
}

int articulationPointFinding( int n ){

    memset( visitTime, -1, sizeof visitTime );
    memset( lowTime, -1, sizeof lowTime );
    memset( visit, false, sizeof visit );
    memset( articulationPoint, false, sizeof articulationPoint );
    dfsCounter = 1;

    for( int i = 1; i <= n; i++ ){
        if( !visit[i] ){
            dfs( i, -1 );
        }
    }

    int cnt  = 0;
    for( int i = 1; i <= n; i++ ){
        if( articulationPoint[i] ){
            cnt++;
        }
    }
    for( int i = 0; i < MAX_N; i++ ){
        hil[i].clear();
    }
    return cnt;
}

int main(){
    int t;
    cin >> t;
    for( int Case = 1; Case <= t; Case++ ){
        int n, m;
        cin >> n >> m;
        for( int i = 0; i < m; i++ ){
            int u, v;
            cin >> u >> v;
            hil[u].push_back(v);
            hil[v].push_back(u);
        }
        cout << "Case " << Case << ": " << articulationPointFinding(n) << endl;
    }
}