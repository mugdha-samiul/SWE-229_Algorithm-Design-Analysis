#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y, d;
ll gcdExtended(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    d = gcdExtended(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll a, b;
    cin >> a >> b;
    d = gcdExtended(a, b, x, y);
    cout << x << " " << y << " " << d << endl;
    return 0;
}
