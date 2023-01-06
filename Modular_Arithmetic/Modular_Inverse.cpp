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

int Extended_Euclid(int a,int b,int& x,int& y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d = Extended_Euclid(b,a%b,x1,y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return d;
}
int modInverse(int a, int m){
    int x,y;
    cout << Extended_Euclid(a,m,x,y) << en;
    //cout << x << sp << y << en;               //the values of x, y of ax+by=gcd(a,b)
    x %= m;
    if(x<m)x+=m;
    return x;                                   //x=a^-1(mod m)
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a, m;
    cin >> a >> m;
    cout << modInverse(a,m) << en;
    return 0;
}
