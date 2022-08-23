#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX        1000000

bool allFlags[MAX];
vector <ll> primes;

void primeFinder(){
    //it'll store all the primes from 1-10^8 in primes vector
    int curSizeOfPrimes = 0;
    for(int i = 2;i < MAX;i++){
        if(allFlags[i]==false){
            primes.push_back(i);   //it's pushing the primes in the vector
            curSizeOfPrimes++;  //updating the current size of vector
        }
        for(int j = 0;j < curSizeOfPrimes && primes[j]*i < MAX;j++){
                                                    /*this loop will iterate the whole primes array and mark the composite numbers*/
            allFlags[i*(primes[j])] = true;         //q=i*p, flagging the qs in this statement
            if(i%primes[j]==0)break;                /*  q=i*primes[j+1] will be skipped cause q has smaller prime factor than primes[i]
                                                        example : i=15... i*2=30, i*3=45, i*5 = 75 these 3 numbers are marked butt
                                                        i*7 = 105 is not marked in this loop cause it has smaller prime factor(3) than 7
                                                        q=105 will be marked when i=35 && p = 3 (35*3=105)
                                                        that's why the loop will break and no further numbers will be flagged
                                                    */
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
