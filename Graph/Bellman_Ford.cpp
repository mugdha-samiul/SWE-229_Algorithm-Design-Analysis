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
struct edge{
    int a, b, cost;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n, m, u, v, w;
    cin >> n >> m;
    vector <edge> all(m);
    for(int i = 0;i < m;i++){
        cin >> u >> v >> w;
        all[i].a = u;
        all[i].b = v;
        all[i].cost = w;
    }
    vector <ll> d(n+1, 1000000000);
    d[1] = 0;
    for(int i = 1; i <= n-1;i++){
        for(int j = 0;j < m;j++){
            if(d[all[j].b] > d[all[j].a] + all[j].cost)
                d[all[j].b] = d[all[j].a] + all[j].cost;
        }
    }
    ll flag = 1;
    for(int j = 0;j < m;j++){
        if(d[all[j].b] > d[all[j].a] + all[j].cost)
            flag = 01;
    }
    if(flag == 0)cout << "neg cycle detected\n";
    else{
        for(int i = 1;i <= n;i++)
            cout << d[i] << sp;
    }
    return 0;
}
/*
7 10
1 2 6
1 3 5
1 4 5
4 6 -1
3 2 -2
2 5 -1
3 5 1
6 7 3
5 7 3
4 3 -2
*/
