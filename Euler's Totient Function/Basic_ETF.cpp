#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ETF(ll n){                       //O(sqrt(N)) for each query
                                    //Using the formula : phi(n) = n * ((P1-1)/P1) * ((P2-1)/P2) * ... * ((Pk-1)/Pk)
                                    //here P1,P2,P3...Pk are prime divisors of n
    ll res = n;                     //initially phi(n) = n, we'll multuply ((Pi-1)/Pi) with this in the loop
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){             //finding the prime divisors of n {'i's will be prime here}
            res /= i;               //dividing by i and multiplying by i-1
            res *= (i-1);           //basically doing this -> n * ((P1-1)/P1)
            while(n%i == 0)
                n /= i;             //dividing by the prime divisor(i) until n have any divisor of (i)
        }
    }
    if(n>1){                        //it means n is prime, it'll handle this corner case
        res /= n;
        res *= (n-1);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll tc, n;
    cin >> tc;
    while(tc--){
        cin >> n;
        cout << ETF(n) << endl;
    }
    return 0;
}
