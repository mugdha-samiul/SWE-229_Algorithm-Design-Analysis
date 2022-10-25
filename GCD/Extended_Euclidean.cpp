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
    //there is a relation between the x and y of 2 consecutive equations(line 13+14), so we can find g = g(1) + (0)(0) as a form of g = ax + by
    //where x = 1, y = 0, a = g, b = 0 and this is the base case -> line 6 of this code
    //we'll use the relation of x,y and get the x,y of upper fuctions, and we'll get the solution for g = ax+by where g = gcd(a,b)
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
