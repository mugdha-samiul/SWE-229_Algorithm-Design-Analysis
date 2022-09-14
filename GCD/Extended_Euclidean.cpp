#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcdExtended(ll a, ll b, ll *x, ll *y) {
   if(a == 0){
      *x = 0;
      *y = 1;
      return b;
   }
   ll x1, y1;
   ll gcd = gcdExtended(b%a, a, &x1, &y1);
   *x = y1 - (b/a) * x1;
   *y = x1;
   return gcd;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll x, y, a, b, d;
    cin >> a >> b;
    d = gcdExtended(a, b, &x, &y);
    cout << x << " " << y << " " << d << endl;
    return 0;
}
