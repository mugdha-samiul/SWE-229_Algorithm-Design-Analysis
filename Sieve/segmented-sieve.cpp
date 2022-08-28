#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX        10000000             //primes in range of 1-10^7 will be stored
bool allFlags[MAX];
vector <ll> primes;                     //primes are stored in here
void primeFinder(){                     //primes are generated in this func
    for(ll i = 3;i*i < MAX;i+=2){
        if(allFlags[i] == false){
            for(ll j = i*i;j < MAX;j+=(i+i)){
                allFlags[j] = true;
            }
        }
    }
    primes.push_back(2);                //primes vector saves all the primes in 10^7
    for(int i = 3;i < MAX;i+=2){
        if(allFlags[i]==false)primes.push_back(i);
    }
}
void segSieve(ll L, ll R){
    bool RangeFlag[R-L+1];                              //local flag array to store the primality of R-L+1 numbers, from L to R
    for(ll i = 0; i < R-L+1;i++)RangeFlag[i] = 0;       //initially all numbers are prime, composites will be marked later
    if(L == 1)RangeFlag[0] = 1;                         //1's primality is not tested, so it is flagged manually

    for(ll i = 0; primes[i]*primes[i] <= R; i++){       /*to check the primality between 50-100 we need the primes between 2 to sqrt(R) or 2-10(2,3,5,7) ,,, or primes between sqrt(100)
                                                        then we'll find the multiples of (2,3,5,7) between (50-100)
                                                        */
        ll curPrime = primes[i];
        ll composite = ((L+curPrime-1)/curPrime)*curPrime;  //L=50, curPrime = 7, ((50+7-1)/7)*7 = (56/7)*7 = 8*7 = 56,, so '56' is the first composite of 7 in the range 50-100
        if(composite == curPrime)composite += curPrime;     //if L=1, curPrime = 2, composite = 2, but 2 is prime
        for(;composite <= R;composite+=curPrime){           //now flag all the composites inside the range form L to R
            RangeFlag[composite-L] = 1;
        }
    }
    for(ll i = 0;i < R-L+1;i++){                            //printing all the primes between L-R
        if(RangeFlag[i]==0)
            cout << i+L << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    primeFinder();
    ll r, l;
    cin >> l >> r;
    segSieve(l,r);
    return 0;
}
