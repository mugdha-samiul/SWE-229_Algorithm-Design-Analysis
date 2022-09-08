#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000001
vector <ll> PHI(MAX);
void PHI_generator(){                   //it'll generate all the primes for 1-MAX
                                        //we know, phi(n) = n * ((P1-1)/P1) * ((P2-1)/P2) * ... * ((Pk-1)/Pk)
    for(ll i = 1; i < MAX;i++)          //so initially marking PHI[i] = i,,,that means phi(n) = n
        PHI[i] = i;
    for(ll i = 2;i < MAX;i++){          //if we get PHI[i] = i that means its a prime. So we'll change the phi for all of its multiples (including i)
        if(PHI[i] == i){
            for(ll j = i;j < MAX;j+=i){ //formula phi(n) = n * ((P1-1)/P1) * ((P2-1)/P2) * ... * ((Pk-1)/Pk)
                PHI[j] /= i;            //here P1 = i, PHI[j] = phi(n)
                PHI[j] *= (i-1);        //so we are dividing by P1 and multiplying by (p1-1) with phi(n)
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    PHI_generator();
    ll tc, n;
    cin >> tc;
    while(tc--){
        cin >> n;
        cout << PHI[n] << endl;
    }
    return 0;
}
