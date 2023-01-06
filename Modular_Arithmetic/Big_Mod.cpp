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
ll bigMod(ll a, ll n, ll m){
    if(n < 1){
        return 1;
    }
    if(n%2 == 0){
        ll d = bigMod(a,n/2, m);
        return (d*d)%m;
    }
    else{
        return (a*bigMod(a,n-1,m))%m;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll a, n, m;
    cin >> a >> n >> m;
    cout << bigMod(a, n, m) << en;  //a^n(mod m)
    return 0;
}
