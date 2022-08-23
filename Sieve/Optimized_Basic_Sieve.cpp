#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX        10000

bool allFlags[MAX];
vector <ll> primes;

void primeFinder(){
    for(ll i = 3;i*i < MAX;i+=2){      //we'll only work with odd numbers, i <= sqrt(MAX) will be enough to flag all the composites
        if(allFlags[i] == false){       //if prime then mark all of its multiples
            for(ll j = i*i;j < MAX;j+=(i+i)){       //j=i*i will skip some of the prime marking from overlapping, j+=i will be even we only work with odd in this function, so we'll use j+=(i+i)
                allFlags[j] = true;
            }
        }
    }
    primes.push_back(2);                //the only even prime is 2
    for(int i = 3;i < MAX;i+=2){        //all the odd numbers will be checked if it's a prime or not
        if(allFlags[i]==false)primes.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    primeFinder();
    for(auto &a : primes){
        cout << a << "\n";
    }
    return 0;
}
