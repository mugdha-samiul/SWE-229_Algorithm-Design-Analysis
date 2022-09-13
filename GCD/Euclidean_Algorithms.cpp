#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//O(Log min(x, y))
ll euclid(ll x, ll y){
   if(y==0) return x;
   x%=y;
   return euclid(y,x);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll x, y;
    cin >> x >> y;
    cout << euclid(x,y) << endl;
    return 0;
}
