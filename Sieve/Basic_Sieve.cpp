#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX        1000000

bool allFlags[MAX];
vector <ll> primes;

void primeFinder(){
    for(ll i = 2;i < MAX;i++){
        if(allFlags[i] == false){       //if prime then mark all of its multiples
            primes.push_back(i);
            for(ll j = i+i;j < MAX;j+=i){
                allFlags[j] = true;
            }
        }
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
