#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F          first
#define S          second
#define PB         push_back
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '
#define inf        LONG_LONG_MAX

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    ll Graph[n+1][n+1];
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= n;j++){
            Graph[i][j]=1000000000;
            if(i==j)Graph[i][j] = 0;
        }
    }
    for(int i = 0;i < m;i++){
        ll u, v, w;
        cin >> u >> v >> w;
        Graph[u][v] = w;
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(Graph[i][j] > Graph[i][k]+Graph[k][j])
                    Graph[i][j] = Graph[i][k]+Graph[k][j];
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout << Graph[i][j] << sp;
        }
        cout << en;
    }
    return 0;
}
/*
4 6
1 2 8
2 3 1
3 1 4
1 4 1
4 2 2
4 3 9
*/
