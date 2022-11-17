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

vector < pair <ll,ll> > graph[10000];
vector <ll> dis(10000);

void dijkstra(ll source){
    priority_queue < pair<ll,ll>, vector< pair<ll,ll> >, greater<pair<ll,ll> > > pq;

    pq.push({0,source});
    dis[source] = 0;

    while(!pq.empty()){
        ll curN = pq.top().S;
        ll curC = pq.top().F;
        pq.pop();

        for(auto &a : graph[curN]){
            if(a.F+curC < dis[a.S]){
                dis[a.S] = a.F+curC;
                pq.push({dis[a.S], a.S});
                
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n, m, u, v, w, source;
    cin >> n >> m >> source;
    for(int i = 0;i < n;i++){
        graph[i].clear();
    }
    for(auto &a : dis)a=INT_MAX;
    for(int i = 0;i < m;i++){
        cin >> u >> v >> w;
        graph[u].PB({w,v});
    }
    dijkstra(source);
    for(int i = 1;i <= n;i++)cout << dis[i] << sp;
    cout << en;
    return 0;
}
/*
7
8
1
1 4 10
1 2 2
1 3 3
2 5 10
3 5 11
3 7 4
5 6 2
7 6 2
*/
